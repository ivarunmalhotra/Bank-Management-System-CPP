/*
	Main file where data file handling and some operations will be done
*/

#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <fstream>
#include "Account.h"
using namespace std;

// declaring some functions
void open_account();
void balance_enquiry(int);
void delete_account(int);
void display_list();
void update_balance(int);
void search_account(int);
void display_all();
void name_add(int, int);
void display_last();
void check_interest(int);

int main()
{
	int choice, acc;

	do
	{
		system("CLS");
		cout.setf(ios::right, ios::adjustfield);
		cout << "\n--------------------------------------\n";
		cout << "\t BANK MANAGEMENT SYSTEM";
		cout << "\n--------------------------------------\n";

		cout << "Which operation do you want to perform?\n";
		cout << "\n\t1. OPEN NEW ACCOUNT";	 //
		cout << "\n\t2. DISPLAY LIST";		 //
		cout << "\n\t3. DELETE ACCOUNT";	 //
		cout << "\n\t4. UPDATE BALANCE";	 //
		cout << "\n\t5. DISPLAY LAST ENTRY"; //
		cout << "\n\t6. SEARCH ACCOUNT";	 //
		cout << "\n\t7. NAME ENQUIRY";		 //
		cout << "\n\t8. ADDRESS ENQUIRY";	 //
		cout << "\n\t9. BALANCE ENQUIRY";	 //
		cout << "\n\t10. DISPLAY ALL DATA";	 //
		cout << "\n\t11. CHECK INTEREST";
		cout << "\n\t12. EXIT"; //

		cout << "\n\nEnter Your Choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("CLS");
			open_account();
			break;

		case 2:
			system("CLS");
			display_list();
			break;

		case 3:
			system("CLS");
			cout << "\n\n\t\tDELETE ACCOUNT\n"
				 << endl;
			cout << "\nEnter The account No. : ";
			cin >> acc;
			delete_account(acc);
			break;

		case 4:
			system("CLS");
			cout << "\n\n\tUPDATE ACCOUNT BALANCE\n"
				 << endl;
			cout << "\nEnter The account No. : ";
			cin >> acc;
			update_balance(acc);
			break;

		case 5:
			system("CLS");
			cout << "\n\n\t\tLAST ENTRY DETAILS\n"
				 << endl;
			display_last();
			break;

		case 6:
			system("CLS");
			cout << "\n\nCHECK AVAILABILITY OF ACCOUNT NUMBER\n"
				 << endl;
			cout << "\nEnter The account No. : ";
			cin >> acc;
			search_account(acc);
			break;

		case 7:
			system("CLS");
			cout << "\n\nRETRIEVE NAME OF THE ACCOUNT HOLDER\n"
				 << endl;
			cout << "\nEnter The account No. : ";
			cin >> acc;
			name_add(acc, 1);
			break;

		case 8:
			system("CLS");
			cout << "\n\nRETRIEVE ADDRESS OF THE ACCOUNT HOLDER\n"
				 << endl;
			cout << "\nEnter The account No. : ";
			cin >> acc;
			name_add(acc, 2);
			break;

		case 9:
			system("CLS");
			cout << "\n\n\t\tCHECK BALANCE\n"
				 << endl;
			cout << "\nEnter The account No. : ";
			cin >> acc;
			balance_enquiry(acc);
			break;

		case 10:
			system("CLS");
			cout << "\n\n\tDISPLAY ALL DETAILS\n"
				 << endl;
			display_all();
			break;

		case 11:
			system("CLS");
			cout << "\n\n\t\tCHECK INTEREST\n"
				 << endl;
			cout << "\nEnter The account No. : ";
			cin >> acc;
			check_interest(acc);
			break;

		case 12:
			// exit
			cout << "\nThank you for using this bank service.\nHave a nice day!\n"
				 << endl;
			break;

		default:
			cout << "\nERROR:Invalid Choice!!";
		}
		cin.ignore();
		if (choice != 12)
		{
			cout << "\nPress enter..";
			cin.get();
		}

	} while (choice != 12);
	return 0;
}

// function to open account and store details in data file
void open_account()
{
	Account ac;
	ofstream writeFile;
	writeFile.open("customer.txt", ios::binary | ios::app);
	ac.OpenAccount();
	writeFile.write(reinterpret_cast<char *>(&ac), sizeof(Account));
	writeFile.close();
}

// function to search account
void search_account(int acc)
{
	Account ac;

	ifstream inFile;
	inFile.open("customer.txt", ios::binary);

	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}

	while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Account)))
	{
		if (ac.SearchAccount(acc))
			cout << "\nAccount already exists" << endl;
		else
			cout << "\nAccount doesn't exists" << endl;
	}

	inFile.close();
}

