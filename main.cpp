// COMSC-210 | Lab 36 | Vevaan Verma
using namespace std;
#include <iostream>
#include <fstream>
#include "StringBinaryTree.h"

/* FUNCTION PROTOTYPES */
int getMenuChoice();
int getValidatedChoice(int min, int max);

/* CONSTANTS */
const string FILE_NAME = "codes.txt"; // file name

/* GLOBAL VARIABLES */
ifstream fin;

// main() is the entry point of the program and drives the program
// arguments: none
// returns: int - the exit code of the program
int main() {

	fin.open(FILE_NAME); // open file

	if (!fin) { // if file does not exist

		cout << "Error: File " << FILE_NAME << " not found." << endl; // output error message
		return 1; // return error code

	}

	StringBinaryTree tree; // create tree

	while (!fin.eof()) { // while not end of file

		string code; // create string to store code
		fin >> code; // read code from file
		tree.insertNode(code); // insert code into tree

	}

	int choice = getMenuChoice();

	while (choice != 5) { // while choice is not to exit

	}

	return 0;

}

// getMenuChoice() displays the menu and gets the user's choice
// arguments: none
// returns: int - the user's choice
int getMenuChoice() {

	cout << "Menu:" << endl;
	cout << "1. Add Record" << endl;
	cout << "2. Delete Record" << endl;
	cout << "3. Search Record" << endl;
	cout << "4. Modify Record" << endl;
	cout << "5. Exit" << endl;

	cout << "Enter your choice: ";
	return getValidatedChoice(1, 5);

}

// getValidatedChoice() gets a validated integer choice from the user (between min and max inclusive)
// arguments: int min - the minimum value, int max - the maximum value
// returns: int - the validated integer choice
int getValidatedChoice(int min, int max) {

	int inputInt; // variable to store the input (of type int)

	while (!(cin >> inputInt) || inputInt < min || inputInt > max) { // while the input is not an integer or is not between the min and max

		cin.clear(); // clear the input stream
		cin.ignore(INT_MAX, '\n'); // ignore the invalid input
		cout << "Invalid input. Please enter a valid integer: "; // prompt the user to enter an integer

	}

	return inputInt;

}