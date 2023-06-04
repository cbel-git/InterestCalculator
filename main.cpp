#include <iostream>
#include <iomanip>
#include <vector>
#include "CompoundInterestCalc.h"

using namespace std;

int main() {
    int numYears = 5;
    double initialDeposit = 1.00;
    double monthlyDeposit  = 50.00;
    double interestRate = 5.0;
    double yearEndBal;
    vector<double> yearEndTotals;
    vector<double> yearEndInterest;

    vector<double> yearEndTotalsNoDep;
    vector<double> yearEndInterestNoDep;
    //FIXME remove variable declarations from here
    //double totalAmount;
    //double interestGained;
    //double finalBalance;
    CompoundInterestCalc CompCalc;

    string userInput = "empty";
    while (userInput != "quit") {


        for (char& c : userInput) {
            c = tolower(c);
        }

        // Check if input is "quit"
        if (userInput == "quit") {
            std::cout << "Exiting. Thank you for using our calculator!" << std::endl;
            break;
        }

        yearEndTotals.clear();
        yearEndInterest.clear();

        // get user information
        //CompCalc.getUserInfo(numYears, initialDeposit, monthlyDeposit, interestRate);


        // sets the respective variables initialDeposit and monthly deposit
        CompCalc.SetDepositAmt(initialDeposit);
        CompCalc.SetMonthlyPayment(monthlyDeposit);


        // sets the interest rate & amount earned
        CompCalc.SetInterestRate(interestRate);


        // calculates year end balances, adds to vector yearEndTotals
        CompCalc.SetYearEndBal(numYears, initialDeposit, monthlyDeposit, interestRate, yearEndTotals, yearEndInterest);
        CompCalc.SetYearEndBalNoDep(numYears, initialDeposit, monthlyDeposit, interestRate, yearEndTotalsNoDep, yearEndInterestNoDep);



        CompCalc.PrintCalc(yearEndTotals, yearEndInterest);
        cout << endl;
        CompCalc.PrintCalc(yearEndTotalsNoDep, yearEndInterestNoDep);


//        cout << "   Year" << "      " << "Year-End Balance" << "        " << "Yearly Interest" << endl;
//        cout << setw(54) << setfill('*') << "" << endl;
//        cout << setw(0) << setfill(' ') << "";
//
//        cout << fixed << setprecision(2);  // Set precision for floating-point values
//
//        for (int i = 0; i < yearEndTotals.size(); i++) {
//            cout << setw(5) << i + 1 << "   |" << setw(15) << yearEndTotals[i] << setw(10) << "   |"
//                 << setw(15) << right << yearEndInterest[i] << "    |" << endl;
//        } // end of for loop
//
//        cout << setw(54) << setfill('*') << "" << endl;
//        cout << setw(0) << setfill(' ') << "";

        cout << endl << endl;
        cout << "Type continue to re-input information, or quit to exit." << endl;
        cin >> userInput;


    } // end of while loop

    return 0;
}
