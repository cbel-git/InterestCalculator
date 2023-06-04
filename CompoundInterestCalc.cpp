//
// Created by codyh on 5/26/2023.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include "CompoundInterestCalc.h"
using namespace std;



// setters

void CompoundInterestCalc::SetInterestRate(double interest) {
    this->interestRate = interest;

}

void CompoundInterestCalc::SetDepositAmt(double firstDeposit) {
    this->initialDeposit = firstDeposit;
}

void CompoundInterestCalc::SetMonthlyPayment(double monthlyPayment) {
    this->monthlyDeposit = monthlyPayment;

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
}

void CompoundInterestCalc::SetYearEndBalNoDep(int numYears, double firstDeposit, double monthlyPayment,
                                              double interestRate, std::vector<double> &yearlyTotalsNoInt,
                                              std::vector<double> &yearlyInterestNoInt) {
    int timeInMonths = numYears * 12;
    double balance = firstDeposit; // Set initial balance as firstDeposit
    double yearlyTotal = balance;
    double yearlyInterestTotal = 0.0;

    for (int month = 1; month <= timeInMonths; month++) {
        double monthlyInterest = balance * ((interestRate / 100) / 12);
        balance += monthlyInterest;
        yearlyInterestTotal += monthlyInterest;
        if (month % 12 == 0) {
            yearlyTotalsNoInt.push_back(balance);
            yearlyInterestNoInt.push_back(yearlyInterestTotal);
            yearlyInterestTotal = 0.0;
        }
    }
}


// getters

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

void CompoundInterestCalc::PrintCalc(std::vector<double> yearlyTotals, std::vector<double> yearlyInterest) {
    cout << "   Year" << "      " << "Year-End Balance" << "        " << "Yearly Interest" << endl;
    cout << setw(54) << setfill('*') << "" << endl;
    cout << setw(0) << setfill(' ') << "";

    cout << fixed << setprecision(2);  // Set precision for floating-point values

    for (int i = 0; i < yearlyTotals.size(); i++) {
        cout << setw(5) << i + 1 << "   |" << setw(15) << yearlyTotals[i] << setw(10) << "   |"
             << setw(15) << right << yearlyInterest[i] << "    |" << endl;
    } // end of for loop

    cout << setw(54) << setfill('*') << "" << endl;
    cout << setw(0) << setfill(' ') << "";

}


