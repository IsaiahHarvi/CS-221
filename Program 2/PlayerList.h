#pragma once
#include "Player.h"


class Playerlist {
private:
	Player* playerArr;
	int maxSize;
	int currentSize;
	int iteratorIndex;
	void insertPlayer(int index, Player player);

public:
	Playerlist(int size);
	bool addPlayer(Player player);
	void clear();
	bool isEmpty();
	int getSize();
	double getTotalCaloriesBurned();
	Player getNext();
	bool hasNext();


};