#include "setup.hpp"

// Initialize items and return them in an array
std::array<GridItem, 10> setupItems() {
    // Create GridItems
    GridItem redGem(0);
    GridItem pinkGem(1);
    GridItem greenGem(2);
    GridItem blueGem(3);
    GridItem apple(4);
    GridItem peach(5);
    GridItem watermelon(6);
    GridItem grapes(7);
    GridItem banana(8);
    GridItem lolipop(9);

    // Store items in an array
    std::array<GridItem, 10> items = {redGem, pinkGem, greenGem, blueGem, apple, peach, watermelon, grapes, banana, lolipop};

    return items;
}

// Generates a grid 6x5 of random items
std::array<std::array<GridItem, 6>, 5> generateView(std::array<GridItem, 10>& items, std::discrete_distribution<>& dist) {
    std::array<std::array<GridItem, 6>, 5> view;

    for(size_t i=0; i<5; ++i) {     // Rows
        for(size_t j=0; j<6; ++j) { // Cols
            view[i][j] = getRandom(items, dist);
        }
    }

    return view;
}

// Print Grid
void printGrid(const std::array<std::array<GridItem, 6>, 5>& grid, std::ostringstream& printStr) {
    for(const auto& row : grid) {
        for(const auto& item : row) {
            printStr << item.getIcon() << " | ";
        }
        printStr << std::endl;
    }
}

// Print Payout
void printPayout(uint32_t payout, std::ostringstream& printStr) {
    printStr << "Total Payout: " << std::to_string(payout) << std::endl;
}