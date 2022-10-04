#pragma once
#include "Player.h"

class PlayerList {
private:
	int readSize;
	int arrSize;
	int index;
	Player *playerArr;

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