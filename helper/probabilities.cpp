#include "probabilities.hpp"

// TODO:
//  Swap for loop line 9 for const auto& item: items
//  Same for line 32

// Initiate Discrete Distribution
std::discrete_distribution<> createDistribution(const std::array<GridItem, totalItems>& items) {
    std::array<uint32_t, totalItems> probabilities;
    for(size_t i=0; i<totalItems; ++i) {
        probabilities.at(i) = items.at(i).getProbability();
    }
    return std::discrete_distribution<>(probabilities.begin(), probabilities.end());
}

// Random number generator
std::random_device rd;
std::mt19937 gen(rd());

// Get Random
GridItem getRandom(const std::array<GridItem, totalItems>& items, std::discrete_distribution<>& dist) {
    // Select random index
    uint32_t selectedIdx = dist(gen);
    return items.at(selectedIdx);
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

uint32_t calculatePayout(const std::array<std::array<GridItem, 6>, 5>& grid, std::ostringstream& printStr) {
    uint32_t totalPayout = 0;
    std::map<uint32_t, uint32_t> itemCounts;    // Map to store the frequency of each item

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
        uint32_t tempPayout;                        // Just to print each payout separatly
        const auto& payouts = allPayouts[itemID];
        tempPayout = findMinPayout(payouts, count);
        if(tempPayout != 0) {
            printStr << std::to_string(count) << "x " << ItemKey.at(itemID).icon << " " << ItemKey.at(itemID).name << " -> " << std::to_string(tempPayout) << "%" << std::endl;
            totalPayout += tempPayout;
        } 
    }

    return totalPayout;
}