#include "PlayerList.h"


// Constructor
PlayerList::PlayerList(int sizeOfArray) {
	arrSize = sizeOfArray;
	readSize = 0; // # of players added to the array
	index = 0; // position in array
	playerArr = new Player[arrSize];
}


// Insert Player object into PlayerList in an ordered manner
void PlayerList::add(Player playerToAdd) {
	for (int i = 0; i < arrSize; i++) {
		if (playerToAdd.getLastName()[0] < playerArr[i].getLastName()[0]) { // sort by last name
			for (int j = arrSize - 1; j >= i; j--) { // iterate backwards and shift from the insert index
				playerArr[j] = playerArr[j - 1];
			}
			playerArr[i] = playerToAdd; // insert
			readSize++; // read another player
			break;
		}
	}
}


// If the getNext index is not outside the bounds of the array size
bool PlayerList::hasNext() {
	if (index < arrSize) {
		return true;
	}

	return false;
}


// Returns next element in playerArr (playerList)
Player PlayerList::getNext() { 
	return playerArr[index++];
}


// Deletes playerArr
void PlayerList::clear() { 
	readSize = 0; // amount of read players reset
	index = 0; // current position in array reset 
	delete playerArr;
}


// If no players have been read (the array is empty or deleted)
bool PlayerList::isEmpty() { 
	return readSize;
}


// Size of the overall array based on the number of lines in the text file
int PlayerList::getSize() { 
	return arrSize;
}


// Adds up all of the calories from each player in the list
double PlayerList::totalCalBurned() {
	double totalCalories = 0;

	for (int i = 0; i < arrSize; i++) {
		totalCalories += playerArr[i].getCaloriesBurned(); // calculates each players CaloriesBurned and adds it
	}

	return totalCalories; // return sum of all calories
}