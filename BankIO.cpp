#include "Credit.h"
#include "Debit.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "BankIO.h"
using namespace std;

int BankIO::totalaccounts = 0;

void BankIO::filereader(string filename_) {
	filename = filename_;
}
vector<Credit>BankIO::loadCredit() {
	string line;			//variable to hold the lines of the file  (account details)
	vector<Credit> credits;
	Credit credit;
	ifstream input_file(filename);
	if (input_file) {

		while (getline(input_file, line)) { //read file line by line and add it to the account vector 
			stringstream ss(line);
			getline(ss, first, '\t');
			ss  >> last
				>> acct
				>> credam
				>> debtam;
			credit.setFirstName(first);
			credit.setLastName(last);
			credit.setAccountNumber(acct);
			credit.setcAmount(credam);
			credit.setdAmount(debtam);

			credits.push_back(credit);
		}
		input_file.close();				//save file 

		return credits;				//return the credit vector 

	}
	else {
		throw runtime_error("unable to openfile: " + filename);			//run time error if fail to open file 
	}
}
vector<Debit> BankIO::loadDebit() {
	string line;			
	vector<Debit> debits;
	Debit debit;
	ifstream input_file(filename);
	if (input_file) {

		while (getline(input_file, line)) { 
			stringstream ss(line);
			getline(ss, first, '\t');
			ss  >> last
				>> acct
				>> credam
				>> debtam;
			debit.setFirstName(first);
			debit.setLastName(last);
			debit.setAccountNumber(acct);
			debit.setcAmount(credam);
			debit.setdAmount(debtam);

			debits.push_back(debit);
		}
		input_file.close();				//save file 

		return debits;				//return the vector 

	}
	else {
		throw runtime_error("unable to openfile: " + filename);			//run time error if fail to open file 
	}
}
vector<BankAccount> BankIO::loadAccounts() {
	string line;			
	vector<BankAccount> Accounts;
	BankAccount account;
	ifstream input_file(filename);
	if (input_file) {

		while (getline(input_file, line)) { 
			stringstream ss(line);
			getline(ss, first, '\t');
			ss  >> last
				>> acct
				>> credam
				>> debtam;
			account.setFirstName(first);
			account.setLastName(last);
			account.setAccountNumber(acct);
			account.setdAmount(debtam);
			account.setcAmount(credam);
			Accounts.push_back(account);
			totalaccounts++;
		}
		input_file.close();				

		return Accounts;				

	}
	else {
		throw runtime_error("unable to openfile: " + filename);			//run time error if fail to open file 
	}
	
}



