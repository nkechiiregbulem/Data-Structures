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

accountBalance::accountBalance()
{
    balance = 0.0;
    interestRate = 0.0;
    lastInterestDate = 0;
}
accountBalance::accountBalance(double amount, double interest)
{
    balance = amount;
    interestRate = interest;
}
void accountBalance::setBalance(double BAL)
{
    balance = BAL;
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
    time_t t  = time(0);
    struct tm* now  = localtime(&t);
    int today = (now -> tm_year + 1900) * 10000 + (now->tm_mon + 1) * 100 + (now->tm_mday);
    lastInterestDate = today;
    
    
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
void accountBalance::info()
{
    cout<<  "balance = $"<<balance << endl;
    cout << "interest rate = " << interestRate << "%" << endl;
    cout << "last interest date: " << lastInterestDate << endl;
}

int main()
{
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
    
    
    
    
    
    
    return 0;
}

