#include "probabilities.hpp"

// TODO:
//  Replace i and j in forloop for row and col

// Variables
std::array<GridItem, totalItems> itemsLocal; 
std::discrete_distribution<> dist;

// Initiate Discrete Distribution
void createDistribution() {
    std::array<uint32_t, totalItems> probabilities;
    for(size_t i=0; i<totalItems; ++i) {
        probabilities.at(i) = itemsLocal.at(i).getProbability();
    }
    dist =  std::discrete_distribution<>(probabilities.begin(), probabilities.end());
}

// Random number generator
std::random_device rd;
std::mt19937 gen(rd());

// Get Random
GridItem getRandom() {
    // Select random index
    uint32_t selectedIdx = dist(gen);
    return itemsLocal.at(selectedIdx);
}

// Calculate the weights
void calculateProbabilities(std::array<GridItem, totalItems>& items){
    std::array<uint32_t, totalItems> invertedPayouts;

    // Calculate the inverse
    for(size_t i=0; i<totalItems; ++i) {
        uint32_t totalInvertedPayout = 0;
        for(const auto& [threshold, payout] : allPayouts.at(items.at(i).getID())) {
            totalInvertedPayout += 10000 / payout;              // Invert each payout
        }
        invertedPayouts.at(i) = totalInvertedPayout;
    }

    // Sum of the inverted payouts
    uint32_t totalWeight = std::accumulate(invertedPayouts.begin(), invertedPayouts.end(), 0);

    // Normalize weights
    std::array<uint32_t, totalItems> weights;
    for(size_t i=0; i<totalItems; ++i){
        uint32_t weight = (invertedPayouts.at(i) * 100) / totalWeight;  // Convert to percentage
        weights.at(i) = (weight == 0 ? 1 : weight);                     // Probability can't be 0
    }

    // Update item's probability
    for(auto& item : items) {
        item.setProbability(weights.at(item.getID()));
    }

    // Store locally item's address
    itemsLocal = items;
}

uint32_t findMinPayout(const std::map<uint32_t, uint32_t>& payouts, uint32_t count) {
    uint32_t minDif = std::numeric_limits<uint32_t>::max(); // Start with the largest int value
    uint32_t correspondingPayout = 0;

    for(const auto& [threshold, payout] : payouts) {
        if(count >= threshold) {
            uint32_t dif = count - threshold;
            if(dif < minDif) {
                correspondingPayout = payout;
            }
        }
    }

    return correspondingPayout;
}

uint32_t calculatePayout(const std::array<std::array<GridItem, 6>, 5>& grid, std::ostringstream& printStr, std::set<std::pair<uint32_t, uint32_t>>& winningPositions) {
    uint32_t totalPayout = 0;
    std::map<uint32_t, uint32_t> itemCounts;                    // Map to store the frequency of each item

    printStr << "Receipt: " << std::endl;

    // Count the occurences
    for(size_t i=0; i<5; ++i){
        for(size_t j=0; j<6; ++j){
            uint32_t itemID = grid.at(i).at(j).getID();
            itemCounts[itemID]++;
        }
    }

    // Calculate the payout with threshold
    for(const auto& [itemID, count] : itemCounts) {
        uint32_t currentPayout;
        const auto& payouts = allPayouts[itemID];
        currentPayout = findMinPayout(payouts, count);

        // Winning Item
        if(currentPayout != 0) {
            printStr << count << "x " << ItemKey.at(itemID).icon << " " << ItemKey.at(itemID).name << " -> " << currentPayout/100.0 << "€" << std::endl;
            totalPayout += currentPayout;

            // Add positions of this winning item to the set
            for(size_t i=0; i<5; ++i){
                for(size_t j=0; j<6; ++j){
                    if(grid.at(i).at(j).getID() == itemID) {
                        winningPositions.insert({i, j});
                    }
                }
            }
        } 
    }

    return totalPayout;
}

// Print Payout
void printPayout(uint32_t payout, std::ostringstream& printStr) {
    printStr << "Total Payout: " << payout/100.0 << "€\n" << std::endl;
}