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

    // Get array with items
    std::array<GridItem, 10> items = setupItems();

    // Initialize discrete distribution
    calculateProbabilities(items);
    std::discrete_distribution<> dist = createDistribution(items);

    // DEBUG: Print Details
    std::ostringstream printStr;
    items.at(0).printDetails(true, printStr);    // Print Header
    for(const auto& item : items) {
        item.printDetails(false, printStr);
    }

    // Generate 6x5 grid random
    std::array<std::array<GridItem, 6>, 5> view = generateView(items, dist);
    printGrid(view, printStr);

    // Single print output
    std::string outputStr = printStr.str();
    std::cout << outputStr << std::endl;

    return 0;
}