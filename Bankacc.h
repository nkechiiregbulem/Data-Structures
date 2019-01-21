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
private:
    double balance;
    double interestRate;
    double lastInterestDate;
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
};

#endif /* Bankacc_h */
