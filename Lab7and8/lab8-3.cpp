#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// This program demonstrates how to use an array of structures

// RAZIQ DIN BIN MOHD TASRIRI

struct taxPayer
{
    string name;
    float taxRate;
    float income;
    float taxes;
};

int main()
{
    const int NUM_TAXPAYERS = 5; // Number of taxpayers
    taxPayer citizens[NUM_TAXPAYERS]; // Array of taxPayer structures

    cout << fixed << showpoint << setprecision(2);
    cout << "Please enter the name, annual income, and tax rate for " 
         << NUM_TAXPAYERS << " taxpayers:\n\n";

    for (int i = 0; i < NUM_TAXPAYERS; i++)
    {
        cout << "Enter name for taxpayer #" << (i + 1) << ": ";
        cin >> ws; // Clear any whitespace before input
        getline(cin, citizens[i].name);

        cout << "Enter this year's income for " << citizens[i].name << ": ";
        cin >> citizens[i].income;

        cout << "Enter the tax rate for " << citizens[i].name << " (e.g., 0.30 for 30%): ";
        cin >> citizens[i].taxRate;

        // Compute taxes
        citizens[i].taxes = citizens[i].income * citizens[i].taxRate;

        cout << endl;
    }

    cout << "Taxes due for this year:\n\n";

    for (int i = 0; i < NUM_TAXPAYERS; i++)
    {
        cout << "Taxpayer #" << (i + 1) << ": " << citizens[i].name
             << "\nIncome: $" << citizens[i].income
             << "\nTax Rate: " << citizens[i].taxRate * 100 << "%"
             << "\nTaxes Due: $" << citizens[i].taxes << "\n\n";
    }

    return 0;
}
