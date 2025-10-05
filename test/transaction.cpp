#include <string>
#include <iostream>
#include <vector>
#include "transaction.h"

Transaction Transaction::from_line(std::string line, char delimiter){
	std::vector<std::string> parts;
	std::string current;

	for (char c : line) {
		if (c == delimiter) {
			parts.push_back(current);
			current.clear();
		}
		else {
			current.push_back(c);
		}
	}

	parts.push_back(current);
	Transaction t{ std::stoi(parts[0]), std::stod(parts[1]), parts[2], parts[3]};
	return t;
}