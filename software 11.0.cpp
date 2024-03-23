#include <iostream>
using namespace  std;
class PayRoll {
private:
    double hourlyPayRate;
    double hoursWorked;
    double totalPay;

public:
    PayRoll() : hourlyPayRate(0), hoursWorked(0), totalPay(0) {}

    void setHourlyPayRate(double rate) {
        hourlyPayRate = rate;
    }

    void setHoursWorked(double hours) {
        if (hours <= 60)
            hoursWorked = hours;
        else {
            cout << "Error: Hours worked cannot be greater than 60." << endl;
            hoursWorked = 0;
        }
    }

    double calculatePay() {
        totalPay = hourlyPayRate * hoursWorked;
        return totalPay;
    }
};

int main() {
    const int numEmployees = 7;
    PayRoll employees[numEmployees];

    double hoursWorked;


    for (int i = 0; i < numEmployees; ++i) {
        cout << "Enter hours worked for employee " << i + 1 << ": ";
        cin >> hoursWorked;
        employees[i].setHoursWorked(hoursWorked);
    }

    double hourlyPayRate;
    
    cout << "Enter hourly pay rate for all employees: ";
    cin >> hourlyPayRate;

    
    for (int i = 0; i < numEmployees; ++i) {
        employees[i].setHourlyPayRate(hourlyPayRate);
    }

    
     cout << "\nGross Pay for Each Employee:" << endl;
    for (int i = 0; i < numEmployees; ++i) {
        double grossPay = employees[i].calculatePay();
        cout << "Employee " << i + 1 << ": $" << grossPay << endl;
}
}
