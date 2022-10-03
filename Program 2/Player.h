#pragma once
#include <string>

class Player {
private:
    std::string iFileName;
    std::string oFileName;
    int stats[];

public:
    Player();
    void setter();
    double getFenwick();
    double getCaloriesBurned();
    std::string getIFileName();
    std::string getOFileName();
};
