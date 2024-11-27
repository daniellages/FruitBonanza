#include "GridItem.hpp"

// Constructor
GridItem::GridItem() {
    id = 0;
    payouts = ItemKey.at(0).payout;
    probability = 0;
}

GridItem::GridItem(const uint32_t itemID) {
    id = itemID;
    payouts = ItemKey.at(id).payout;
    probability = 0;
}

// Getters
std::string GridItem::getName() const {
    return ItemKey.at(id).name;
}

std::string GridItem::getIcon() const {
    return ItemKey.at(id).icon;
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
        printStr << std::string(80, '-') << std::endl;
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