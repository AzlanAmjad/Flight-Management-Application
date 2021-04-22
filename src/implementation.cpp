
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

flight::flight(string file_name) {
	ifstream in_stream(file_name);
	if (in_stream.fail()) {
		cout << "An error occured while opening flight info file... Program will now end" << endl;
		in_stream.clear();
		exit(1);
	}
	in_stream >> flight_number >> row >> col;
	int i = 0;
	string temp;
	while (!in_stream.eof()) {
		getline(in_stream, temp);
		i++;
	}
	in_stream.clear();
	num_of_pass = i - 2;
	passengers = vector<passenger> (num_of_pass);
	in_stream.seekg(0, ios::beg);
	getline(in_stream, temp);
	string fname;
	string lname;
	string phone;
	string seat_label;
	string ID;
	string line;
	for(int j = 0; j < num_of_pass; j++) {
		in_stream >> fname >> lname >> phone >> seat_label >> ID;
		passengers[j].set_first_name(fname);
		passengers[j].set_last_name(lname);
		passengers[j].set_phone_number(phone);
		passengers[j].set_passenger_seat(seat_label);
		passengers[j].set_ID_number(ID);
	}
	in_stream.close();
}
void flight::set_flight_number(string a) {
	flight_number = a;
}
void flight::set_row(int a) {
	row = a;
}
void flight::set_col(int a) {
	col = a;
}
string flight::get_flight_number()const {
	return flight_number;
}
int flight::get_row()const {
	return row;
}
int flight::get_col()const {
	return col;
}

