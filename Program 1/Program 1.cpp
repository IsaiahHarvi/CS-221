// Isaiah Harville
// 9/14/22 | Visual Studio 2022
// Program 1.cpp : This program calculates Advanced Statistics For a Hockey Player.
//               : After the user inputs the statistics: Age ShotsTargetFor ShotsTargetAgainst MissedShotsFor MissedShotsAgainst MET Bodyweight
//               : This program will return the player's Fenwick For percentage and their calories burned while playing hockey.

#include <iostream>
#include <fstream>
#include <cmath>


std::string grammaticallyCorrectApostrapheS(std::string lastName);


class Player {
private:
    std::string firstName, lastName;

    int stats[7] = {}; // Array containing all statistics about Player

public:
    // Default Constructor
    Player() {
        firstName = "unknown";
        lastName = "unkown";

        // Set all seven statistics values to 0.
        for (int i = 0; i < 7; i++) {
            stats[i] = 0;
        }

    }

    void setter() {
        // Update the first and last name
        std::cin >> firstName >> lastName;

        // Insert the statistics in the array
        for (int i = 0; i < 7; i++) {
            std::cin >> stats[i];
        }

    }

    // Function to Calculate Fenwick For Percentage and return it
    double getFenwick() {
        double numerator = (stats[1] + stats[3]); // Shots on Target for + Missed shots for
        double denominator = ((stats[1] + stats[3]) - (stats[2] + stats[4])); // (Numerator) - (shots on target against + missed shots against)

        return (round(((numerator / denominator) * 100) * 10) / 10); // Round to nearest 10ths place (first decimal).
    }

    // Function to calculate the burned calories and return it
    double getCaloriesBurned() {
        // (met * bodyweight * 3.5) / 200
        return (round(((stats[5] * stats[6] * 3.5) / 200) * 10) / 10); // Round to nearest 10ths place (first decimal).
    }

    // Function for returning the first name
    std::string getFirstName() {
        return firstName;
    }

    // Function for returning the last name
    std::string getLastName() {
        return lastName;
    }
};


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
        }else { repeat = false; }

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