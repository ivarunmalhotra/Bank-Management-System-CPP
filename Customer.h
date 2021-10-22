/*
    Class Bank Account to be used in Transaction and main file
*/

#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>
using namespace std;

// Customer class to store information of customer
class Customer
{
private:
    // Private members of the class
    char Name_[50];
    int AccountNo_;
    char AccountType_;
    double Balance_;
    char Address_[100];

public:
    // Public members and member functions
    Customer() {}
    void OpenAccount();
    void ShowAccount();
    void DepositAmount();
    void WithdrawAmount();
    void PrintName();
    void PrintAddress();
    char GetAccountType() const;
    double GetBalance() const;
    int GetAccountNo() const;
    int SearchAccount(int);
    void PrintList() const;
};

// Definition of member functions outside the class to open account
void Customer::OpenAccount()
{
    cout << "\n\n\tFILL FORM TO OPEN ACCOUNT\n" << endl;

    cout << "Enter Your Name: ";
    cin.ignore();
    cin.getline(Name_, 50);

    cout << "Enter Address: ";
    cin.getline(Address_, 100);

    cout << "Enter Account Type(S/C): ";
    cin >> AccountType_;

    cout << "Enter Account Number: ";
    cin >> AccountNo_;

    cout << "Enter Initial Balance: ";
    cin >> Balance_;

    cout << "\nAccount create successfully" << endl;
}

// To display account info or balance
void Customer::ShowAccount()
{
    cout << "Account Type: " << AccountType_ << endl;
    cout << "Name: " << Name_ << endl;
    cout << "Balance: " << Balance_ << endl;
}

// To deposit amount entered by user
void Customer::DepositAmount()
{
    float amt;
    cout << "Enter amount you want to deposit: ";
    cin >> amt;

    Balance_ = Balance_ + amt;
    cout << "\nAmount successfully deposited.\n";
}

// To withdrawl amount entered by user
void Customer::WithdrawAmount()
{
    float amt;
    cout << "Enter Amount you want to withdraw: ";
    cin >> amt;

    if (amt <= Balance_)
    {
        Balance_ = Balance_ - amt;
        cout << "\nAmount successfully withdrawn.\n";
    }
    else
    {
        cout << "\nERROR: Insufficient Balance!!\nYour balance is not sufficient for this request.\n";
        cout << "Please add money before proceeding." << endl;
    }
}

// To get name on the basis of account no
void Customer::PrintName()
{
    cout << "Account Holder's Name: " << Name_ << endl;
}

// To get name on the basis of account no
void Customer::PrintAddress()
{
    cout << "Account Holder's Address: " << Address_ << endl;
}

// To return account type
char Customer::GetAccountType() const
{
    return AccountType_;
}

// To return account no
int Customer::GetAccountNo() const
{
    return AccountNo_;
}

// To get name on the basis of account no
double Customer::GetBalance() const
{
    return Balance_;
}

// Search an accout through an account no
int Customer::SearchAccount(int a)
{
    if (AccountNo_ == a)
        return 1;
    return 0;
}

// Printing in form of list
void Customer::PrintList() const
{
    cout.setf(ios::left, ios::adjustfield);
    cout << setw(12) << AccountNo_ << setw(20) << Name_ << setw(10) << AccountType_ << setw(10) << Balance_ << endl;
}