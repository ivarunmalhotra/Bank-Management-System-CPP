/*
    Transaction class to be used in main file
*/

#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include "Customer.h"
using namespace std;

// class account inheriting some features of Customer class
class Account : public Customer
{

private:
    // Private members of class
    int NoOfTransaction = 0;
    int day_, month_, year_;
    char dd_[3], mm_[3], yyyy_[5];

public:
    // public members of class
    Account();
    void DoTransaction();
    void PrintLastDate();
    void CheckInterest();
};

// default constructor of class Account
Account::Account()
{
    NoOfTransaction = 0;
    day_ = 0;
    month_ = 0;
    year_ = 0;
}

// Transaction Operation to be performed
void Account::DoTransaction()
{
    int choice;

    // taking date of transaction from user
    cout << "Enter date(in dd/mm/yyyy format): ";
    cin.get(dd_, 3, '/');
    cin.ignore(100, '/');
    cin.get(mm_, 3, '/');
    cin.ignore(100, '/');
    cin.get(yyyy_, 5);

    // convert string to int using atoi function
    day_ = atoi(dd_);
    month_ = atoi(mm_);
    year_ = atoi(yyyy_);

    // operations to be performed for transaction
    cout << "\nWhat operation you want to perform: " << endl;
    cout << "1. Deposit Money" << endl;
    cout << "2. Withdraw Money" << endl;

    cout << "\nEnter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        NoOfTransaction += 1;
        DepositAmount();
    }
    else if (choice == 2)
    {
        NoOfTransaction += 1;
        WithdrawAmount();
    }
    else
    {
        cout << "ERROR:Invalid Choice!!\nPlease enter correct option." << endl;
        DoTransaction();
    }
}

// to print last date of transaction
void Account::PrintLastDate()
{
    cout << "Last date of transaction: " << day_ << "/" << month_ << "/" << year_ << endl;
}

// member function to check interest
void Account::CheckInterest()
{
    int day, month, year, difYear, difMonth;
    char dd[3], mm[3], yyyy[5];

    cout << "Enter Present date(in dd/mm/yyyy): ";
    cin.get(dd, 3, '/');
    cin.ignore(100, '/');
    cin.get(mm, 3, '/');
    cin.ignore(100, '/');
    cin.get(yyyy, 5);

    // convert string to int using atoi function
    day = atoi(dd);
    month = atoi(mm);
    year = atoi(yyyy);

    difMonth = month - month_;
    difYear = year - year_;

    if (difYear == 0)
    {
        if (difMonth == 0)
        {
            cout << "\nYou will not get charged.";
            PrintLastDate();
        }
        else
        {
            cout << "\nYou will be charged with the interest.\nReason: You haven't done any transaction from past 1 or more month";
            PrintLastDate();
        }
    }
    else
    {
        cout << "\nYou will be charged with the interest.\nReason: You haven't done any transaction from past 1 year";
        PrintLastDate();
    }
}