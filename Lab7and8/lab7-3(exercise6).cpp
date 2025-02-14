// This program will read in the quarterly sales transactions for a given number
// of years. It will print the year and transactions in a table format.
// It will calculate year and quarter total transactions.

// RAZIQ DIN BIN MOHD TASRIRI

#include <iostream>
#include <iomanip>
using namespace std;

const int MAXYEAR = 10;
const int MAXCOL = 5;

typedef int SalesType[MAXYEAR][MAXCOL];  // creates a new 2D integer data type 

void getSales(SalesType, int&);          // places sales figures into the array
void printSales(SalesType, int);         // prints data as a table
void printTableHeading();                // prints table heading

int main()
{
   int yearsUsed;                        // holds the number of years used
   SalesType sales;                      // 2D array holding the sales transactions 

   getSales(sales, yearsUsed);           // calls getSales to put data in array
   printTableHeading();                  // calls procedure to print the heading 
   printSales(sales, yearsUsed);         // calls printSales to display table

   return 0;
}

//*****************************************************************************
//   printTableHeading
//
//   task:     This procedure prints the table heading
//   data in:  none
//   data out: none
//*****************************************************************************

void printTableHeading()
{
   cout << setw(30) << "YEARLY QUARTERLY SALES" << endl << endl << endl;

   cout << setw(10) << "YEAR" << setw(10) << "Quarter 1"
       << setw(10) << "Quarter 2" << setw(10) << "Quarter 3"
       << setw(10) << "Quarter 4" << setw(12) << "Year Total" << endl;
}

//*****************************************************************************
//   getSales
//
//   task:     This procedure asks the user to input the number of years.
//             For each of those years it asks the user to input the year
//             (e.g. 2004), followed by the sales figures for each of the
//             4 quarters of that year. That data is placed in a 2D array
//   data in:  a 2D array of integers
//   data out: the total number of years
//*****************************************************************************

void getSales(SalesType table, int& numOfYears)
{
   cout << "Please input the number of years (1-" << MAXYEAR << ")" << endl;
   cin >> numOfYears;

   while (numOfYears < 1 || numOfYears > MAXYEAR) {
      cout << "Invalid input. Please enter a number between 1 and " << MAXYEAR << ": ";
      cin >> numOfYears;
   }

   for (int year = 0; year < numOfYears; year++) {
      cout << "Enter the year (e.g., 2024): ";
      cin >> table[year][0]; // Store the year in the first column

      for (int quarter = 1; quarter <= 4; quarter++) {
         cout << "Enter sales for Quarter " << quarter << ": ";
         cin >> table[year][quarter];
      }
   }
}

//*****************************************************************************
//   printSales
//
//   task:     This procedure prints out the information in the array
//   data in:  an array containing sales information
//   data out: none
//*****************************************************************************

void printSales(SalesType table, int numOfYears)
{
   int quarterlyTotals[4] = {0, 0, 0, 0}; // Holds totals for each quarter

   for (int year = 0; year < numOfYears; year++) {
      int yearTotal = 0;
      cout << setw(10) << table[year][0]; // Print the year

      for (int quarter = 1; quarter <= 4; quarter++) {
         cout << setw(10) << table[year][quarter];
         yearTotal += table[year][quarter];
         quarterlyTotals[quarter - 1] += table[year][quarter];
      }

      cout << setw(12) << yearTotal << endl; // Print the year total
   }

   // Print quarterly totals
   cout << setw(10) << "TOTALS";
   for (int quarter = 0; quarter < 4; quarter++) {
      cout << setw(10) << quarterlyTotals[quarter];
   }
   cout << endl;
}