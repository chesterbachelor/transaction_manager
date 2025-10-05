#pragma once
#include <vector>
#include "transaction.h"

namespace Printer {
	void print_menu();
	void print_all_transactions(std::vector<Transaction>&);
	void print_transaction(const Transaction&);
}