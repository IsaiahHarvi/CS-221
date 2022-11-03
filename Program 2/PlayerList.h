#pragma once
#include "Player.h"


class PlayerList {
private:
	Player *head;
	Player *last;
	Player *current;
	int size;


public:
	PlayerList();
	void addPlayer(Player *player);
	bool removePlayer(std::string firstName, std::string lastName);
	double getTotalCaloriesBurned();
	bool isEmpty();
	int getSize();
	void clear();
	bool hasNext();
	bool hasPrev();
	void getNext();
	void getPrev();
	void writeData(std::string outFileName, char remove);
	void getPlayers(std::string inFileName);
};