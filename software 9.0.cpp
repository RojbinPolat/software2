#include <iostream>
#include <stdexcept>
using namespace std;
class Population {
private:
    double population;
    double births;
    double deaths;

public:

    Population(double pop, double b, double d) {
        if (pop < 1 || b < 0 || d < 0) {
          throw invalid_argument("Population, births, and deaths must be positive values.");
        }
        population = pop;
        births = b;
        deaths = d;
    }

     
    double birthRate() const {
        return births / population;
    }

    
    double deathRate() const {
        return deaths / population;
    }
};

int main() {
    double population, births, deaths;

    
     cout << "Enter the population: ";
     cin >> population;

     cout << "Enter the number of births: ";
     cin >> births;

      cout << "Enter the number of deaths: ";
      cin >> deaths;

    try {
        
        Population pop(population, births, deaths);

        
         cout << "Birth rate: " << pop.birthRate() <<  endl;
          cout << "Death rate: " << pop.deathRate() <<  endl;
    } catch (const invalid_argument& e) {
        cerr << "Invalid input: " << e.what() << endl;
    }

}
