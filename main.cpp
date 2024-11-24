#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <random>
#include <numeric>
using namespace std;

// Tips to remember:
//  Always initialize variables (memory control)
//  Make headers

// Notes:
//  const & are used to avoids copies and doesnt modify the argument

// TODO:

// Defining Types
enum class ItemType{FRUIT, GEM, LOLIPOP}; // All possible types

// Define item class
class GridItem {
    public:
        // Constructor
        GridItem(const string& itemName, ItemType itemType, const map<int,double>& payoutRules, double prob): name(itemName), type(itemType), payouts(payoutRules), probability(prob) {}

        // Getters
        string getName() const {return name;}
        ItemType getType() const {return type;}
        double getProbability() const {return probability;}

        // Read enum
        static string typeToString(ItemType itemType) {
            switch(itemType) {
                case ItemType::FRUIT: return "Fruit";
                case ItemType::GEM: return "Gem";
                case ItemType::LOLIPOP: return "Lolipop";
                default: return "Unknown";
            }
        }

        // Get payout multiplyer based on count
        double getPayout(int count) const {
            double payout = 0;
            for(const auto& [threshold, value] : payouts) {
                if(count >= threshold) {
                    payout = value;
                }
            }
            return payout;
        }

        // Debug: Print Details
        void printDetails() const {
            cout << "Item: " << name
                 << ", Type: " << typeToString(type)
                 << ", Payouts: ";
            for (const auto& [threshold, value] : payouts) {
                cout << threshold << "+->" << value << "x ";
            }
            cout << ", Probability: " << probability << endl;
        }
    private:
        string name;                // Name of the item
        ItemType type;              // Type of the item
        map<int,double> payouts;    // Payout rules (multiplier) [count:value]
        double probability;         // Inverse probability to payout
};

// Calculate Normalized Probabilities
vector<double> calculateProb(const vector<map<int,double>>& allPayouts) {
    vector<double> probabilities;

    // Calculate Payouts sum
    double totalPayoutAll = 0;
    for(const auto& payouts : allPayouts) {
        for(const auto& [threshold, value] : payouts) {
            totalPayoutAll += value;
        }
    }

    // Calculate probability of each item
    for(const auto& payouts : allPayouts) {
        double totalPayout = 0;
        for(const auto& [threshold, value] : payouts) {
            totalPayout += value;
        }

        probabilities.push_back((totalPayout > 0 && totalPayoutAll > 0) ? (totalPayout / totalPayoutAll) : 0.0);
    }

    return probabilities;
}

int main() {
    // Initialize items
    vector<map<int,double>> allPayouts = {{{8, 10.0}, {10, 25.0}, {12, 50.0}},  // Red Gem
                                          {{8, 2.5}, {10, 10.0}, {12, 25.0}},  // Pink Gem
                                          {{8, 2.0}, {10, 5.0}, {12, 15.0}},   // Green Gem
                                          {{8, 1.5}, {10, 2.0}, {12, 12.0}},   // Blue Gem
                                          {{8, 1.0}, {10, 1.5}, {12, 10.0}},   // Apple
                                          {{8, 0.8}, {10, 1.2}, {12, 8.0}},    // Peach
                                          {{8, 0.5}, {10, 1.0}, {12, 5.0}},    // Watermelon
                                          {{8, 0.4}, {10, 0.9}, {12, 4.0}},    // Grapes
                                          {{8, 0.25}, {10, 0.75}, {12, 2.0}},  // Banana
                                          {{3, 3.0}, {5, 5.0}, {6, 100.0}}};   // Lolipop

    // Get normalized probabilities
    vector<double> probabilities = calculateProb(allPayouts);

    // Create GridItems
    GridItem redGem("Red", ItemType::GEM, allPayouts[0], probabilities[0]);
    GridItem pinkGem("Pink", ItemType::GEM, allPayouts[1], probabilities[1]);
    GridItem greenGem("Green", ItemType::GEM, allPayouts[2], probabilities[2]);
    GridItem blueGem("Blue", ItemType::GEM, allPayouts[3], probabilities[3]);
    GridItem apple("Apple", ItemType::FRUIT, allPayouts[4], probabilities[4]);
    GridItem peach("Peach", ItemType::FRUIT, allPayouts[5], probabilities[5]);
    GridItem watermelon("Watermelon", ItemType::FRUIT, allPayouts[6], probabilities[6]);
    GridItem grapes("Grapes", ItemType::FRUIT, allPayouts[7], probabilities[7]);
    GridItem banana("Banana", ItemType::FRUIT, allPayouts[8], probabilities[8]);
    GridItem lolipop("Lolipop", ItemType::LOLIPOP, allPayouts[9], probabilities[9]);


    // Store items in a vector
    vector<GridItem> items = {redGem, pinkGem, greenGem, blueGem, apple, peach, watermelon, grapes, banana, lolipop};

    // Debug: Print Details
    for(const auto& item : items) {
        item.printDetails();
    }

    return 0;
}