#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <iostream>
#include <string>
#include <vector>



class BankAccount {
protected:
	

public:
	std::string firstName;
	std::string LastName;
	std::string AccountNumber;
	static int numberOfAccounts;
	double credamount;
	double debtamount;
	void setFirstName(std::string name1);
	void setLastName(std::string name2);
	void setAccountNumber(std::string acct);
	void setcAmount(double amnt);
	void setdAmount(double amnt);
	void update();
	std::string getFirst();
	std::string getLast();
	std::string getAccount();
	double getAmount();
	double getcAmount();
	virtual void printAccountDetails();
};

#endif BANK_ACCOUNT_H

