/
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
#include <vector>
#include <utility>
#include <map>
using namespace std;

int accountBalance::todayDate() {
    time_t t  = time(0);
    struct tm* now  = localtime(&t);
    return (now -> tm_year + 1900) * 10000 + (now->tm_mon + 1) * 100 + (now->tm_mday);
}
int accountBalance::accountCount = 0 // ask about this
int accountBalance::accountNumber = 999;
int accountBalance::AccountToDelete = 0;
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
    accountCount++;
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
int accountBalance::getaccountNumber() {
    return accountNumber++;
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


void week3main()
{
   
    SavingsAccount* Savingspointer = nullptr;
    WalletAccount* Walletpointer = nullptr;
    
    cout << "Current accounts: " << accountBalance::getAccountCount() << endl;
    
    string yes_no;
    double balance_Q;
    cout << "Would you like to open an account?" << endl;
    cin >> yes_no;
    if (yes_no == "yes" || yes_no == "Yes") {
        cout << "Would you like to open a savings account?";
        cin >> yes_no;
        if (yes_no == "yes"|| "Yes") {
            cout << "What is your initial balance?";
            cin >> balance_Q;
            Savingspointer = new SavingsAccount(balance_Q, 0.02, false);
        }
    
        cout << "Would you like to open a Wallet Account?" << endl;
        cin >> yes_no;
        if (yes_no == "yes") {
            cout << "What is your initial balance?" << endl;
            cin >> balance_Q;
            Walletpointer = new WalletAccount(balance_Q,0.02);
        }
        
    }
    else
    {
        cout << "Maybe other time!" << endl;
    }
    
    cout << "Current number of accounts: " << accountBalance::getAccountCount();
    cout << endl;
}
        
        
        
void week4main(){
    vector< SavingsAccount*> accounts;
    cout << "Current number of accounts: " << accountBalance::getAccountCount();
    cout << endl;
    
    string yes_no;
    double balance_Q;
    
    cout << "Would you like to open a savings account?";
    cin >> yes_no;
    while (yes_no == "yes" || yes_no == "Yes") {
        cout << "What is your initial balance?";
        cin >> balance_Q;
        SavingsAccount* Savingspointer = nullptr;
        Savingspointer = new SavingsAccount(balance_Q, 0.02, false);
        accounts.push_back(Savingspointer);
        cout << "Would you like to open a savings account?";
        cin >> yes_no;
    }
    cout << "Current number of accounts: " << accountBalance::getAccountCount() << endl;
    int i;
    for (i = 0; i < accounts.size(); i++) {
        cout << endl << "Account number: " << i;
        accounts.at(i) -> Info();
    }
    int user_index;
    cout << endl << "Which account would you like to delete?";
    cin >> user_index;
    delete accounts.at(user_index);
    accounts.erase(accounts.begin()+user_index ,accounts.begin()+user_index+1);
    cout << endl << "Current number of accounts: " << accountBalance::getAccountCount()<< endl;
    
    SavingsAccount* max = accounts.at(0);
    for (i = 0; i < accounts.size(); i++) {
        if (max -> getBalance() < accounts.at(i) -> getBalance() ){
            max = accounts.at(i);
        }
        
    }
    max -> Info();
}
    
void week2Main(){
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
    
    cout << accountBalance::getAccountCount();
}

void week5main(){
    map<int, pair<WalletAccount*, SavingsAccount*>> Accounts;
    cout << accountBalance::getAccountCount() << endl;
    cout << "Would you like to open an account? " << endl;
    string yes_no;
    cin >> yes_no;
    while (yes_no == "yes" || yes_no == "Yes") {
        cout << "What is your initial Savings balance?";
        double savingsBalance;
        cin >> savingsBalance;
        SavingsAccount* Savingspointer = new SavingsAccount(savingsBalance, 0.02, false);
        cout << "What is your initial balance for your Wallet Account" << endl;
        double walletBalance;
        cin >> walletBalance;
        WalletAccount* Walletpointer = new WalletAccount(walletBalance,0.02);
        
        pair<WalletAccount*,SavingsAccount*> Account = make_pair(Walletpointer, Savingspointer);
        Accounts.emplace(accountBalance::getaccountNumber(), Account);
        cout << "Would you like to open an account? " << endl;
        cin >> yes_no;
    }
    
    cout << accountBalance::getAccountCount() << endl;
    
    cout << "***********************************" << endl;
    for (auto account:Accounts) {
        cout << account.first;
        cout << "***********************************" << endl;
        cout << "Wallet Account Info" << endl;
        account.second.first->info();
        cout << "***********************************" << endl;
        cout << "Savings Account Info" << endl;
        account.second.second->info();
    }
    
    cout << "Enter account number to deposit more into" << endl;
    int user_accountNum;
    cin >> user_accountNum;
    cout << "Enter which account you like to change? e.g(Savings or Wallet)" << endl;
    string user_answer;
    if (Accounts.count(user_accountNum) == 1) {
        if (user_answer == "savings" || "Savings") {
            cout << "How much would you like to deposit?" << endl;
            double user_deposit;
            cin >> user_deposit;
            Accounts.at(user_accountNum).second->deposit(user_deposit);
        }
        if (user_answer == "wallet" || "Wallet") {
            cout << "How much would you like to deposit?" << endl;
            double user_deposit;
            cin >> user_deposit;
            Accounts.at(user_accountNum).first->deposit(user_deposit);
        }
    }
    
    
    cout << "What account would you like to close?" << endl;
    int user_account;
    cin >> user_account;
    if (Accounts.count(user_accountNum) == 1) {
        delete Accounts.at(user_account).first;
        delete Accounts.at(user_account).second;
        Accounts.erase(user_account);
        cout << "Account is now closed" << endl;
    }
    
    cout << "Number of Accounts: " <<accountBalance::getAccountCount() << endl;
    
}

bool sortBalance(pair<int, set<SavingsAccount*>> acc1, pair<int, set<SavingsAccount*>> acc2) {
    double agBal1 = 0;
    double agBal2 = 0;
    for(auto subAccount:acc1.second){
        agBal1 += subAccount->getBalance();
    }
    for(auto subAccount:acc2.second) {
        agBal2 += subAccount->getBalance();
    }
    return  agBal1 > agBal2;

}


bool findHelper(pair<int, set<SavingsAccount*>> acc){
    return acc.first == accountBalance::AccountToDelete;
}

void week6main() {
     vector<pair<int, set<SavingsAccount*>>>Accounts;
    cout << "Would you like to open an account?" << endl;
    string yes_no;
    cin >> yes_no;
    while (yes_no == "yes" || yes_no == "Yes") {
        cout << "Would you like to open a savings account?" << endl;
        string yes_no2;
        cin >> yes_no2;
        double balance;
        set< SavingsAccount*> subAccounts;
        
        while (yes_no2 == "yes" || yes_no2 == "Yes") {
            cout << "How much would you like to deposit?" << endl;
                cin >> balance;
            subAccounts.insert(new SavingsAccount(balance, 0.02, false));
            cout << "Would you like to open a savings account?" << endl;
            cin >> yes_no2;
        }
        Accounts.push_back(make_pair(accountBalance::getaccountNumber(), subAccounts));
        
        cout << "Would you like to open an account?" << endl;
        cin >> yes_no;
    }

    sort(Accounts.begin(), Accounts.end(),sortBalance);
    
    for (auto account:Accounts) {
        set<SavingsAccount*> subAccounts = account.second;
        cout<< "Account " << account.first << endl;
        for (auto subAccount:subAccounts){
            subAccount ->info();
        }
    }

    
    
    cout << "Enter account number for account you wish to delete" << endl;
    
    cin >> accountBalance::AccountToDelete;
    vector<pair<int, set<SavingsAccount*>>>::iterator it;
        it = find_if(Accounts.begin(), Accounts.end(),findHelper);
    if (it != Accounts.end()){
            for(auto subAccount:it->second){
                delete subAccount;
            }
            Accounts.erase(it);
    }
}



int main() {
    week5main();
    return 0;
}
