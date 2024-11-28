#include "tumble.hpp"

// printStr << "Tumbling . . ." << std::endl;

// Replaces winning positions by void items
void removeWinningItems(std::array<std::array<GridItem, 6>, 5>& grid, std::set<std::pair<uint32_t, uint32_t>>& winningPositions, std::ostringstream& printStr) {
    for(const auto& [row, col] : winningPositions) {
        grid[row][col] = GridItem();              // Replace by void
    }

    // Erase winning positions
    winningPositions.clear();

    // DEBUG
    printStr << "Removing items:" << std::endl;
    printGrid(grid, printStr);
}

// Make items fall down
void applyGravity(std::array<std::array<GridItem, 6>, 5>& grid, std::ostringstream& printStr) {
    for(uint32_t col = 0; col < 6; ++col) {
        uint32_t emptyRow = 4;              // Last row
        for(int32_t row = 4; row >= 0; --row) {                     // Can't be uint32_t because of --row
            if(!grid[row][col].isEmpty()) {
                std::swap(grid[emptyRow][col], grid[row][col]);
                --emptyRow;
            }
        }
    }

    // DEBUG
    printStr << "Gravity:" << std::endl;
    printGrid(grid, printStr);
}

// Generate new items in empty spots
void generateNewItems(std::array<std::array<GridItem, 6>, 5>& grid, std::ostringstream& printStr) {
    for(size_t col = 0; col < 6; ++col) {
        for(size_t row = 0; row < 5; ++row) {
            if(grid[row][col].isEmpty()) {
                grid[row][col] = getRandom();
            }
        }
    }

    // DEBUG
    printStr << "Generating new items:\n" << std::endl;
    printGrid(grid, printStr);
}