// Isaiah Harville
// 10/4/22 | Visual Studio 2022
// Program 2.cpp : This program calculates Advanced Statistics For a Hockey Player.
//               : After the user inputs the statistics: Age ShotsTargetFor ShotsTargetAgainst MissedShotsFor MissedShotsAgainst MET Bodyweight
//               : This program will return the player's Fenwick For percentage and their calories burned while playing hockey.

#include <iostream>
#include <fstream> // remove if it remains in Player.h
//#include <cmath> i dont think i need this but I guess we will see in an hour or two
#include "PlayerList.h"


int main()
{
    Player player;
    std::ifstream inputFile;
    std::string inputFileName, outputFileName, firstName, lastName;

    // Prompt
    std::cout << "Welcome to the hockey player statistics test driver program." << std::endl
        << "I am going to read players from an input data file. You will tell me the names of your input and output files." << std::endl
        << "I will store all of the players in a list, compute each player's stats and then write the resulting team report to your output file." << std::endl;

    // Collect File Names
    std::cout << std::endl << "Enter input file name: ";
    std::cin >> inputFileName;
    std::cout << std::endl << "Enter output file name: ";
    std::cin >> outputFileName;

    int lines = 0; // variable for tracking the length of the file and therefore the length of playerlist
    inputFile.open(inputFileName);

    player.setter(&inputFile);

    PlayerList players = PlayerList(lines);

    // Status Messages
    std::cout << std::endl << "Reading Players from: " << player.getIFileName();

    std::cout << std::endl << "The data has been written to your output file: " << player.getOFileName() << std::endl;;

    std::cout << std::endl << "End of Program 2" << std::endl;

    return 1;

}
