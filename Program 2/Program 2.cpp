// Isaiah Harville
// 10/4/22 | Visual Studio 2022
// Program 2.cpp : This program calculates Advanced Statistics For a Hockey Player.
//               : After the user inputs the statistics: Age ShotsTargetFor ShotsTargetAgainst MissedShotsFor MissedShotsAgainst MET Bodyweight
//               : This program will return the player's Fenwick For percentage and their calories burned while playing hockey.

#include <iostream>
#include <fstream>
#include <cmath>
#include "Player.h"


int main()
{
    Player player;


    // Prompt
    std::cout << "Welcome to the hockey player statistics test driver program." << std::endl
        << "I am going to read players from an input data file. You will tell me the names of your input and output files." << std::endl
        << "I will store all of the players in a list, compute each player's stats and then write the resulting team report to your output file." << std::endl;


    player.setter();

    std::cout << std::endl << "Reading Players from: " << player.getIFileName();

    std::cout << std::endl << "The data has been written to your output file: " << player.getOFileName() << std::endl;;

    std::cout << std::endl << "End of Program 2" << std::endl;

    return 1;
}
