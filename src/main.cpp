
#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

#include "seat.h"
#include "passenger.h"
#include "flight.h"

void display_header();
/*REQUIREMENTS:
		 * 	- none
		 * PROMISES:
		 * 	- displays program header
		 */
int menu();
/*REQUIREMENTS:
		 * 	- none
		 * PROMISES:
		 * 	- display menu
		 * 	- ask user to choose from menu
		 * 	- return user choice
		 */
void press_enter();
/*REQUIREMENTS:
		 * 	- none
		 * PROMISES:
		 * 	- allows user to continue after pressing enter
		 */

int main() {
	flight f("flight_info.txt");
	int choice;
	display_header();
	press_enter();
	while ((choice = menu())) {
		switch (choice) {
			case 1:
				f.show_seat_map();
				press_enter();
				break;
			case 2:
				f.display_passengers();
				press_enter();
				break;
			case 3:
				f.add_passenger();
				press_enter();
				break;
			case 4:
				f.remove_passenger();
				press_enter();
				break;
			case 5:
				f.save_data();
				press_enter();
				break;
			case 6:
				cout << "Quitting Program..." << endl;
				exit(1);
		}
	}
	return 0;
}


void display_header() {
	cout << "\nVersion:  1.0\n";
	cout << "Term Project - Flight Management Program in C++\n";
	cout << "Produced by: Azlan Amjad\n";
}

int menu() {
	press_enter();
	char choice;
	int value;
	cout << "Please select one of the following options:\n";
	cout << "1. Display Flight Seat Map\n";
	cout << "2. Display Passengers Information\n";
	cout << "3. Add a New Passenger\n";
	cout << "4. Remove an Existing Passenger\n";
	cout << "5. Save Data\n";
	cout << "6. Quit\n";
	cout << "Enter your choice: (1, 2, 3, 4, 5, or 6)";
	cin >> choice;
	while (choice < '0' || choice > '6') {
		cout << "Error: invalid input...\n";
		cout << "Please enter a valid input:\n";
		cin >> choice;
	}
	value = choice - '0';
	return value;
}

void press_enter() {
	cout << "\n<<< Press Return to Continue >>>\n";
	cin.get();
}



