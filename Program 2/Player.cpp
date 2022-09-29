#include "Player.h"
#include <iostream>


Player::Player() {
    // Default Constructor
    firstName = "unknown";
    lastName = "unkown";

    // Set all seven statistics values to 0.
    for (int i = 0; i < 7; i++) {
        stats[i] = 0;
    }
}


void Player::setter() {
    // Update the first and last name
    std::cin >> firstName >> lastName;

    // Insert the statistics in the array
    for (int i = 0; i < 7; i++) {
        std::cin >> stats[i];
    }

}


double Player::getFenwick() {
    double numerator = (stats[1] + stats[3]); // Shots on Target for + Missed shots for
    double denominator = ((stats[1] + stats[3]) - (stats[2] + stats[4])); // (Numerator) - (shots on target against + missed shots against)

    return (round(((numerator / denominator) * 100) * 10) / 10); // Round to nearest 10ths place (first decimal).
}


double Player::getCaloriesBurned() {
    // (met * bodyweight * 3.5) / 200
    return (round(((stats[5] * stats[6] * 3.5) / 200) * 10) / 10); // Round to nearest 10ths place (first decimal).
}


std::string Player::getFirstName() {
    return firstName;
}


std::string Player::getLastName() {
    return lastName;
}