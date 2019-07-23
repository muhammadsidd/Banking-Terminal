#ifndef BANK_IO
#define BANK_IO

#include <fstream>
#include <string>
#include <cstdlib>
#include "Debit.h"
#include "Credit.h"
#include <vector>
#include <iostream>

using namespace std;

class BankIO {
private:
	
public:
	string first;
	string last;
	string acct;
	double credam;
	double debtam;
	string filename;
	void filereader(string filename);
	vector<Credit>loadCredit();
	vector<Debit> loadDebit();
	vector<BankAccount> loadAccounts();
	static int totalaccounts;
	
};
#endif 
