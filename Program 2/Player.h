#pragma once
#include <string>

class Player {
private:
    std::string firstName, lastName;
    int stats[];

public:
    Player();
    void setter();
    double getFenwick();
    double getCaloriesBurned();
    std::string getFirstName();
    std::string getLastName();
};
