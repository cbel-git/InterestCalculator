//
// Created by codyh on 5/26/2023.
//
#include <iostream>
#include <vector>
#include "CompoundInterestCalc.h"
using namespace std;



// setters

void CompoundInterestCalc::SetYears(int years) {
    this->numYears = years;

}

void CompoundInterestCalc::SetInterestRate(double interest) {
    this->interestRate = interest;

}

void CompoundInterestCalc::SetDepositAmt(double firstDeposit) {
    this->initialDeposit = firstDeposit;
}

void CompoundInterestCalc::SetMonthlyPayment(double monthlyPayment) {
    this->monthlyDeposit = monthlyPayment;

}

void CompoundInterestCalc::SetTotalAmt(double firstDeposit, double monthlyPayment) {
    this->totalAmount = firstDeposit + monthlyPayment;

}

void CompoundInterestCalc::SetInterestAmt(double initialDeposit, double monthlyDeposit, double interestRate, int years) {
    this->interestGained = ((initialDeposit + monthlyDeposit) * ((interestRate / 100) * 12));

}



void CompoundInterestCalc::SetClosingBal(double totalPayment, double interestEarned ) {
    this->finalBalance = totalPayment + interestEarned;

}

void CompoundInterestCalc::SetYearEndBal(int numYears,
                                         double firstDeposit,
                                         double monthlyPayment,
                                         double interestRate,
                                         vector<double>& yearlyTotals,
                                         vector<double>& yearlyInterest) {
    int timeInMonths = numYears * 12;
    double balance = firstDeposit; // Set initial balance as firstDeposit
    double yearlyTotal = balance;
    double yearlyInterestTotal = 0.0;

    for (int month = 1; month <= timeInMonths; month++) {
        balance += monthlyPayment; // Update balance by adding monthly payment
        double monthlyInterest = balance * ((interestRate / 100) / 12);
        balance += monthlyInterest;
        yearlyInterestTotal += monthlyInterest;
        if (month % 12 == 0) {
            yearlyTotals.push_back(balance);
            yearlyInterest.push_back(yearlyInterestTotal);
            yearlyInterestTotal = 0.0;
        }
    }
    //this->yearEndBal = balance;
}

// getters

int CompoundInterestCalc::GetYears() {
    return numYears;
}

double CompoundInterestCalc::GetDepositAmt() {
    return monthlyDeposit;
}

double CompoundInterestCalc::GetTotalAmt() {
    return static_cast<double>(totalAmount);
}

double CompoundInterestCalc::GetInterestAmt() {
    return static_cast<double>(interestGained);
}

double CompoundInterestCalc::GetInterestRate() {
    return static_cast<double>(interestRate);
}

double CompoundInterestCalc::GetClosingBal() {
    return finalBalance;
}


double CompoundInterestCalc::GetYearEndBal() {
    return yearEndBal;
}





// other functions

void CompoundInterestCalc::getUserInfo(int& numYears, double& initialDeposit, double& monthlyDeposit, double& interestRate) {
    cout << "numYears:" << endl;
    cin >> numYears;
    cout << "initialDeposit:" << endl;
    cin >> initialDeposit;
    cout << "monthlyDeposit:" << endl;
    cin >> monthlyDeposit;
    cout << "interestRate:" << endl;
    cin >> interestRate;
}


