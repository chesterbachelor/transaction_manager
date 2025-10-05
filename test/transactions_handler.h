#pragma once
#include "transaction.h"
#include <vector>

namespace TransactionsHandler {
	int get_next_id(std::vector<Transaction>&);
	void add_transaction_to_list(std::vector<Transaction>&, int);
	Transaction create_transaction(int);
}