#include "main.hpp"

// Notes:
//  const & are used to avoids copies and doesnt modify the argument
//  don't use item[x], use item.at(x)
//  don't use vectors, use arrays
//  everything that goes to the terminal has to go all ta once

// TODO:
//  Make payout know what was the count of items and the math, if there were more than one price
//  Add output string spaces somewhere else

int main() {
    // Allow emoji output
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);

    // Get array with items
    std::array<GridItem, 10> items = setupItems();

    // Initialize discrete distribution
    calculateProbabilities(items);
    createDistribution();

    // Create winning Positions variable
    std::set<std::pair<uint32_t, uint32_t>> winningPositions;

    // Create output string
    std::ostringstream printStr;
    printStr << std::fixed << std::setprecision(2);

    // DEBUG: Print Details
    items.at(0).printDetails(true, printStr);    // Print Header
    for(const auto& item : items) {
        item.printDetails(false, printStr);
    }

    // Add space
    printStr << std::endl;

    // Generate 6x5 grid random
    std::array<std::array<GridItem, 6>, 5> view = generateView();
    printGrid(view, printStr);

    // Add space
    printStr << std::endl;

    // Payout
    uint32_t totalPayout = calculatePayout(view, printStr, winningPositions);
    printPayout(totalPayout, printStr);

    // Tumble Feature
    if(totalPayout != 0) {      // Payout activates Tumble Feature
        uint32_t prevTotalPayout = 0;
        while(prevTotalPayout != totalPayout) {
            prevTotalPayout = totalPayout;

            // Will be replaced by tumble()
            removeWinningItems(view, winningPositions, printStr);
            applyGravity(view, printStr);
            generateNewItems(view, printStr);

            // Add space
            printStr << std::endl;

            totalPayout += calculatePayout(view, printStr, winningPositions);
            printPayout(totalPayout, printStr);
        }
    }

    // Single print output
    std::string outputStr = printStr.str();
    std::cout << outputStr << std::endl;

    return 0;
}