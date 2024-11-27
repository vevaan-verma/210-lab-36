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

		string code; // create string to store code

		switch (choice) {// switch on choice

		case 1: // add record

			cout << "Enter the code to add: "; // prompt user to enter code
			cin >> code; // read code from user

			tree.insertNode(code); // insert code into tree
			break;

		case 2: // delete record

			cout << "Enter the code to delete: "; // prompt user to enter code
			cin >> code; // read code from user

			// this can be used to give user feedback if the code is not found
			if (!tree.searchNode(code)) { // if code is not found

				cout << "Code not found." << endl; // output message
				break;

			}

			tree.remove(code); // remove code from tree
			break;

		case 3: // search record

			cout << "Enter the code to search: "; // prompt user to enter code
			cin >> code; // read code from user

			if (tree.searchNode(code)) // if code is found
				cout << "Code found." << endl; // output message
			else // if code is not found
				cout << "Code not found." << endl; // output message

			break;

		case 4: // modify record

			cout << "Enter the code to modify: "; // prompt user to enter code
			cin >> code; // read code from user

			// this can be used to give user feedback if the code is not found
			if (!tree.searchNode(code)) { // if code is not found

				cout << "Code not found." << endl; // output message
				break;

			}

			tree.remove(code); // remove code from tree

			cout << "Enter the new code: "; // prompt user to enter new code
			cin >> code; // read code from user

			tree.insertNode(code); // insert code into tree
			break;

		}

		choice = getMenuChoice(); // get new choice from user

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