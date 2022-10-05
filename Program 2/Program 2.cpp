#include "PlayerList.h"
#include <iostream>
#include <fstream>
#include <iomanip>


Playerlist getPlayers(std::string inFileName);
void writeData(std::string outFileName, Playerlist players);

int main() {
	std::string inFileName;
	std::string outFileName;

	// Prompt
	std::cout << "Welcome to the hockey player statistics calculator test program."
		<< std::endl << "I am going to read players from an input data file. You will tell me the names of your input and output files."
		<< std::endl << "I will store all of the players in a list, compute player's stats and then write the resulting team report to your output file." << std::endl;

	// Get File Names
	std::cout << "Enter the name of your input file: ";
	std::cin >> inFileName;

	std::cout << "Enter the name of your output file: ";	
	std::cin >> outFileName;

	// Read
	std::cout << std::endl << "Reading Players from: " << inFileName << std::endl;
	Playerlist players = getPlayers(inFileName);

	// Write
	writeData(outFileName, players);
	std::cout << "The data has been written to your output file: " << outFileName << std::endl;

	// End
	std::cout << std::endl << "End of Program 2" << std::endl;


	return 1;
}


// Function to Read the data from input file
Playerlist getPlayers(std::string inFileName) {
	std::ifstream inFile;
	std::string line; // contains the data of the read line
	std::string firstName, lastName; // variables for first and last name of player
	int statsArr[7]; // array to pass the stats to player obj
	int lineNum = 0;

	inFile.open(inFileName);
	while (!inFile.eof()) { // while not at end of file
		std::getline(inFile, line); // read a line from the file and store it in the line variable
		lineNum++; // get the number of players in the folder by counting lines
	}
	
	// Return to beginning of file
	inFile.clear();
	inFile.seekg(0);

	Playerlist players = Playerlist(lineNum);


	while (!inFile.eof()) { // while not at end of file
		// save names to name variables
		inFile >> firstName;
		inFile >> lastName;

		// save stats to array
		for (int i = 0; i < 7; i++) {
			inFile >> statsArr[i];
		}
	
		// pass the data read from the file into a player obj and add it to the playerlist
		players.addPlayer(Player(firstName, lastName, statsArr));
	}

	inFile.close();
	return players;
}


void writeData(std::string outFileName, Playerlist players) {
	std::ofstream outFile;
	outFile.open(outFileName);

	// Write the header
	outFile << "BASKETBALL TEAM REPORT --- " << players.getSize() << " PLAYERS FOUND IN FILE" << std::endl
			<< "TOTAL CALORIES BURNED: " << players.getTotalCaloriesBurned() << std::endl << std::endl
			<< std::string(6, ' ') << "PLAYER NAME" << std::string(6, ' ') << " :"
			<< std::string(7, ' ') << "FF%" << std::string(4, ' ')
			<< std::string(4, ' ') << "Calories burned" << std::endl
			<< std::string(58, '-') << std::endl;
	outFile << std::fixed << std::setprecision(1);

	// Write the players
	Player player;
	while (players.hasNext()) {
		player = players.getNext();
		
		// Write to the outfile in proper format
		outFile << std::setw(23) << (player.getLastName() + ", " + player.getFirstName()) << " :"
				<< std::setw(11) << (player.getFenwick() * 100)
				<< std::setw(17) << player.getCaloriesBurned() << std::endl;
	}

	outFile.close();
}