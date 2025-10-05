#include "printer.h"
#include <iostream>
#include <vector>

using namespace std;

void Printer::print_menu() {
	cout << "1: Get current transactions \n";
	cout << "2: Add transaction \n";
	cout << "3: Delete transaction \n";
	cout << "4: Save transactions and exit \n";
	cout << "5: Exit without save \n";
}

void Printer::print_all_transactions(vector<Transaction>& transactions) {
	cout << "Amount             |  Category                 |  Description    " << '\n';

	for (const Transaction& t : transactions) {
		cout << t.amount << "        " << t.category << "            " << t.description << '\n';
	}
}


void Printer::print_transaction(const Transaction& trans) {
	std::cout << "Transaction amount: " << trans.amount << ". Category of purchase: " << trans.category
		<< ". Description: " << trans.description << '\n';
}