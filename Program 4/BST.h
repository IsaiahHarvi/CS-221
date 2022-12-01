#pragma once
#include "Player.h"


class BST {
private:
	Player *val;
	BST *left;
	BST *right;

public:
	BST();
	~BST();
	BST(Player *player);
	void addPlayer(BST *current, Player *player);
	double getTotalCaloriesBurned(double sum, BST *current);
	int count(BST *current);
	void clear();
	void printTree(BST *current);
	void writeFile(BST* root, std::string outFileName);
	void writePlayer(BST *current, std::ostream &outFile);
	void getPlayers(BST* root, std::string inFileName);
};