//
//  main.cpp
//  BankAccountLab
//
//  Created by Nkechi Iregbulem on 1/18/19.
//  Copyright © 2019 Nkechi Iregbulem. All rights reserved.
//

#include "Bankacc.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int accountBalance::todayDate() {
    time_t t  = time(0);
    struct tm* now  = localtime(&t);
    return (now -> tm_year + 1900) * 10000 + (now->tm_mon + 1) * 100 + (now->tm_mday);
}
int accountBalance::accountCount = 0; 
accountBalance::accountBalance()
{
    balance = 0.0;
    interestRate = 0.0;
    lastInterestDate = 0;
    accountCount += 1;
}
accountBalance::~accountBalance() {
    accountCount -= 1;
}
accountBalance::accountBalance(double amount, double interest)
{
    balance = amount;
    interestRate = interest;
    lastInterestDate = todayDate();
}
void accountBalance::setBalance(double BAL)
{
    balance = BAL;
}
void accountBalance::deposit(double Addition)
{
    balance +=Addition;
}
void accountBalance::withdraw(double deduction)
{
    if (balance > 0) {
        balance -=deduction;
    }
    else
        cout << "Insufficient Balance" << endl;
        
}
void accountBalance::increaseBalanceBy(double BAL)
{
    balance += BAL;
}
void accountBalance::setInterestRate(double INTR)
{
    interestRate = INTR;
}
void accountBalance::addInterest()
{
    lastInterestDate = todayDate();
    
    if (todayDate() - lastInterestDate >= 30) {
        balance += interestRate;
        lastInterestDate = todayDate();
    }
    
    
}
 double accountBalance::getBalance()
{
    return balance;
}
double accountBalance::getInterestRate()
{
    return interestRate;
}
double accountBalance::getLastInterestDate()
{
    return lastInterestDate;
}
int accountBalance::getAccountCount()
{
    return accountCount;
}
void accountBalance::info()
{
    cout<<  "Balance: $"<<balance << endl;
    cout << "Interest Rate: " << interestRate << "%" << endl;
    cout << "Last Interest Date: " << lastInterestDate << endl;
}
SavingsAccount::SavingsAccount()
{
    bool lock = false;
    void accountLockMessage();
    time_t t  = time(0);
    struct tm* now  = localtime(&t);
    int today = (now -> tm_year + 1900) * 10000 + (now->tm_mon + 1) * 100 + (now->tm_mday);
    lastInterestDate = today;
}
SavingsAccount::SavingsAccount(double BAL, double INTR, bool lock):accountBalance(BAL,INTR)
{
    this->lock = lock;
}
void SavingsAccount::lockAccount()
{
    lock = true;
    cout << "Account is Locked" << endl;
}
void SavingsAccount::removeLock()
{
    lock = false;
    cout << "Account is Open" << endl;
}
void SavingsAccount::setBalance(double BAL)
{
    if (bool lock = true) {
        accountBalance::setBalance(BAL);
    }
    else
        cout << "Access is denied due to account being locked" << endl;
}
void SavingsAccount::setInterestRate(double INTR)
{
    if (bool lock = false) {
        setInterestRate(INTR);
    }
    else
        cout << "Accces is denied due to account being locked" << endl;
}
void SavingsAccount::addInterest()
{
    if (bool lock = true) {
        addInterest() ;
    }
    else
        cout << "Access is denied due to account being locked" << endl;
}
void SavingsAccount::deposit(double addition)
{
    if (bool lock = true) {
        deposit(addition);
    }
    else
        cout << "Access is denied due to account being locked" << endl;
}
void SavingsAccount::withdraw(double deduction)
{
    if (bool lock = true) {
        accountBalance::withdraw(deduction);
    }
    else
        cout << "Access is denied due to account being locked" << endl;
}
void SavingsAccount::Info()
{
    accountBalance::info();
    string value = "";
    if ( lock == true) {
        value = "True";
    } else {
        value = "False";
    }
    cout << "Account Lock: " << value << endl;
}
WalletAccount::WalletAccount()
{
    void accountBalance(double BAL, double interest);
    time_t t  = time(0);
    struct tm* now  = localtime(&t);
    int today = (now -> tm_year + 1900) * 10000 + (now->tm_mon + 1) * 100 + (now->tm_mday);
    lastInterestDate = today;
}
WalletAccount::WalletAccount(double BAL, double INTR)
{
    void accountBalance(double BAL, double interest);
    balance = BAL;
    interestRate = INTR;
}
double WalletAccount::getMaxWalletCapacity()
{
    return maxWalletCapacity;
}
void WalletAccount::deposit(double addition)
{
    if (balance + addition > maxWalletCapacity) {
        balance +=addition;
    }
    else
        cout << "Balance exceeds wallet capacity" << endl;
}
void WalletAccount::setBalance(double BAL)
{
    if (BAL < maxWalletCapacity) {
        balance += BAL;
    }
    else
        cout << "Balance exceeds wallet capacity" << endl;
}
void WalletAccount::Info()
{
    cout << "Balance: $" << balance << endl;
    cout << "Interest Rate: " << interestRate << "%" << endl;
    cout << "Last Interest Date" << getLastInterestDate() << endl;
    cout << "Max Wallet Capacity: $" <<maxWalletCapacity << endl;
}
int main()
{
    SavingsAccount* Savingspointer;
    Savingspointer = nullptr;
    WalletAccount* Walletpointer;
    Walletpointer = nullptr;
    cout << "Current accounts: " << accountBalance::getAccountCount();
    cout << endl;
    cout << "Would you like to open another account?" << endl;
    string yes_no;
    string yes_no2;
    string yes_no3;
    string balance_Q;
    string balance_Q2;
    cin >> yes_no;

    if (yes_no == "yes" || "Yes") {
        cout << "Would you like to open a savings account?" << endl;
        cin >> yes_no2;
        if (yes_no2 == "yes") {
            cout << "What is your initial balance?" << endl;
            cin >> balance_Q;
            Savingspointer = new SavingsAccount;
            cout << "Current number of accounts: " << accountBalance::getAccountCount();
            cout << endl;
        }
    else
        cout << "okay " << endl;
        
        while (yes_no2 == "no") {
        cout << "Would you like to open a Wallet Account?" << endl;
        cin >> yes_no3;
        if (yes_no3 == "yes") {
            cout << "What is your initial balance?" << endl;
            cin >> balance_Q2;
            Walletpointer = new WalletAccount;
            cout << "Current number of accounts: " << accountBalance::getAccountCount();
            cout << endl;
            break;
        }
        };
            while (yes_no2 == "yes") {
                cout << "Would you like to open a Wallet Account?" << endl;
                cin >> yes_no3;
                if (yes_no3 == "yes") {
                    cout << "What is your initial balance?" << endl;
                    cin >> balance_Q2;
                    Walletpointer = new WalletAccount;
                    cout << "Current number of accounts: " << accountBalance::getAccountCount();
                    cout << endl;
                    break;
            }
            };
    

    }
    
    accountBalance Account = accountBalance();
    Account.setBalance(3000);
    Account.setInterestRate(.02);
    Account.info();
    Account.addInterest();
    Account.info();
    Account.addInterest();
    Account.info();
    accountBalance Account2 = accountBalance();
    Account2.info();
    
    SavingsAccount savings(1000, 0.02, true);
    savings.Info();
    savings.withdraw(200);
    savings.removeLock();
    savings.withdraw(300);
    savings.withdraw(1000);
    savings.lockAccount();
    savings.deposit(2000);
    savings.Info();
    
    WalletAccount wallet(70.0, 0.02);
    wallet.Info();
    wallet.deposit(50);
    wallet.Info();
    
    
    
    
    
    
    
    return 0;
}

