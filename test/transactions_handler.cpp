#include "transactions_handler.h"
#include "transaction.h"
#include "user_inputs.h"
#include <vector>
#include <iostream>

using namespace std;

int TransactionsHandler::get_next_id(vector<Transaction>& list) {
	int current_biggest = 0;
	for (Transaction& t : list) {
		if (t.id > current_biggest) {
			current_biggest = t.id;
		}
	}
	return current_biggest + 1;
}

void TransactionsHandler::add_transaction_to_list(vector<Transaction>& transactions, int id) {
	transactions.push_back(create_transaction(id));
}

Transaction TransactionsHandler::create_transaction(int id) {
	Transaction t;
	t.id = id;
	t.amount = UserInput::get_transaction_amount_from_user();
	cout << "Provide category: ";
	cin >> t.category;
	cout << "Provide description: ";
	cin >> t.description;
	cin.clear();
	return t;
}