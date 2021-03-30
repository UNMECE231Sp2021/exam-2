#include "library_utils.hpp"

void welcome_message() {
	std::cout << "Welcome to the MiniLibrary\n";
	std::cout << "We have a selection of 9 books\n";
	std::cout << "\t3 novels\n";
	std::cout << "\t3 poems\n";
	std::cout << "\t3 comics\n";
}

void print_options() {
	std::cout << "Please select from the following:\n";
	std::cout << "1. View inventory\n";
	std::cout << "2. Print titles\n";
	std::cout << "Other: Exit\n";
}

// Prints the options above, then '>>', then reads the input with std::cin
int read_input() {
	int temp_input;
	print_options();
	std::cout << ">>";
	std::cin >> temp_input;
	return temp_input;
}

// Pretty much only returns true if x is either 1 or 2
// The two cases back-to-back mean that if either one is true they will
//	do the same thing
bool validate_input(int x) {
	bool binput = false;
	switch(x) {
		case 1:
		case 2:
			binput = true;
			break;
		default:
			break;
	}
	return binput;
}
