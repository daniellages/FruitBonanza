#include "main.hpp"

// Notes:
//  const & are used to avoids copies and doesnt modify the argument
//  don't use item[x], use item.at(x)
//  don't use vectors, use arrays
//  everything that goes to the terminal has to go all ta once

// TODO:

int main() {
    // Allow emoji output
    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);

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

    // Store items in a vector
    std::array<GridItem, 10> items = {redGem, pinkGem, greenGem, blueGem, apple, peach, watermelon, grapes, banana, lolipop};

    // Initialize discrete distribution
    calculateProbabilities(items);
    std::discrete_distribution<> dist = createDistribution(items);

    // DEBUG: Print Details
    std::ostringstream printStr;
    items.at(0).printDetails(true, printStr);    // Print Header
    for(const auto& item : items) {
        item.printDetails(false, printStr);
    }

    // Print random
    printStr << "\nRandom Choosen: " << std::endl;
    getRandom(items, dist).printDetails(false, printStr);

    // Single print output
    std::string outputStr = printStr.str();
    std::cout << outputStr << std::endl;

    return 0;
}