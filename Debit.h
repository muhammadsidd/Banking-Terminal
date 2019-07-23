#ifndef DEBIT_H
#define DEBIT_H
#include "BankAccount.h"
#include <string>
#include <iomanip>
#include "Credit.h"

class Debit : public BankAccount {
private:
	

public: 
	double withdraw_amount;
	double deposit_amount;
	double temporary;
	double money;
	double buff;
	void operator+ (Debit &obj);
	void operator- (Debit &obj);
	void setTemporary(double payment);
	void printAccountDetails()	override final;
};


#endif DEBIT_H

