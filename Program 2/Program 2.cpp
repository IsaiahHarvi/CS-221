// Isaiah Harville
// 10/4/22 | Visual Studio 2022
// Program 2.cpp : This program calculates Advanced Statistics For a Hockey Player.
//               : After the user inputs the statistics: Age ShotsTargetFor ShotsTargetAgainst MissedShotsFor MissedShotsAgainst MET Bodyweight
//               : This program will return the player's Fenwick For percentage and their calories burned while playing hockey.

#include <iostream>
#include <fstream>
#include <cmath>
#include "Player.h"


std::string grammaticallyCorrectApostrapheS(std::string lastName);


int main()
{
    bool repeat; // True to continue the loop and False to break
    char yn;     // Y keeps repeat at True, N will set it to False

    do {
        Player player;


        // Prompt
        std::cout << "Welcome to the hockey player statistics test driver program." << std::endl
            << "When prompted, please enter the player's data in the form of" << std::endl
            << "Firstname Lastname Age ShotsTargetFor ShotsTargetAgainst MissedShotsFor MissedShotsAgainst MET Bodyweight" << std::endl;

        std::cout << std::endl << "Enter PlayerData: ";

        // Take input and build the player obj
        player.setter();

        // Print the player Data
        std::cout << player.getFirstName() << " " << player.getLastName() << grammaticallyCorrectApostrapheS(player.getLastName()) << " FF% = " << player.getFenwick() << "%"
            << " and Calories Burned = " << player.getCaloriesBurned() << std::endl;

        // Prompt to test another player
        std::cout << "Do you wish to test another [y/n]? ";
        std::cin >> yn;

        // Test another?  If 'n' the loop will break
        if (yn == 'y' || yn == 'Y') {
            repeat = true;
        }
        else { repeat = false; }

    } while (repeat);

    std::cout << "Program 1 Testing Complete" << std::endl;
}


// Completely necessary function to properly construct the print statement for the player data.
// Note: this is not a method because this function is exlusively for the test driver.
//     : this program is developed passively with the main() only serving as a test.
std::string grammaticallyCorrectApostrapheS(std::string lastName) {
    // If the last name ends with "s" it will return a "'".  Otherwise it will return "'s".
    // For Example: LastName = Neelis, Output: Nellis' Stats
    // Example 2: LastName = Neel, Output: Neel's Stats
    if (lastName.back() == 's') {
        return "'";
    }

    return "'s";
}