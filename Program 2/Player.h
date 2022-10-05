#pragma once

#include <string>

class Player {
private:
	std::string firstName;
	std::string lastName;
	int stats[7];

public:
	Player();
    Player(std::string firstName, std::string lastName, int statsArray[]);
	std::string getFirstName();
	std::string getLastName();
	double getFenwick();
	double getCaloriesBurned();
};