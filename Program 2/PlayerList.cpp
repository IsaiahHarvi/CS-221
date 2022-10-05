#include "PlayerList.h"
#include<string>
#include <iostream>
#include <algorithm>


Playerlist::Playerlist(int size) {
	playerArr = new Player[size];

	maxSize = size;
	currentSize = 0;
	iteratorIndex = 0;
}


bool Playerlist::addPlayer(Player player) {
	if (currentSize == maxSize) {
		return false;
	}

	std::string p1Name = player.getLastName() + player.getFirstName();
	transform(p1Name.begin(), p1Name.end(), p1Name.begin(), std::tolower);
	std::string p2Name;

	for (int i = 0; i < currentSize; i++) {
		p2Name = playerArr[i].getLastName() + playerArr[i].getFirstName();
		transform(p2Name.begin(), p2Name.end(), p2Name.begin(), std::tolower);

		if (p1Name < p2Name) {
			insertPlayer(i, player);
			currentSize++;
			return true;
		}
	}

	insertPlayer(currentSize, player);
	currentSize++;
	return true;
}


void Playerlist::insertPlayer(int index, Player player) {
	for (int i = currentSize; i > index; i--) {
		playerArr[i] = playerArr[i - 1];
	}

	playerArr[index] = player;
}


void Playerlist::clear() {
	currentSize = 0;
	iteratorIndex = 0;
	delete playerArr;
}


bool Playerlist::isEmpty() {
	return (currentSize == 0);
}


int Playerlist::getSize() {
	return currentSize;
}


double Playerlist::getTotalCaloriesBurned() {
	double total = 0;

	for (int i = 0; i < currentSize; i++) {
		total += playerArr[i].getCaloriesBurned();
	}

	return total;
}


Player Playerlist::getNext() {
	Player nextPlayer = playerArr[iteratorIndex];
	iteratorIndex++;
	return nextPlayer;
}


bool Playerlist::hasNext() {
	return (iteratorIndex < currentSize);
}

