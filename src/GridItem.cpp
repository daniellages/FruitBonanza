#include "GridItem.hpp"

// Match ID to details
struct ItemDetails {
    std::string name;
    std::string icon;
    std::map<uint32_t, uint32_t> payout;
};

// Define allPayouts
const std::array<std::map<uint32_t, uint32_t>, totalItems> allPayouts = {{
    {{8, 1000}, {10, 2500}, {12, 5000}},  // Red Gem
    {{8, 250}, {10, 1000}, {12, 2500}},  // Pink Gem
    {{8, 200}, {10, 500}, {12, 1500}},   // Green Gem
    {{8, 150}, {10, 200}, {12, 1200}},   // Blue Gem
    {{8, 100}, {10, 150}, {12, 1000}},   // Apple
    {{8, 80}, {10, 120}, {12, 800}},     // Peach
    {{8, 50}, {10, 100}, {12, 500}},     // Watermelon
    {{8, 40}, {10, 90}, {12, 400}},      // Grapes
    {{8, 25}, {10, 75}, {12, 200}},      // Banana
    {{3, 300}, {5, 500}, {6, 10000}}     // Lolipop
}};

// Item map -> ID : Name and Icon
std::map<uint32_t,ItemDetails> ItemKey{
        {0, {"Red", "❤️", allPayouts[0]}},
        {1, {"Pink", "🩷", allPayouts[1]}},
        {2, {"Green", "💚", allPayouts[2]}},
        {3, {"Blue", "💙", allPayouts[3]}},
        {4, {"Apple", "🍎", allPayouts[4]}},
        {5, {"Peach", "🍑", allPayouts[5]}},
        {6, {"Watermelon", "🍉", allPayouts[6]}},
        {7, {"Grapes", "🍇", allPayouts[7]}},
        {8, {"Banana", "🍌", allPayouts[8]}},
        {9, {"Lolipop", "🍭", allPayouts[9]}}
};

// GridItem Class Functions

// Constructor
GridItem::GridItem(const uint32_t itemID) {
    id = itemID;
    payouts = ItemKey.at(id).payout;
    probability = 0;
}

// DEBUG: Print Details
void GridItem::printDetails(bool printHeader, std::ostringstream& printStr) const {
    // Header
    if(printHeader) {
        printStr << std::left << std::setw(15) << "Item"
                 << std::setw(40) << "Payouts"
                 << std::setw(15) << "Probability"
                 << "Icon" << std::endl;
        // Separator
        printStr << std::string(85, '-') << std::endl;
        return;
    }

    // Row
    printStr << std::left << std::setw(15) << ItemKey.at(id).name;

    // Payouts
    std::string payoutsStr = "";
    for (const auto& [threshold, value] : payouts) {
        payoutsStr += std::to_string(threshold) + "+->" + std::to_string(value) + "% ";
    }
    printStr << std::setw(40) << payoutsStr;

    // Probability and Icon
    printStr << std::setw(15) << probability
             << ItemKey.at(id).icon << std::endl;
};