// display all details
void display_all()
{
	Account ac;

	ifstream inFile;
	inFile.open("customer.txt", ios::binary);

	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}

	while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Account)))
	{
		cout << "Account Number: " << ac.GetAccountNo() << endl;
		ac.ShowAccount();
		ac.PrintAddress();
		ac.PrintLastDate();
		cout << endl;
	}

	inFile.close();
}

// function to display details list
void display_list()
{
	Account ac;

	ifstream inFile;
	inFile.open("customer.txt", ios::binary);

	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}

	cout.setf(ios::left, ios::adjustfield);
	cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout << "-------------------------------------------------";
	cout << endl;
	cout << setw(12) << "A/C No." << setw(20) << "Name" << setw(10) << "Type" << setw(10) << "Balance" << endl;
	cout << "-------------------------------------------------\n"
		 << endl;
	while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Account)))
	{
		ac.PrintList();
	}
	cout << "-------------------------------------------------\n";
	inFile.close();
}

// function to delete account
void delete_account(int acc)
{
	Account ac;
	char ch;

	cout << "Are you sure you want to delete?(y/n)\n";
	cin >> ch;

	if (ch == 'y' || ch == 'Y')
	{
		ifstream inFile;
		ofstream outFile;
		inFile.open("customer.txt", ios::binary);

		if (!inFile)
		{
			cout << "File could not be open !! Press any Key...";
			return;
		}

		outFile.open("temp.txt", ios::binary);
		inFile.seekg(0, ios::beg);

		while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Account)))
		{
			if (!ac.SearchAccount(acc))
			{
				outFile.write(reinterpret_cast<char *>(&ac), sizeof(Account));
			}
		}
		inFile.close();
		outFile.close();
		remove("customer.txt");
		rename("temp.txt", "customer.txt");
		cout << "Record Deleted.." << endl;
	}
	else
		cout << "\nAccount not deleted." << endl;
}

// function to update balance
void update_balance(int acc)
{
	int amt;
	bool found = false;

	Account ac;
	fstream File;
	File.open("customer.txt", ios::binary | ios::in | ios::out);

	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}

	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char *>(&ac), sizeof(Account));
		if (ac.SearchAccount(acc))
		{
			ac.ShowAccount();
			ac.DoTransaction();
			int pos = (-1) * static_cast<int>(sizeof(ac));

			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char *>(&ac), sizeof(Account));
			found = true;
		}
	}
	File.close();

	if (found == false)
		cout << "\nAccount number does not exist!";
}

// function to print name or address
void name_add(int acc, int option)
{
	Account ac;
	bool flag = false;

	ifstream readFile;
	readFile.open("customer.txt", ios::binary);

	if (!readFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (readFile.read(reinterpret_cast<char *>(&ac), sizeof(Account)))
	{
		if (ac.SearchAccount(acc))
		{
			if (option == 1)
			{
				cout << "Account Number: " << acc;
				ac.ShowAccount();
			}
			else if (option == 2)
			{
				cout << "Account Number: " << acc;
				ac.ShowAccount();
				ac.PrintAddress();
			}
			flag = true;
		}
	}
	readFile.close();

	if (flag == false)
		cout << "\nAccount number does not exist!";
}

// function for balance enquiry
void balance_enquiry(int acc)
{
	Account ac;
	bool flag = false;

	ifstream readFile;
	readFile.open("customer.txt", ios::binary);

	if (!readFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}

	while (readFile.read(reinterpret_cast<char *>(&ac), sizeof(Account)))
	{
		if (ac.SearchAccount(acc))
		{
			cout << "Account Number: " << acc;
			ac.ShowAccount();
			flag = true;
		}
	}
	readFile.close();

	if (flag == false)
		cout << "\nAccount number does not exist!";
}

// display last entry details
void display_last()
{
	Account ac, *acPtr;

	ifstream inFile;
	inFile.open("customer.txt", ios::binary);

	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}

	while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(Account)))
	{
		acPtr = &ac;
	}

	cout << "Account No: " << acPtr->GetAccountNo() << endl;
	acPtr->ShowAccount();
	acPtr->PrintAddress();
	acPtr->PrintLastDate();
	cout << endl;

	inFile.close();
}

// function to check intrest
void check_interest(int acc)
{
	Account ac;
	bool found = false;

	ifstream readFile;
	readFile.open("customer.txt", ios::binary);

	if (!readFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}

	while (readFile.read(reinterpret_cast<char *>(&ac), sizeof(Account)))
	{
		if (ac.SearchAccount(acc))
		{
			ac.CheckInterest();
			found = true;
		}
	}

	if (found == false)
		cout << "\nAccount doesn't exists" << endl;
	readFile.close();
}