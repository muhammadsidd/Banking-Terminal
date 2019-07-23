#include"BankAccount.h"
#include"BankIO.h"
#include"Credit.h"
#include"Debit.h"
#include<vector>
#include<string>
#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	string first;
	string last;
	string newaccount;
	string accountno;
	int positive;
	double negative;
	double newamount;
	double payment;
	int found=0;
	vector <Debit> debit;					//SUBCLASS INHERITING FROM PARENT
	vector <Credit> cred;					//SUBCLASS INHERITING FROM PARENT
	vector <BankAccount> accounts;			//PARENT CLASS
	char terminate='y';
	BankIO bank;
	bank.filereader("Text.txt");
	debit = bank.loadDebit();
	cred = bank.loadCredit();
	accounts = bank.loadAccounts();
	char command;
	double withdraw = 0;
	string acctno;
	cout << "******************************STATE BANK OF USF*********************************" << endl;
	cout << "\nClient Account List\n" << endl;
	cout << setw(10) << "firstName" << setw(20) << "LastName" << setw(20) << "AccountNumber" << setw(20) << "credit Balance" << setw(20) << "Debit Amount" << setw(10) << endl;
	for (BankAccount d : accounts) {
		d.printAccountDetails();			//ORIGINAL GET DETAILS FUNTION OF PARENT CLASS
	}

	do {
		cout<< "\nPress w to withdraw from the debit account\n"
			<< "press d to deposit to the debit account\n"
			<< "press p to pay credit bill from debit account\n"
			<< "press a to add client to the STATE BANK OF USF\n" 
			<< "press x to exit" << endl<<endl;

		cin >> command;
		cout << endl;
		switch (command)
		{ 
		case 'w':
			
			cout << "Enter the Client account number: ";
			cin >> accountno;
			
			for (int i = 0; i < debit.size(); ++i) {
				if (accountno == debit[i].AccountNumber) {
					found = 1;
					debit[i].printAccountDetails();
					cout << "Enter the amount to withdraw: ";
					cin >> withdraw;

					Debit bro;
					bro.debtamount = withdraw;
					debit[i] - bro;						//OVERLOADING - OPERATOR AS WITHDRAW
					cout << "\nAmount wihtdrawn: " << debit[i].withdraw_amount << endl;
					debit[i].printAccountDetails();		//POLYMOSPHISM USED TO GET DEATILS ONLY FOR DEBIT
					accounts[i].debtamount = debit[i].debtamount;
				}
			}
			if (found == 0) {
				cout << "ACCOUNT NUMBER NOT FOUND!"<<endl;
				break;
			}
			found = 0;
			break;

		case 'd':
			cout << "Enter the Client account number: ";
			cin >> accountno;
			for (int i = 0; i < debit.size(); ++i) {
				if (accountno == debit[i].AccountNumber) {
					found = 1;
					debit[i].printAccountDetails();
					cout << "Enter the amount to Deposit: ";
					cin >> withdraw;

					Debit bro;
					bro.debtamount = withdraw;
					debit[i] + bro;					//OVERLOADING + OPERATOR TO USE AS DEPOSIT
					cout << "\nAmount deposited: " << debit[i].deposit_amount << endl;
					debit[i].printAccountDetails();	//POLYMOSPHISM USED TO GET DEATILS ONLY FOR DEBIT
					accounts[i].debtamount = debit[i].debtamount;
				}
			}
			if (found == 0) {
				cout << "ACCOUNT NUMBER NOT FOUND!" << endl;
				break;
			}
			found = 0;
			break;

		case 'p':
			cout << "Enter the Client account number: ";
			cin >> accountno;
			for (int i = 0; i < debit.size(); ++i) {
				if (accountno == debit[i].AccountNumber) {
					found = 1;
					debit[i].printAccountDetails();
					
					for (int j = 0; j < cred.size();++j) {

						if (accountno == cred[j].AccountNumber) {
							cout << "\nYour Balance from Last Statement: ";
							cout<<cred[j].getcAmount();
							cout << "\nEnter the payment amount:  ";
							cin >> payment;
							debit[i].setTemporary(payment);
							cout << "\nCURRENT BALANCE FOR CLIENT:  "<<endl;
							cred[j].printAccountDetails();					//POLYMOSPHISM USED TO GET DEATILS ONLY FOR DEBIT
							
							payBillFromDebit(cred[j], debit[i]);			//Friend Function Used To pay the bill from Debit account
							cout << "\nPAYING BILL PLEASE WAIT: " << endl;
							cred[j].printAccountDetails();					//POLYMOSPHISM USED TO GET DEATILS ONLY FOR CREDIT
							accounts[j].credamount = cred[j].credamount;	
							accounts[i].debtamount = debit[i].debtamount;
							cout << endl;
						}
					}

				}
			}
			
			if (found == 0) {
				cout << "ACCOUNT NUMBER NOT FOUND!" << endl;
				break;
			}
			break;
		
		case 'a':
			BankAccount person;
			cout << "enter the First name: ";
			cin >> person.firstName;
			cout << "\nenter the last name: ";
			cin >> person.LastName;
			//cout << "\nenter the account number: ";
			//cin >> person.AccountNumber;
			positive = accounts.size() + 1;
			person.setAccountNumber(to_string(positive));
			cout << "\nenter credit amount owed: ";
			cin >> person.credamount;
			cout << "\nenter debit amount: ";
			cin >> person.debtamount;
			
			accounts.push_back(person);
			
			ofstream fout;
			fout.open("Text.txt", ios::app);			//NEW USER IS BEING APPENDED TO ALREADY EXISTING FILE 
			fout << "\n"
				 << person.firstName <<"\t" 
				 << person.LastName <<"\t" 
				 << person.AccountNumber <<"\t" 
				 << person.credamount <<"\t" 
				 << person.debtamount;
			

			break;

		}
		
		if (command == 'x') {
			cout << "prinitng updated list: \n";
			for (BankAccount b : accounts) {
				b.printAccountDetails();
			}
			cout << "\nTotal Number of Accounts in USF STATE BANK: " << BankIO::totalaccounts << endl; //Getting Total Account as Static Member

			cout << "signing out" << endl;
			break;
		}

	} while (tolower(terminate) == 'y');


	system("pause");
	return 0;
}
