#ifndef INTERESTCALCULATOR_COMPOUNDINTERESTCALC_H
#define INTERESTCALCULATOR_COMPOUNDINTERESTCALC_H

//
// Created by codyh on 5/26/2023.
//


class CompoundInterestCalc {
public:
    void SetYears(int years);
    int GetYears();
    void SetInterestRate(double interest);
    double GetInterestRate();
    void SetDepositAmt(double firstDeposit);
    double GetDepositAmt();
    void SetMonthlyPayment(double monthlyPayment);
    double GetMonthlyPayment();
    void SetTotalAmt(double firstDeposit, double monthlyPayment);
    double GetTotalAmt();
    void SetInterestAmt(double initialDeposit, double monthlyDeposit , double interestRate, int numYears);
    double GetInterestAmt();
    void SetClosingBal(double totalAmount, double interestGained);
    double GetClosingBal();

    void PrintCalc(std::vector<double> yearlyTotals, std::vector<double> yearlyInterest);

    void SetYearEndBal(int numYears, double firstDeposit, double monthlyPayment, double interestRate, std::vector<double>& yearlyTotals, std::vector<double>& yearlyInterest);
    void SetYearEndBalNoDep(int numYears, double firstDeposit, double monthlyPayment, double interestRate, std::vector<double>& yearlyTotalsNoInt, std::vector<double>& yearlyInterestNoInt);


    double GetYearEndBal();

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
