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
        weights.at(i) = (weight == 0 ? 1 : weight);               // Probability can't be 0
    }

    // Update item's probability
    for(auto& item : items) {
        item.setProbability(weights.at(item.getID()));
    }
}