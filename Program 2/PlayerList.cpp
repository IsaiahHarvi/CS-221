#include "PlayerList.h"
#include "Player.h"
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
	// Adding the head node
	if (size == 0) {
		head = player; 
		current = head;
		last = head;
		size++;

		return;
	}
	
	Player *currentPlayer = head;
	for (int i = 0; i < size; i++) {
		if ((player->getLastName() + player->getFirstName()) < (currentPlayer->getLastName() + currentPlayer->getFirstName())) { // if a < b add n so: a < n < b
			// If we are at the first node
			if (currentPlayer->prev == nullptr) {
				player->next = currentPlayer;	 // pointing our new head forwards to the old head
				currentPlayer->prev = player;	 // pointing back to the new head
				head = player;					 // updating head
			}

			else {
				// If we are in a middle node
				player->prev = currentPlayer->prev; // pointing player's previous to the same node it is replacing previous 
				currentPlayer->prev->next = player; // pointing the previous node to player
				player->next = currentPlayer;		// pointing player to the node it just inserted before
				currentPlayer->prev = player;		// pointing the +1 index node back to player
			}
			size++;

			return;
		}
		currentPlayer = currentPlayer->next;
	}
	
	// If we are at the last node
	player->prev = last; 
	last->next = player;
	last = player;
	size++;
}


bool PlayerList::removePlayer(std::string firstName, std::string lastName) {
	Player *toRemove = head;

	while (true) { // Will return true if player is removed, false if player is not removed.
		// If the player specified is not in the list
		if (toRemove == nullptr) {
			return false;
		}

		// If the player is in the list
		if ((toRemove->getFirstName() + toRemove->getLastName()) == (firstName + lastName)) { 
			// If the player is the head node
			if (toRemove->prev == nullptr) {
				head = toRemove->next;
				toRemove->next->prev = nullptr;

				size--;
				delete toRemove;
				return true;
			}

			// If the player between first or last
			if (toRemove->next != nullptr) {
				toRemove->next->prev = toRemove->prev;
				toRemove->prev->next = toRemove->next;

				size--;
				delete toRemove;
				return true;
			}

			// If the player is the last node
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
	size = 0; // list is now of size 0
	Player *del = nullptr; 
	while (head != nullptr) {
		del = head;
		head = head->next; // our new head is the next index
		delete del;		   // delete the previous head
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
		current = head; // start at beginning of list

		// Write the header
		outFile << "BASKETBALL TEAM REPORT --- " << getSize() << " PLAYERS FOUND IN FILE" << std::endl
				<< "TOTAL CALORIES BURNED: " << getTotalCaloriesBurned() << std::endl << std::endl
				<< "      " << "PLAYER NAME" << "      " << " :" << "      " << "FF%" << "      " << "      " << "Calories burned" << std::endl
				<< "---------------------------------------------------------------------" << std::endl << std::right;
	}

	// If names have been removed
	if (remove == 'y') {
		outFile.open(outFileName, std::ios_base::app);
		current = last; // start at the end of the list

		// Write after removal header
		outFile << std::endl << "The list after removals contains " << size << " entries" << std::endl << "They are in Reverse Order:" << std::endl << std::endl;
	}

	// Write Player Data
	while (current != nullptr) {
		outFile << std::setw(30) << current->getLastName() << ", " << current->getFirstName() << " :"
				<< std::setw(15) << current->getFenwick()
				<< std::setw(20) << current->getCaloriesBurned() << std::endl;

		if (remove == 'y') {
			getPrev(); // if names have been removed we are at the end of the list and need to traverse backwards
		}else {
			getNext(); // if names have not been removed we are at the beginning of the list and need to traverse forwards
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