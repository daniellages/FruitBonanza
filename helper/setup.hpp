#ifndef SETUP_HPP
#define SETUP_HPP

// Main Header
#include "pch.hpp"

// Other Headers
#include "../src/GridItem.hpp"
#include "probabilities.hpp"

// Functions
std::array<GridItem, 10> setupItems();  // returns an array with all items
std::array<std::array<GridItem, 6>, 5> generateView(); // returns a view of random items 6x5
void printGrid(const std::array<std::array<GridItem, 6>, 5>& grid, std::ostringstream& printStr);

#endif