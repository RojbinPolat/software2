#include <iostream>
#include <cmath>

using namespace std;

class Mgage {
private:
    double loan;
    double rate;
    int years;

public:
    Mgage(double l = 0.0, double r = 0.0, int y = 0) : loan(l), rate(r), years(y) {}

    void setLoan(double l) {
        loan = l;
    }

    void setRate(double r) {
        rate = r;
    }

    void setYears(int y) {
        years = y;
    }

    double monthlyPayment() const {
        double monthlyRate = rate / 12 / 100;
        int n = years * 12;
        double payment = (loan * monthlyRate) / (1 - pow(1 + monthlyRate, -n));
        return payment;
    }

    double totalAmountPaid() const {
        return monthlyPayment() * years * 12;
    }
};

int main() {
    double loanAmount, interestRate;
    int numberOfYears;

    cout << "Enter the loan amount: ";
    cin >> loanAmount;

    cout << "Enter the annual interest rate (in percentage): ";
    cin >> interestRate;

    cout << "Enter the number of years of the loan: ";
    cin >> numberOfYears;

    Mgage mortgage(loanAmount, interestRate, numberOfYears);

    cout << "\nMonthly Payment: $" << mortgage.monthlyPayment() << endl;
    cout << "Total Amount Paid to the Bank: $" << mortgage.totalAmountPaid() << endl;

}
