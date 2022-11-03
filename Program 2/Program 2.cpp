// Isaiah Harville
// 11/3/22 | Visual Studio 2022
// Program 3.cpp : This program calculates Advanced Statistics For a Hockey Player.
//               : The program will read from an input data file and will perform a series of calculations.
//               : It will then return the calculations in another data file.
//				 : Program 3 is the same as Program 2 except it utilizes a linked list instead of an array and offers the removal of players.

#include "PlayerList.h"
#include <iostream>
#include <fstream>


int main() {
	PlayerList playerList;
	std::string iFileName;
	std::string oFileName;
	std::string firstName;
	std::string lastName;
	char remove;

	// Prompt
	std::cout << "Welcome to the hockey player statistics calculator test program."
		<< std::endl << "I am going to read players from an input data file. You will tell me the names of your input and output files."
		<< std::endl << "I will store all of the players in a list, compute player's and then write the resulting team report to your output file." << std::endl;

	// Get File Names
	std::cout << "Enter the name of your input file: ";
	std::cin >> iFileName;

	std::cout << "Enter the name of your output file: ";	
	std::cin >> oFileName;

	// Read
	std::cout << std::endl << "Reading Players from: " << iFileName;
	playerList.getPlayers(iFileName);
	playerList.writeData(oFileName, NULL); // writeData(fileName, character which indicates if anything has been removed)

	// Remove?
	do {
		std::cout << std::endl << "Would you like to remove any players from your list? ";
		std::cin >> remove;

		if (remove == 'y') {
			std::cout << "\tPlease enter the First and Last Name of the Player: ";
			std::cin >> firstName >> lastName; 

			if (playerList.removePlayer(firstName, lastName)) { // If the player was in the list
				std::cout << "\t" << firstName << " " << lastName << " Removed Successfully." << std::endl;
				playerList.writeData(oFileName, remove);
			}

			else { // If the player was not in the list
				std::cout << "\t" << firstName << " " << lastName << " was not found in your list." << std::endl;
			}
		}
	} while (remove == 'y');
	
	
	// End
	std::cout << "Testing Complete.  Both versions of the list have been printed to: " << oFileName << std::endl;
	std::cout << std::endl << "End of Program 3" << std::endl;

	return 1;
}


