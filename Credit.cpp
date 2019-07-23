#include "Credit.h"
#include "BankAccount.h"
#include <string>
#include <iostream>
#include "Debit.h"


using namespace std;



void Credit::setCurrentAmountOwed(double amount_) {
	credamount = amount_;
}
void Credit::setInterestCharged() {
	interest_Charged = credamount * rate;
}
double Credit::getCurrentAmountOwed() {
	return credamount;
}
double Credit::getInterestCharged() {
	return interest_Charged;
}
void payBillFromDebit(Credit& c, Debit& d) {
	if (d.temporary) {
		c.credamount = c.credamount - d.temporary;
	}
	else {
		cout << "SORRY" << endl;
	}
}
void Credit::printAccountDetails() {
	cout << setw(10) << firstName << setw(20) << LastName << setw(20) << AccountNumber << setw(20) << credamount << setw(10) << endl;
}