void flight::show_seat_map() {
	cout << "\nAircraft Seat Map\n\n";
	char label = 'A';
	int label_size;
	int p_row;
	int p_col;
	int n;
	cout << "     ";
	for (int i = 0; i < col; i++) {
		cout << left << setw(4) << label;
		label++;
	}
	for (int j = 0; j < row; j++) {
		cout << "\n";
		cout << setw(3) << " ";
		for (int k = 0; k < col; k++) {
			cout << left << "+---";
		}
		cout << "+\n";
		cout << left << setw(3) << j+1;
		for (int m = 0; m < col; m++) {
			cout << left << "|";
			for (n = 0; n < num_of_pass; n++) {
				label_size = (passengers[n].get_passenger_seat().get_seat_label()).size();
				p_row = stoi(passengers[n].get_passenger_seat().get_seat_label());
				p_col = int(passengers[n].get_passenger_seat().get_seat_label().at(label_size-1) - 'A' + 1);
				if (p_row == j+1 && p_col == m+1) {
					break;
				}
			}
			if (n == num_of_pass) {
				cout << "   ";
			}
			else {
				cout << " " << "X" << " ";
			}
		}
		cout << "|";
	}
	cout << "\n";
	cout << setw(3) << " ";
	for (int l = 0; l < col; l++) {
		cout << "+---";
	}
	cout << "+\n";
}
void flight::display_passengers() {
	int size;
	cout << left << setw(17) << "First Name";
	cout << left << setw(17) << "Last Name";
	cout << left << setw(20) << "Phone";
	cout << left << setw(8) << "Row";
	cout << left << setw(8) << "Seat";
	cout << left << setw(12) << "ID";
	cout << setw(78) << "\n-----------------------------------------------------------------------------\n";
	for (int i = 0; i < num_of_pass; i++) {
		size = (passengers[i].get_passenger_seat().get_seat_label()).size();
		cout << left << setw(17) << passengers[i].get_first_name();
		cout << left << setw(17) << passengers[i].get_last_name();
		cout << left << setw(20) << passengers[i].get_phone_number();
		cout << left << setw(8) << stoi(passengers[i].get_passenger_seat().get_seat_label());
		cout << left << setw(8) << passengers[i].get_passenger_seat().get_seat_label().at(size-1);
		cout << left << setw (12) << passengers[i].get_ID_number();
		cout << setw(78) << "\n-----------------------------------------------------------------------------\n";
	}
}
void flight::add_passenger() {
	string fname, lname, phone, ID, p_row, p_col, seat_label;
	bool error = false;
	cout << "Please enter the passenger ID number (xxxxx)\n";
	cin >> ID;
	cout << "Please enter the passenger first name\n";
	cin >> fname;
	cout << "Please enter the passenger last name\n";
	cin >> lname;
	cout << "Please enter the passenger phone number (xxx-xxx-xxxx)\n";
	cin >> phone;
	cout << "\nPlease enter the passenger's desired row\n";
	cin >> p_row;
	cout << "Please enter the passenger's desired seat\n";
	cin >> p_col;
	
	//FIRST NAME ERROR CHECK
	if (fname.size() > 17) {
		cout << "\nFirst Name ERROR: first name was too long\n";
		error = true;
	}
	int j;
	for (j = 0; j < fname.size(); j++) {
		if (fname.at(j) < 'A' || fname.at(j) > 'Z') {
			if (fname.at(j) < 'a' || fname.at(j) > 'z') {
				break;
			}
		}
	}
	if (j != fname.size()) {
		cout << "\nFirst Name ERROR: first name contains innapropriate characters\n";
		error = true;
	}
	
	//LAST NAME ERROR CHECK
	if (lname.size() > 17) {
		cout << "\nLast Name ERROR: last name was too long\n";
		error = true;
	}
	int k;
	for (k = 0; k < lname.size(); k++) {
		if (lname.at(k) < 'A' || lname.at(k) > 'Z') {
			if (lname.at(k) < 'a' || lname.at(k) > 'z') {
				break;
			}
		}
	}
	if (k != lname.size()) {
		cout << "\nLast Name ERROR: last name contains innapropriate characters\n";
		error = true;
	}
	
	//ID NUMBER ERROR CHECK
	if (ID.size() != 5) {
		cout << "\nID Number ERROR: ID was not of appropriate length\n";
		error = true;
	}
	int i;
	for (i = 0; i < ID.size(); i++) {
		if (ID.at(i) < '0' || ID.at(i) > '9') {
			break;
		}
	}
	if (i != ID.size()) {
		cout << "\nID Number ERROR: ID contains inappropriate characters\n";
		error = true;
	}
	int m;
	for (m = 0; m < num_of_pass; m++) {
		if (passengers[m].get_ID_number() == ID) {
			break;
		}
	}
	if (m != num_of_pass) {
		cout << "\nID Number ERROR: ID already exists\n";
		error = true;
	}
	
	//ROW ERROR CHECK
	int p_row_int;
	if (p_row.size() > 2) {
		p_row_int = (p_row.at(0) - '0')*10 + (p_row.at(1) - '0');
	}
	else {
		p_row_int = (p_row.at(0) - '0');
	}
	if (p_row.size() > 2) {
		cout << "\nRow ERROR: row does not exist\n";
		error = true;
	}
	else if (p_row_int < 1 || p_row_int > row )  {
		cout << "\nRow ERROR: row does not exist\n";
		error = true;
	}
	
	//SEAT ERROR CHECK
	int p_col_int = p_col.at(0) - 'A' + 1;
	if (p_col.size() > 1) {
		cout << "\nSeat ERROR: seat does not exist\n";
		error = true;
	}
	else if (p_col.at(0) < 'A' || p_col.at(0) > 'Z') {
		cout << "\nSeat ERROR: seat does not exist\n";
		error = true;
	}
	else if (p_col_int < 1 || p_col_int > col )  {
		cout << "\nSeat ERROR: seat does not exist\n";
		error = true;
	}
	
	//SEAT LABEL ERROR CHECK
	seat_label = p_row+p_col;
	int n;
	for (n = 0; n < num_of_pass; n++) {
		if (passengers[n].get_passenger_seat().get_seat_label() == seat_label) {
			break;
		}
	}
	if (n != num_of_pass) {
		cout << "\nSeat ERROR: seat is already taken\n";
		error = true;
	}
	
	//PHONE NUMBER ERROR CHECK
	int p;
	if (phone.size() != 12) {
		cout << "\nPhone Number ERROR: invalid phone number\n";
		error = true;
	}
	else {
		for (p = 0; p < phone.size(); p++) {
			if ((phone.at(p) < '0' || phone.at(p) > '9') && (phone.at(3) != '-' || phone.at(7) != '-')) {
				break;
			}
		}
		if (p != phone.size()) {
			cout << "\nPhone Number ERROR: invalid phone number\n";
			error = true;
		}
		else if (phone.at(3) != '-' || phone.at(7) != '-') {
			cout << "\nPhone Number ERROR: invalid phone number\n";
			error = true;
		}
	}
	int g;
	for (g = 0; g < num_of_pass; g++) {
		if (passengers[g].get_phone_number() == phone) {
			break;
		}
	}
	if (g != num_of_pass) {
		cout << "\nPhone Number ERROR: phone number is already taken\n";
		error = true;
	}
	
	//CREATE NEW PASSENGER
	if (!error) {
		num_of_pass += 1;
		passengers.resize(num_of_pass);
		passengers[num_of_pass-1].set_first_name(fname);
		passengers[num_of_pass-1].set_last_name(lname);
		passengers[num_of_pass-1].set_phone_number(phone);
		passengers[num_of_pass-1].set_passenger_seat(seat_label);
		passengers[num_of_pass-1].set_ID_number(ID);
		cout << "Passenger has been added.\n";
	}
}
void flight::remove_passenger() {
	string ID;
	int i;
	cout << "Please enter the ID of that passenger that needs to be removed (xxxxx):\n";
	cin >> ID;
	for (i = 0; i < num_of_pass; i++) {
		if (passengers[i].get_ID_number() == ID) {
			passengers.erase(passengers.begin() + i);
			num_of_pass -= 1;
			cout << "Passenger has been removed.\n";
			break;
		}
		else if (i == num_of_pass-1) {
			cout << "ERROR: no passenger with such an ID was found";
			break;
		}
	}
}
void flight::save_data() {
	cout << "Saving data...\n";
	ofstream out_stream("flight_info.txt");
	out_stream << flight_number << " " << row << " " << col << "\n";
	for (int i = 0; i < num_of_pass; i++) {
		out_stream << passengers[i].get_first_name() << " ";
		out_stream << passengers[i].get_last_name() << " ";
		out_stream << passengers[i].get_phone_number() << " ";
		out_stream << passengers[i].get_passenger_seat().get_seat_label() << " ";
		out_stream << passengers[i].get_ID_number() << "\n";
	}
	cout << "Your data has been saved.\n";
	out_stream.close();
}


void passenger::set_first_name(string a) {
	first_name = a;
}
void passenger::set_last_name(string a) {
	last_name = a;
}
void passenger::set_phone_number(string a) {
	phone_number = a;
}
void passenger::set_ID_number(string a) {
	ID_number = a;
}
void passenger::set_passenger_seat(string a) {
	passenger_seat.set_seat_label(a);
}
string passenger::get_first_name()const {
	return first_name;
}
string passenger::get_last_name()const {
	return last_name;
}
string passenger::get_phone_number()const {
	return phone_number;
}
string passenger::get_ID_number()const {
	return ID_number;
}
seat passenger::get_passenger_seat()const {
	return passenger_seat;
}


void seat::set_seat_label(string a) {
	seat_label = a;
}
string seat::get_seat_label()const{
	return seat_label;
}



