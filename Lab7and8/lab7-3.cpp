// This program will read in prices and store them into a two-dimensional array.
// It will print those prices in a table form and find the highest price.

// RAZIQ DIN BIN MOHD TASRIRI

#include <iostream>
#include <iomanip>
using namespace std;

const int MAXROWS = 10;
const int MAXCOLS = 10;

typedef float PriceType[MAXROWS][MAXCOLS];

void getPrices(PriceType, int&, int&);
void printPrices(PriceType, int, int);
float findHighestPrice(PriceType, int, int);
float findLowestPrice(PriceType , int , int);

int main()
{
   int rowsUsed;
   int colsUsed;
   PriceType priceTable;

   getPrices(priceTable, rowsUsed, colsUsed);
   printPrices(priceTable, rowsUsed, colsUsed);

   float highestPrice = findHighestPrice(priceTable, rowsUsed, colsUsed);
   float lowestPrice = findLowestPrice(priceTable , rowsUsed , colsUsed);
   cout << "The highest price is: " << highestPrice << endl;
   cout << "The lowest price is :" << lowestPrice << endl;
   return 0;
}

//*******************************************************************************
//   getPrices
//
//   task:     This procedure asks the user to input the number of rows and
//             columns. It then asks the user to input (rows * columns) number of
//             prices. The data is placed in the array.
//   data in:  none
//   data out: an array filled with numbers and the number of rows
//             and columns used.
//*******************************************************************************

void getPrices(PriceType table, int& numOfRows, int& numOfCols)
{
   cout << "Please input the number of rows from 1 to " << MAXROWS << endl;
   cin >> numOfRows;

   while (numOfRows < 1 || numOfRows > MAXROWS) {
      cout << "Invalid input. Please input a number between 1 and " << MAXROWS << endl;
      cin >> numOfRows;
   }

   cout << "Please input the number of columns from 1 to " << MAXCOLS << endl;
   cin >> numOfCols;

   while (numOfCols < 1 || numOfCols > MAXCOLS) {
      cout << "Invalid input. Please input a number between 1 and " << MAXCOLS << endl;
      cin >> numOfCols;
   }

   for (int row = 0; row < numOfRows; row++) {
      for (int col = 0; col < numOfCols; col++) {
         cout << "Enter value for row " << row + 1 << ", column " << col + 1 << ": ";
         cin >> table[row][col];
      }
   }
}

//***************************************************************************
//   printPrices
//
//   task:     This procedure prints the table of prices
//   data in:  an array of floating point numbers and the number of rows
//             and columns used.
//   data out: none
//****************************************************************************

void printPrices(PriceType table, int numOfRows, int numOfCols)
{
   cout << fixed << showpoint << setprecision(2);

   for (int row = 0; row < numOfRows; row++) {
      for (int col = 0; col < numOfCols; col++) {
         cout << setw(8) << table[row][col] << " ";
      }
      cout << endl;
   }
}

//***************************************************************************
//   findHighestPrice
//
//   task:     This function returns the highest price in the array
//   data in:  an array of floating point numbers and the number of rows
//             and columns used.
//   data out: the highest price in the array
//****************************************************************************

float findHighestPrice(PriceType table, int numOfRows, int numOfCols)
{
   float highestPrice = table[0][0]; // Initialize with the first element

   for (int row = 0; row < numOfRows; row++) {
      for (int col = 0; col < numOfCols; col++) {
         if (highestPrice < table[row][col]) {
            highestPrice = table[row][col];
         }
      }
   }

   return highestPrice;
}


float findLowestPrice(PriceType table , int numOfRows , int numOfCols)
{
   float lowestPrice = table[0][0];
   for (int row = 0; row < numOfRows;row++ ){
     for (int col = 0 ; col < numOfCols ; col++){
      if (lowestPrice > table[row][col]){
         lowestPrice = table[row][col];
      }
     }
   }

   return lowestPrice;
   
}