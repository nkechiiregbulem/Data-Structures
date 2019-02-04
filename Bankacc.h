//
//  Bankacc.h
//  BankAccountLab
//
//  Created by Nkechi Iregbulem on 1/18/19.
//  Copyright © 2019 Nkechi Iregbulem. All rights reserved.
//

#ifndef Bankacc_h
#define Bankacc_h


class accountBalance {
protected:
    double balance;
    double interestRate;
    double lastInterestDate;
    int todayDate();
    static int accountCount;
public:
    accountBalance();
    accountBalance(double amount, double interest);
    void setBalance (double BAL);           // BAL = balance
    void increaseBalanceBy (double BAL);
    void setInterestRate (double INTR);      // INTR = interest rate
    void addInterest();
    double getBalance ();
    double getInterestRate ();
    double getLastInterestDate ( );  // INTD = interest date
    void info ();
    ~accountBalance();
    static int getAccountCount();
};

class SavingsAccount: public accountBalance {
public:
    SavingsAccount();
    
    
    SavingsAccount(double BAL, double INTR, bool lock);
    void lockAccount();
    void removeLock();
    void setBalance(double BAL);
    void setInterestRate(double INTR);
    void addInterest();
    void deposit (double addition);
    void withdraw (double deduction);
    void Info();
private:
    bool lock = false;
    void accountLockMessage();
    int lastInterestDate = 0;
};

class WalletAccount: public accountBalance {
public:
    WalletAccount();
    
    WalletAccount(double BAL, double INTR);
    double getMaxWalletCapacity();
    void deposit(double addition);
    void setBalance(double BAL);
    void Info();
private:
    double maxWalletCapacity = 300;
    int lastInterestDate = 0;
};
#endif /* Bankacc_h */
