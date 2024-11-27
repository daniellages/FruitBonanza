#ifndef GRIDITEM_HPP
#define GRIDITEM_HPP

// TODO:
//  Maybe i should use 2 times ItemKey.at(id).name and ItemKey.at(id).icon, im calling it with the same id everytime

// Main Header
#include "pch.hpp"

// Local Variable
const uint32_t totalItems = 10;

extern const std::array<std::map<uint32_t, uint32_t>, totalItems> allPayouts;

// Class
class GridItem {
    private:
        uint32_t id;                            // ID of the item
        std::map<uint32_t,uint32_t> payouts;    // Payout rules (multiplier) [count:value]
        uint32_t probability;                   // Probability
    
    public:
        // Constructor
        GridItem(); // Default ID=0
        GridItem(const uint32_t itemID);

        // Getters
        uint32_t getID() const {return id;}
        std::map<uint32_t,uint32_t> getPayouts() const {return payouts;}
        uint32_t getProbability() const {return probability;}
        std::string getName() const;
        std::string getIcon() const;

        // Setters
        void setProbability(uint32_t itemProbability) {probability = itemProbability;}

        // DEBUG: Print Details
        void printDetails(bool printHeader, std::ostringstream& printStr) const;
};

// Functions
void printGrid(const std::array<std::array<GridItem, 6>, 5>& grid, std::ostringstream& printStr);

#endif