#include "BST.h"
#include "Player.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

// Default Constructor
BST::BST() {
	val = nullptr;
	left = nullptr;
	right = nullptr;
}


// Alternative Constructor
BST::BST(Player *player) {
	val = player;
	left = nullptr;
	right = nullptr;
}


// Destructor
BST::~BST() {
	clear();
}


// Add player to the tree
void BST::addPlayer(BST *current, Player *player) {
	// Empty Tree
	if (current->val == nullptr) {
		current->val = player;
		return;
	}
	
	// To left
	if ((player->getLastName() + player->getFirstName()) < (current->val->getLastName() + current->val->getFirstName())) {
		if (current->left != nullptr) { // If left node exists
			addPlayer(current->left, player); // Go further left
		}
		
		else {
			current->left = new BST(player); // Create new node
		}
	}

	// To right
	if ((player->getLastName() + player->getFirstName()) > (current->val->getLastName() + current->val->getFirstName())) {
		if (current->right != nullptr) { // If right node exists
			addPlayer(current->right, player); // Go further right
		}

		else {
			current->right = new BST(player); // Create new node
		}
	}

}


// Delete all nodes
void BST::clear() {
	delete left;
	delete right;
}


// Recursively count all nodes
int BST::count(BST* current) {
	// Empty
	if (current == nullptr) {
		return 0;
	}
	
	int leftCount = count(current->left);
	int rightCount = count(current->right);
	
	return leftCount + rightCount + 1;
}


// Sum all player's calories burned
double BST::getTotalCaloriesBurned(double sum, BST *current) {
	if (current == nullptr) {
		return 0;
	}
	
	// Add calories to total
	sum = current->val->getCaloriesBurned();

	// Left
	if (current->left != nullptr) {
		sum += getTotalCaloriesBurned(sum, current->left);
	}
	
	// Right
	if (current->right != nullptr) {
		sum += getTotalCaloriesBurned(sum, current->right);
	}

	return sum;
}


// Print to console in reverse order
void BST::printTree(BST *current) {
	// Empty
	if (current == nullptr) {
		return;
	}
	
	// Right First to prints in descending order
	if (current->right != nullptr) {
		printTree(current->right);
	}

	// Print
	std::cout << std::right << std::setw(20) << current->val->getLastName() << ", "
		<< std::left << std::setw(10) << current->val->getFirstName() << " : "
		<< std::right << std::setw(5) << current->val->getFenwick()
		<< std::setw(10) << current->val->getCaloriesBurned() << std::endl;

	// Left Second
	if (current->left != nullptr) {
		printTree(current->left);
	}
}

	
// Write the header and call writePlayer
void BST::writeFile(BST* root, std::string outFileName) {
	std::ofstream outFile;
	BST *current = root; // May be redundant.

	outFile.open(outFileName);
	
	// Write the header
	outFile << "HOCKEY TEAM REPORT --- " << count(current) << " PLAYERS FOUND IN FILE" << std::endl
		<< "TOTAL CALORIES BURNED: " << getTotalCaloriesBurned(0, current) << std::endl << std::endl
		<< "      " << "PLAYER NAME" << "      " << " :" << "      " << "FF%" << "      " << "      " << "Calories burned" << std::endl
		<< "---------------------------------------------------------------------" << std::endl << std::right;

	// Write the players
	writePlayer(current, outFile);
	
	outFile.close();
}


// Write the players to the file 
void BST::writePlayer(BST *current, std::ostream &outFile) {
	// Empty
	if (current == nullptr) {
		return;
	}

	// Left
	if (current->left != nullptr) {
		writePlayer(current->left, outFile); // Go further left
	}

	// Write to the file: lastName, firstName, fenwick, caloriesBurned
	outFile << std::right << std::setw(20) << current->val->getLastName() << ", "
		<< std::left << std::setw(10) << current->val->getFirstName() << " : "
		<< std::right << std::setw(5) << current->val->getFenwick()
		<< std::setw(10) << current->val->getCaloriesBurned() << std::endl;

	// Right
	if (current->right != nullptr) {
		writePlayer(current->right, outFile); // Go further right
	}
}


// Function to Read the data from input file
void BST::getPlayers(BST *root, std::string inFileName) {
	std::ifstream inputFile;
	std::string firstName, lastName; // Player's name
	int statsArr[7];                 // Player's stats

	inputFile.open(inFileName);

	// Get data for player object
	while (!inputFile.eof()) { // While not at end of file
		inputFile >> firstName;
		inputFile >> lastName;

		// Save stats to the array
		for (int i = 0; i < 7; i++) {
			inputFile >> statsArr[i];
		}

		// Pass the data read from the file into a player obj and add it to the tree
		root->addPlayer(root, new Player(firstName, lastName, statsArr));
	}

	inputFile.close(); 
}
