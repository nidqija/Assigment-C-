// This program will input temperatures for consecutive days and calculate their average, 
// the highest, and the lowest temperatures. 
// The user will input the number of temperatures (maximum 50).

// RAZIQ DIN BIN MOHD TASRIRI

#include <iostream>
#include <iomanip>
using namespace std;

const int MAXTEMPS = 50; // Maximum number of temperatures

typedef float TempArray[MAXTEMPS];

void getTemperatures(TempArray, int&); // Function to input temperatures
float calculateAverage(TempArray, int); // Function to calculate average temperature
float findHighest(TempArray, int);      // Function to find the highest temperature
float findLowest(TempArray, int);       // Function to find the lowest temperature

int main()
{
    int numTemps;       // Number of temperatures to be read
    TempArray temps;     // Array to hold the temperatures

    getTemperatures(temps, numTemps);

    float average = calculateAverage(temps, numTemps);
    float highest = findHighest(temps, numTemps);
    float lowest = findLowest(temps, numTemps);

    cout << fixed << setprecision(2);
    cout << "The average temperature is " << average << endl;
    cout << "The highest temperature is " << highest << endl;
    cout << "The lowest temperature is " << lowest << endl;

    return 0;
}

//*****************************************************************************
//   getTemperatures
//
//   task:     This function asks the user to input the number of temperatures
//             and the temperatures themselves. The data is placed in an array.
//   data in:  none
//   data out: an array filled with temperatures and the number of temperatures
//*****************************************************************************

void getTemperatures(TempArray temps, int& numTemps)
{
    cout << "Please input the number of temperatures to be read (1-" << MAXTEMPS << "): ";
    cin >> numTemps;

    while (numTemps < 1 || numTemps > MAXTEMPS) {
        cout << "Invalid input. Please enter a number between 1 and " << MAXTEMPS << ": ";
        cin >> numTemps;
    }

    for (int i = 0; i < numTemps; i++) {
        cout << "Input temperature " << i + 1 << ": ";
        cin >> temps[i];
    }
}

//*****************************************************************************
//   calculateAverage
//
//   task:     This function calculates the average of the temperatures
//             stored in the array.
//   data in:  an array of temperatures and the number of temperatures
//   data out: the average temperature
//*****************************************************************************

float calculateAverage(TempArray temps, int numTemps)
{
    float total = 0;
    for (int i = 0; i < numTemps; i++) {
        total += temps[i];
    }
    return total / numTemps;
}

//*****************************************************************************
//   findHighest
//
//   task:     This function finds the highest temperature in the array.
//   data in:  an array of temperatures and the number of temperatures
//   data out: the highest temperature
//*****************************************************************************

float findHighest(TempArray temps, int numTemps)
{
    float highest = temps[0];
    for (int i = 1; i < numTemps; i++) {
        if (temps[i] > highest) {
            highest = temps[i];
        }
    }
    return highest;
}

//*****************************************************************************
//   findLowest
//
//   task:     This function finds the lowest temperature in the array.
//   data in:  an array of temperatures and the number of temperatures
//   data out: the lowest temperature
//*****************************************************************************

float findLowest(TempArray temps, int numTemps)
{
    float lowest = temps[0];
    for (int i = 1; i < numTemps; i++) {
        if (temps[i] < lowest) {
            lowest = temps[i];
        }
    }
    return lowest;
}