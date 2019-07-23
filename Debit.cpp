#include "BankAccount.h"
#include "Debit.h"
#include <string>
#include <iostream>
#include <iomanip>
#include "Credit.h"

using namespace std;


void Debit::operator+ (Debit &obj) {
	deposit_amount = obj.debtamount;
	debtamount = debtamount + obj.debtamount;
	
}
void Debit::operator- (Debit &obj) {
	withdraw_amount = obj.debtamount;
	if (obj.debtamount <= debtamount) {
		debtamount = debtamount - obj.debtamount;
	}
	else {
		cout << "\nERROR! OVERLIMIT! NOT ENOUGH MONEY IN THE ACCOUNT------ \nTRANSACTION DECLINED\nprinting receipt"<<endl;
	}
}
void Debit::setTemporary(double payment_) {
	if (payment_ < debtamount) {
		temporary = payment_;
		debtamount = debtamount - temporary;
		credamount = credamount - temporary;
	}
	else {
		cout << "NOT ENOUGH MONEY TO PAY THE BILL---TRANSACTION DECLINED" << endl;
	}
	
}


void Debit::printAccountDetails() {
	cout <<setw(10)<< getFirst() << setw(20)  << getLast() << setw(20) << getAccount() << setw(20) << getAmount() << setw(10)<< endl;

}