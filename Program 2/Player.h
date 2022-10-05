#pragma once
#include <fstream>

class Player {
private:
    std::string firstName;
    std::string lastName;
    std::string iFileName;
    std::string oFileName;
    int stats[7];

public:
    Player();
    void setter(std::ifstream *inputFile);
    double getFenwick();
    double getCaloriesBurned();
    std::string getIFileName();
    std::string getOFileName();
    std::string getLastName();
    std::string getFirstName();
};
