#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// This program demonstrates partially initialized structure variables

// RAZIQ DIN BIN MOHD TASRIRI

struct taxPayer
{
    string name;
    long socialSecNum;
    float taxRate; 
    float income; 
    float taxes;
};

int main()
{
    // Initialize structure variables
    taxPayer citizen1 = {"Tim McGuiness", 255871234, 0.35, 0.0, 0.0};
    taxPayer citizen2 = {"John Kane", 278990582, 0.29, 0.0, 0.0};

    cout << fixed << showpoint << setprecision(2);

    // Calculate taxes due for citizen1
    cout << "Enter this year's income for " << citizen1.name << ": ";
    cin >> citizen1.income;
    citizen1.taxes = citizen1.income * citizen1.taxRate;

    cout << "Name: " << citizen1.name << endl;
    cout << "Social Security Number: " << citizen1.socialSecNum << endl;
    cout << "Taxes due for this year: $" << citizen1.taxes << endl << endl;

    // Calculate taxes due for citizen2
    cout << "Enter this year's income for " << citizen2.name << ": ";
    cin >> citizen2.income;
    citizen2.taxes = citizen2.income * citizen2.taxRate;

    cout << "Name: " << citizen2.name << endl;
    cout << "Social Security Number: " << citizen2.socialSecNum << endl;
    cout << "Taxes due for this year: $" << citizen2.taxes << endl << endl;

    return 0;
}