#pragma once
#include "Player.h"

class PlayerList {
private:
	int readSize; // amount of players read
	int arrSize; // length of the playerList
	int index;
	Player *playerArr; // playerList

public:
	PlayerList(int sizeOfArray);
	void add(Player playerToAdd);
	void clear();
	bool isEmpty();
	int getSize();
	double totalCalBurned();
	bool hasNext();
	Player getNext();
};