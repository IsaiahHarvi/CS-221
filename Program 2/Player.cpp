#include "Player.h"


// Default Constructor
Player::Player() {
	next = nullptr;
	prev = nullptr;

	firstName = "unkown";
	lastName = "unknown";

	for (int i = 0; i < 7; i++) {
		stats[i] = 0;
	}
}


// Constructor with data read from file
Player::Player(std::string playerFirstName, std::string playerLastName, int statsArray[]) {
	firstName = playerFirstName;
	lastName = playerLastName;

	for (int i = 0; i < 7; i++) {
		stats[i] = statsArray[i];
	}
}


// Return first name
std::string Player::getFirstName() {
	return firstName;
}


// Return last name
std::string Player::getLastName() {
	return lastName;
}


// Calculate fenwick percentage
double Player::getFenwick() {
	double numerator = (stats[1] + stats[3]); // Shots on Target for + Missed shots for
	double denominator = ((stats[1] + stats[3]) - (stats[2] + stats[4])); // (Numerator) - (shots on target against + missed shots against)

	return (round(((numerator / denominator) * 100) * 10) / 10); // Round to nearest 10ths place (first decimal).
}


// Calculate the burned calories
double Player::getCaloriesBurned() {
	// (met * bodyweight * 3.5) / 200
	return (round(((stats[5] * stats[6] * 3.5) / 200) * 10) / 10); // Round to nearest 10ths place (first decimal).
}
