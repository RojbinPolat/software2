#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;

class Coin {
private:
    int side; 
public:
    Coin() {
        
        srand(time(0));
        
        toss();
    }

    void toss() {
        
        side = rand() % 2;
    }

    bool isHeads() const {
        return (side == 0);
    }
};

int main() {
    
    Coin quarter, dime, nickel;

    
    double balance = 0.0;

    
    while (balance < 1.0) {
        
        quarter.toss();
        dime.toss();
        nickel.toss();

        
        if (quarter.isHeads())
            balance += 0.25;
        if (dime.isHeads())
            balance += 0.10;
        if (nickel.isHeads())
            balance += 0.05;

        
        cout << "Balance: $" << balance << endl;

        
        if (balance >= 1.0) {
            if (balance == 1.0)
                cout << "Congratulations! You win!" << endl;
            else
                cout << " Balance exceeded $1." << endl;
            break;
        }
    }


}

