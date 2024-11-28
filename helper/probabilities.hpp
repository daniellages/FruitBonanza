#ifndef PROBABILITIES_HPP
#define PROBABILITIES_HPP

// Main Header
#include "pch.hpp"

// Other headers
#include "../src/GridItem.hpp"

// Local functions
void createDistribution();

GridItem getRandom();

void calculateProbabilities(std::array<GridItem, totalItems>& items);   // This function will store items for future use

uint32_t findMinPayout(const std::map<uint32_t, uint32_t>& payouts,
                       uint32_t count);

uint32_t calculatePayout(const std::array<std::array<GridItem, 6>, 5>& grid,
                         std::ostringstream& printStrs,
                         std::set<std::pair<uint32_t, uint32_t>>& winningPositions);

void printPayout(uint32_t payout,
                 std::ostringstream& printStr);

#endif