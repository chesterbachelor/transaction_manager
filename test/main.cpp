#include "transaction.h"
#include "printer.h"
#include "transactions_handler.h"
#include "user_inputs.h"
#include "file_handler.h"
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Filename is required to start program";
		return -1;
	}
	string filename = argv[1];
	bool cont = true;
	std::vector<Transaction> transactions = FileHandler::get_current_transactions(filename);
	int current_id = TransactionsHandler::get_next_id(transactions);
	while (cont) {
		Printer::print_menu();
		cout << "Please choose option: ";
		int value = UserInput::get_int_from_user();

		switch (value) {
		case 1:
			Printer::print_all_transactions(transactions);
			break;
		case 2:
			TransactionsHandler::add_transaction_to_list(transactions, current_id);
			current_id++;
			cout << "Transaction added \n";
			break;
		case 3:
			cout << "Not created yet \n";
			break;
		case 4:
			FileHandler::save_transactions(transactions, filename);
			cont = false;
			break;
		case 5:
			cont = false;
			break;
		default:
			cout << "Da fq y want \n";
		}
	}
	return 0;
}



