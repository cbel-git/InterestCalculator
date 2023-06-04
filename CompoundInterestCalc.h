#ifndef INTERESTCALCULATOR_COMPOUNDINTERESTCALC_H
#define INTERESTCALCULATOR_COMPOUNDINTERESTCALC_H

//
// Created by cody belanger on 5/26/2023.
//


class CompoundInterestCalc {
public:
    // setters
    void SetInterestRate(double interest);
    void SetDepositAmt(double firstDeposit);
    void SetMonthlyPayment(double monthlyPayment);
    void SetYearEndBal(int numYears, double firstDeposit, double monthlyPayment, double interestRate, std::vector<double>& yearlyTotals, std::vector<double>& yearlyInterest);
    void SetYearEndBalNoDep(int numYears, double firstDeposit, double monthlyPayment, double interestRate, std::vector<double>& yearlyTotalsNoInt, std::vector<double>& yearlyInterestNoInt);


    // getters
    double GetInterestRate();
    double GetDepositAmt();
    double GetMonthlyPayment();
    double GetTotalAmt();
    double GetInterestAmt();
    double GetClosingBal();

    void PrintCalc(std::vector<double> yearlyTotals, std::vector<double> yearlyInterest);





    void getUserInfo(int& numYears, double& initialDeposit, double& monthlyDeposit, double& interestRate);
private:
    int numYears;
    double initialDeposit;
    double monthlyDeposit;
    double totalAmount;
    double interestRate;
    double interestGained;
    double finalBalance;
    double yearEndBal;


};


#endif //COMPINTCALC
