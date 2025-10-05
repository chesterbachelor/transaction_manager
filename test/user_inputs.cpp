#include "user_inputs.h"
#include <string>
#include <iostream>
using namespace std;

int UserInput::get_int_from_user() {
	string value;
	while (true) {
		cin >> value;
		try {
			return stoi(value);
		}
		catch (invalid_argument) {
			cout << "Invalid input! Please enter a number.\n";
		}
	}
}

double UserInput::get_transaction_amount_from_user() {
	string value;
	while (true) {
		cout << "Provide amount: ";
		cin >> value;
		try {
			return stod(value);
		}
		catch (invalid_argument) {
			cout << "Invalid input! Please enter a number.\n";
		}
	}
}
