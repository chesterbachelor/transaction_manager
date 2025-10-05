#include "file_handler.h"
#include <vector>
#include <string>
#include "transaction.h"
#include <fstream>
#include <iostream>

char delimiter = '|';
using namespace std;

vector<Transaction> FileHandler::get_current_transactions(const string& path) {
	vector<Transaction> transactions{};

	ifstream in{ path };
	if (in.good()) {

		string line;
		getline(in, line);

		while (getline(in, line)) {
			transactions.push_back(Transaction::from_line(line, delimiter));
		}
	}

	return transactions;
}

void FileHandler::save_transactions(const std::vector<Transaction>& transactions, const std::string& path) {
    ofstream out(path, ios::trunc);
    if (!out.is_open()) {
        cerr << "Could not open file for saving: " << path << "\n";
        return;
    }

    out << "id" << delimiter << "amount" << delimiter << "category" << delimiter << "description" << "\n";

    for (const auto& t : transactions) {
        out << t.id << delimiter
            << t.amount << delimiter
            << t.category << delimiter
            << t.description << "\n";
    }

    cout << "Data saved";
    out.close();
}