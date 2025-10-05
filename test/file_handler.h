#pragma once
#include "transaction.h"
#include <string>
#include <vector>

namespace FileHandler {
	std::vector<Transaction> get_current_transactions(const std::string&);
	void save_transactions(const std::vector<Transaction>&, const std::string&);
}