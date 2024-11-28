#ifndef GRIDITEM_HPP
#define GRIDITEM_HPP

// TODO:
//  Maybe i should use 2 times ItemKey.at(id).name and ItemKey.at(id).icon, im calling it with the same id everytime

// Main Header
#include "pch.hpp"

// Local Variable
const uint32_t totalItems = 10;

struct ItemDetails {                                                        // Match string to details
    std::string name;
    std::string icon;
    std::map<uint32_t, uint32_t> payout;
};

const std::array<std::map<uint32_t, uint32_t>, totalItems+1> allPayouts = {{  // Define allPayouts
    {{8, 1000}, {10, 2500}, {12, 5000}}, // Red Gem
    {{8, 250}, {10, 1000}, {12, 2500}},  // Pink Gem
    {{8, 200}, {10, 500}, {12, 1500}},   // Green Gem
    {{8, 150}, {10, 200}, {12, 1200}},   // Blue Gem
    {{8, 100}, {10, 150}, {12, 1000}},   // Apple
    {{8, 80}, {10, 120}, {12, 800}},     // Peach
    {{8, 50}, {10, 100}, {12, 500}},     // Watermelon
    {{8, 40}, {10, 90}, {12, 400}},      // Grapes
    {{8, 25}, {10, 75}, {12, 200}},      // Banana
    {{3, 300}, {5, 500}, {6, 10000}},    // Lolipop
    {{0, 0}, {0, 0}, {0, 0}}             // Void Item
}};

const std::map<uint32_t,ItemDetails> ItemKey{                               // Item map -> ID : Name and Icon
        {0, {"Red", "❤️", allPayouts[0]}},
        {1, {"Pink", "🩷", allPayouts[1]}},
        {2, {"Green", "💚", allPayouts[2]}},
        {3, {"Blue", "💙", allPayouts[3]}},
        {4, {"Apple", "🍎", allPayouts[4]}},
        {5, {"Peach", "🍑", allPayouts[5]}},
        {6, {"Watermelon", "🍉", allPayouts[6]}},
        {7, {"Grapes", "🍇", allPayouts[7]}},
        {8, {"Banana", "🍌", allPayouts[8]}},
        {9, {"Lolipop", "🍭", allPayouts[9]}},
        {10,{"NULL", "\u274C", allPayouts[10]}}
};

extern const std::array<std::map<uint32_t, uint32_t>, totalItems+1> allPayouts;

// Class
class GridItem {
    private:
        uint32_t id;                            // ID of the item
        std::map<uint32_t,uint32_t> payouts;    // Payout rules (multiplier) [count:value]
        uint32_t probability;                   // Probability
    
    public:
        // Constructor
        GridItem();                             // Void Item
        GridItem(const uint32_t itemID);

        // Getters
        uint32_t getID() const {return id;}
        std::map<uint32_t,uint32_t> getPayouts() const {return payouts;}
        uint32_t getProbability() const {return probability;}
        std::string getName() const;
        std::string getIcon() const;
        bool isEmpty() const {return (id == 10) ? true : false;}            // Check if it is void item

        // Setters
        void setProbability(uint32_t itemProbability) {probability = itemProbability;}

        // DEBUG: Print Details
        void printDetails(bool printHeader, std::ostringstream& printStr) const;
};

#endif