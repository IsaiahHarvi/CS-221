#include "PlayerList.h"
#include "Player.h"
#include "bitwiseFunctions.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>


PlayerList::PlayerList() {
	head = nullptr;
	current = head;
	last = head;
	size = 0;
}


void PlayerList::addPlayer(Player *player) {
	if (size == 0) { // first element to be added to the list
		head = player;
		current = head;
		last = head;
		size++;

		return;
	}
	
	Player *currentPlayer = head;
	for (int i = 0; i < size; i++) {
		if ((player->getLastName() + player->getFirstName()) < (currentPlayer->getLastName() + currentPlayer->getFirstName())) { // if a < b add n so: a < n < b
			if (currentPlayer->prev == nullptr) { // If we are at the first node
				player->next = currentPlayer;	 // pointing our new head forwards to the old head
				currentPlayer->prev = player;	 // pointing back to the new head
				head = player;					 // updating head
			}

			else {
				// If not first node
				player->prev = currentPlayer->prev;
				currentPlayer->prev->next = player;
				player->next = currentPlayer;
				currentPlayer->prev = player;
			}
			size++; // added one
			return;
		}
		currentPlayer = currentPlayer->next;
	}
	
	// last node
	player->prev = last; 
	last->next = player;
	last = player;
	size++; // added to end
}


bool PlayerList::removePlayer(std::string firstName, std::string lastName) {
	Player *toRemove = head;

	while (true) {
		// Not in list
		if (toRemove == nullptr) {
			return false;
		}

		if ((toRemove->getFirstName() + toRemove->getLastName()) == (firstName + lastName)) { 
			// Delete head
			if (toRemove->prev == nullptr) {
				head = toRemove->next;
				toRemove->next->prev = nullptr;

				size--;
				delete toRemove;
				return true;
			}

			// Not first or last node
			if (toRemove->next != nullptr) {
				toRemove->next->prev = toRemove->prev;
				toRemove->prev->next = toRemove->next;

				size--;
				delete toRemove;
				return true;
			}

			// Last Nodef
			toRemove->prev->next = nullptr;
			last = toRemove->prev;

			size--;
			delete toRemove;
			return true;
		}
		toRemove = toRemove->next;
	}
}


void PlayerList::clear() {
	size = 0;
	Player *del = nullptr;
	while (head != nullptr) {
		del = head;
		head = head->next;
		delete del;
	}
}


bool PlayerList::isEmpty() {
	return (size == 0);
}


int PlayerList::getSize() {
	return size;
}


double PlayerList::getTotalCaloriesBurned() {
	double total = 0;
	Player *calPtr = head;

	while (calPtr != nullptr) {
		total += calPtr->getCaloriesBurned();
		calPtr = calPtr->next;
	}

	return total;
}


void PlayerList::getNext() {
	current = current->next;
}


void PlayerList::getPrev() {
	current = current->prev;
}


bool PlayerList::hasNext() {
	return (current->next != nullptr);
}


bool PlayerList::hasPrev() {
	return (current->prev != nullptr);
}


void PlayerList::writeData(std::string outFileName, char remove) {
	std::ofstream outFile;

	// If no names have been removed
	if (remove != 'y') {
		outFile.open(outFileName);
		current = head;

		// Write the header
		outFile << "BASKETBALL TEAM REPORT --- " << getSize() << " PLAYERS FOUND IN FILE" << std::endl
			<< "TOTAL CALORIES BURNED: " << getTotalCaloriesBurned() << std::endl << std::endl
			<< "      " << "PLAYER NAME" << "      " << " :" << "      " << "FF%" << "      " << "      " << "Calories burned" << std::endl
			<< "---------------------------------------------------------------------" << std::endl << std::right;
	}

	// If names have been removed
	if (remove == 'y') {
		outFile.open(outFileName, std::ios_base::app);
		current = last;

		// Write after removal header
		outFile << std::endl << "The list after removals contains " << size << " entries" << std::endl << "They are in Reverse Order:" << std::endl << std::endl;
	}

	// Write Player Data
	while (current != nullptr) {
		outFile << std::setw(30) << current->getLastName() << ", " << current->getFirstName() << " :"
			<< std::setw(15) << current->getFenwick()
			<< std::setw(20) << current->getCaloriesBurned() << std::endl;

		if (remove == 'y') {
			getPrev();
		}
		else {
			getNext();
		}
	}
	outFile.close();
}


// Function to Read the data from input file
void PlayerList::getPlayers(std::string inFileName) {
	std::ifstream inputFile;
	std::string line; // contains the data of the read line
	std::string firstName, lastName; // variables for first and last name of player
	int statsArr[7]; // array to pass the stats to player obj
	int lineNum = 0;

	inputFile.open(inFileName);
	while (!inputFile.eof()) { // while not at end of file
		std::getline(inputFile, line); // read a line from the file and store it in the line variable
		lineNum++; // get the number of players in the folder by counting lines
	}
	
	// Return to beginning of file
	inputFile.close();
	inputFile.open(inFileName);

	//PlayerList player = PlayerList();
	while (!inputFile.eof()) { // while not at end of file
		// save names to name variables
		inputFile >> firstName;
		inputFile >> lastName;

		// save stats to array
		for (int i = 0; i < 7; i++) {
			inputFile >> statsArr[i];
		}

		// pass the data read from the file into a player obj and add it to the playerlist
		Player *newPlayer = new Player(firstName, lastName, statsArr);
		addPlayer(newPlayer);
	}
}