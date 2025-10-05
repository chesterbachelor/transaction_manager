#pragma once
#include <string>
class Transaction {
public:
	int id;
	double amount;
	std::string category;
	std::string description;

	Transaction(int id, double amount, std::string category, std::string description) : 
		id{ id }, amount{ amount }, category{ category }, description{ description } {}
	Transaction() {}
	~Transaction() {}
	static Transaction from_line(std::string, char delimiter);
};