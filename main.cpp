#include <iostream>
#include <iomanip>
#include <vector>
#include "CompoundInterestCalc.h"

using namespace std;

int main() {
    int numYears = 5;
    double initialDeposit;
    double monthlyDeposit;
    double interestRate;
    vector<double> yearEndTotals;
    vector<double> yearEndInterest;

    vector<double> yearEndTotalsNoDep;
    vector<double> yearEndInterestNoDep;
    CompoundInterestCalc CompCalc;

    string userInput = "empty";
    while (userInput != "quit") {

        // converts userInput to lowercase
        for (char& c : userInput) {
            c = tolower(c);
        }
        if (userInput == "quit") {
            cout << "Thank you for using this calculator!" << endl;
            break;
        }


        // clears vectors for re printing
        yearEndTotalsNoDep.clear();
        yearEndInterestNoDep.clear();
        yearEndTotals.clear();
        yearEndInterest.clear();

        // get user information
        CompCalc.getUserInfo(numYears, initialDeposit, monthlyDeposit, interestRate);


        // sets the respective variables initialDeposit and monthly deposit
        CompCalc.SetDepositAmt(initialDeposit);
        CompCalc.SetMonthlyPayment(monthlyDeposit);


        // sets the interest rate & amount earned
        CompCalc.SetInterestRate(interestRate);


        // calculates year end balances, adds to vector yearEndTotals
        CompCalc.SetYearEndBal(numYears, initialDeposit, monthlyDeposit, interestRate, yearEndTotals, yearEndInterest);
        CompCalc.SetYearEndBalNoDep(numYears, initialDeposit, monthlyDeposit, interestRate, yearEndTotalsNoDep, yearEndInterestNoDep);

        // prints both tables with header to describe content
        cout << endl << "Year end amounts with monthly deposit of $" << monthlyDeposit << ":" << endl << endl;
        cout << setw(54) << setfill('*') << "" << endl;
        cout << setw(0) << setfill(' ') << "";
        CompCalc.PrintCalc(yearEndTotals, yearEndInterest);
        cout << endl << "Year end amounts with NO monthly deposit:" << endl << endl;
        cout << setw(54) << setfill('*') << "" << endl;
        cout << setw(0) << setfill(' ') << "";
        CompCalc.PrintCalc(yearEndTotalsNoDep, yearEndInterestNoDep);

        // allows user to re input data to determine what the best plan is
        cout << endl << endl;
        cout << "Type continue to re-input information, or quit to exit." << endl;
        cin >> userInput;


    } // end of while loop

    return 0;
}
