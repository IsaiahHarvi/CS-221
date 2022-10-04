#include "PlayerList.h"
#include <iostream>

PlayerList::PlayerList(int sizeOfArray) {
	readSize = 0;
	playerArr = new Player[sizeOfArray];
}


void PlayerList::add(Player playerToAdd) {
	for (int i = 0; i < arrSize; i++) {
		if (playerToAdd.getLastName()[0] < playerArr[i].getLastName()[0]) {
			for (int j = arrSize - 1; j >= i; j--) {
				playerArr[j] = playerArr[j - 1];
			}
			playerArr[i] = playerToAdd;
			readSize++;
			break;
		}
	}
}


bool PlayerList::hasNext() {
	if (index < arrSize) {
		return true;
	}

	return false;
}


Player PlayerList::getNext() {
	return playerArr[index++];

}


void PlayerList::clear() {
	readSize = 0;
	delete playerArr;
}


bool PlayerList::isEmpty() {
	return readSize;
}


int PlayerList::getSize() {
	return arrSize;
}


double PlayerList::totalCalBurned() {
	double totalCalories = 0;

	for (int i = 0; i < arrSize; i++) {
		totalCalories += playerArr[i].getCaloriesBurned();
	}

	return totalCalories;
}