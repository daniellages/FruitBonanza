#ifndef SETUP_HPP
#define SETUP_HPP

// Main Header
#include "pch.hpp"

// Other Headers
#include "../src/GridItem.hpp"
#include "probabilities.hpp"

// Functions
std::array<GridItem, 10> setupItems();  // returns an array with all items
std::array<std::array<GridItem, 6>, 5> generateView(std::array<GridItem, 10>& items, std::discrete_distribution<>& dist); // returns a view of random items 6x5
void printGrid(const std::array<std::array<GridItem, 6>, 5>& grid, std::ostringstream& printStr);
void printPayout(uint32_t payout, std::ostringstream& printStr);

#endif