#ifndef TUMBLE_HPP
#define TUMBLE_HPP

// Main header
#include "pch.hpp"

// Other headers
#include "GridItem.hpp"
#include "setup.hpp"
#include "probabilities.hpp"

// Functions
void removeWinningItems(std::array<std::array<GridItem, 6>, 5>& grid,
                        std::set<std::pair<uint32_t, uint32_t>>& winningPositions,
                        std::ostringstream& printStr);

void applyGravity(std::array<std::array<GridItem, 6>, 5>& grid,
                  std::ostringstream& printStr);

void generateNewItems(std::array<std::array<GridItem, 6>, 5>& grid,
                      std::ostringstream& printStr);

#endif