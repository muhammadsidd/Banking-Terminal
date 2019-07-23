#include "BankAccount.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include<iomanip>

using namespace std;

int BankAccount::numberOfAccounts = 15;

void BankAccount::setFirstName(string name1) {
	firstName = name1;
}
void BankAccount::setLastName(string name2) {
	LastName = name2;
}
void BankAccount::setAccountNumber(string acct) {
	AccountNumber = acct;
}
void BankAccount::setcAmount(double amnt) {
	credamount = amnt;
}
void BankAccount::setdAmount(double amnt_) {
	debtamount = amnt_;
}
std::string BankAccount::getFirst() {
	return firstName;
}
std::string BankAccount::getLast() {
	return LastName;
}
std::string BankAccount::getAccount() {
	return AccountNumber;
}
double BankAccount::getAmount() {
	return debtamount;
}
double BankAccount::getcAmount() {
	return credamount;
}
void BankAccount::update() {
	numberOfAccounts++;
}
void BankAccount::printAccountDetails() {
	cout << setw(10) << firstName << setw(20) << LastName << setw(20) << AccountNumber << setw(20) << credamount<< setw(20) << debtamount << setw(10) << endl;
}