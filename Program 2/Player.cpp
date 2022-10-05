#include "Player.h"

// Default Constructor
Player::Player() {
    iFileName = "";
    oFileName = "";
    firstName = "";
    lastName = "";

    // Set all seven statistics values to 0.
    for (int i = 0; i < 7; i++) {
        stats[i] = 0;
    }
}


// Constructor
void Player::setter(std::ifstream *inputFile) {
   
    if (inputFile.is_open()) {
        inputFile >> firstName >> lastName;

        for (int i = 0; i < 7; i++) {
            inputFile >> stats[i];
        }
    }
}


// Calculates Fenwick percentage
double Player::getFenwick() {
    double numerator = (stats[1] + stats[3]); // Shots on Target for + Missed shots for
    double denominator = ((stats[1] + stats[3]) - (stats[2] + stats[4])); // (Numerator) - (shots on target against + missed shots against)

    return (round(((numerator / denominator) * 100) * 10) / 10); // Round to nearest 10ths place (first decimal).
}


// Calculates Calories Burned
double Player::getCaloriesBurned() {
    // (met * bodyweight * 3.5) / 200
    return (round(((stats[5] * stats[6] * 3.5) / 200) * 10) / 10); // Round to nearest 10ths place (first decimal).
}


// Returns the name of the input file
std::string Player::getIFileName() {
    return iFileName;
}


// Returns the name of the output file
std::string Player::getOFileName() {
    return oFileName;
}


// Returns the player's last name
std::string Player::getLastName() {
    return lastName;
}


// Returns the player's first name
std::string Player::getFirstName() {
    return firstName;
}