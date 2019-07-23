#ifndef CREDIT_H
#define CREDIT_H
#include "BankAccount.h"
#include <string>
#include "Debit.h"

class Debit;
class Credit : public BankAccount {
private:
	
public:
	double AmountOwed;
	double buffer;
	double interest_Charged;
	const double rate = 0.85;
	
	void setCurrentAmountOwed(double amount_);
	void setInterestCharged();
	double getCurrentAmountOwed();
	double getInterestCharged();
	friend void payBillFromDebit(Credit& c, Debit& d);
	double getCurrentAmount();
	void printAccountDetails();
};

#endif CREDIT_H

