// Isaiah Harville
// 12/1/22 | Visual Studio 2022
// Program 4.cpp : This program calculates Advanced Statistics For a Hockey Player. The program will read from an input data file and will perform a series of calculations.
//               : It will then output the calculations in a specified output file.
//				 : Program 4 is similar to Program 3 except it utilizes a BST rather than a doubly linked list.

#include "BST.h"
#include <iostream>


int main() {
	// Root of BST
	BST *tree = new BST();
	
	// File Names
	std::string iFileName;
	std::string oFileName;

	// Prompt
	std::cout << "Welcome to the hockey player statistics calculator test program."
		<< std::endl << "I am going to read players from an input data file. You will tell me the names of your input and output files."
		<< std::endl << "I will store all of the players in a list, compute player's and then write the resulting team report to your output file." << std::endl;

	// Store File Names
	std::cout << "Enter the name of your input file: ";
	std::cin >> iFileName;
	std::cout << "Enter the name of your output file: ";	
	std::cin >> oFileName;

	// Read
	std::cout << std::endl << "Reading Players from: " << iFileName << std::endl;
	tree->getPlayers(tree, iFileName);
	
	// Print Players to Console (in reverse)
	tree->printTree(tree);
	
	// Write
	tree->writeFile(tree, oFileName);
	
	// Destruct Tree
	delete tree;

	// End
	std::cout << std::endl << "\nWrote Players to: " << oFileName << std::endl;
	std::cout << std::endl << "\n\nEnd of Program 3" << std::endl;

	return 1;
}