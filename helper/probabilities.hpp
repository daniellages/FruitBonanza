#ifndef MATH_HPP
#define MATH_HPP

// Main Header
#include "pch.hpp"

// Other headers
#include "../src/GridItem.hpp"

// Local functions
std::discrete_distribution<> createDistribution(const std::array<GridItem,
                                                totalItems>& items);
GridItem getRandom(const std::array<GridItem, totalItems>& items,
                   std::discrete_distribution<>& dist);
void calculateProbabilities(std::array<GridItem, totalItems>& items);
uint32_t findMinPayout(const std::map<uint32_t, uint32_t>& payouts, uint32_t count);
uint32_t calculatePayout(const std::array<std::array<GridItem, 6>, 5>& grid);

#endif