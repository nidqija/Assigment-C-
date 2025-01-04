//RAZIQ DIN BIN MOHD TASRIRI

#include <iostream>
#include <gradfile.txt>

using namespace std;

typedef int GradeType[100]; // declares a new data type

float findAverage(const GradeType, int);  // finds average of all grades
int findHighest(const GradeType, int);   // finds highest of all grades
int findLowest(const GradeType, int);    // finds lowest of all grades

int main() {
    GradeType grades;        // the array holding the grades
    int numberOfGrades = 0;  // the number of grades read
    int pos = 0;             // index to the array
    float avgOfGrades;       // contains the average of the grades
    int highestGrade;        // contains the highest grade
    int lowestGrade;         // contains the lowest grade

    cout << "Please input a grade from 1 to 100, (or -99 to stop):" << endl;
    cin >> grades[pos];

    while (grades[pos] != -99) {
        // Ensure valid grades are within the range
        if (grades[pos] >= 1 && grades[pos] <= 100) {
            pos++;
        } else {
            cout << "Invalid grade. Please enter a grade between 1 and 100:" << endl;
        }
        cin >> grades[pos];
    }

    numberOfGrades = pos; // Store the number of valid grades entered

    if (numberOfGrades > 0) {
        avgOfGrades = findAverage(grades, numberOfGrades);
        highestGrade = findHighest(grades, numberOfGrades);
        lowestGrade = findLowest(grades, numberOfGrades);

        cout << endl << "The average of all the grades is " << avgOfGrades << endl;
        cout << "The highest grade is " << highestGrade << endl;
        cout << "The lowest grade is " << lowestGrade << endl;
    } else {
        cout << "No valid grades were entered." << endl;
    }

    return 0;
}

float findAverage(const GradeType array, int size) {
    float sum = 0; // holds the sum of all the numbers
    for (int pos = 0; pos < size; pos++) {
        sum += array[pos];
    }
    return (sum / size); // returns the average
}

int findHighest(const GradeType array, int size) {
    int highest = array[0]; // assume the first grade is the highest
    for (int pos = 1; pos < size; pos++) {
        if (array[pos] > highest) {
            highest = array[pos];
        }
    }
    return highest;
}

int findLowest(const GradeType array, int size) {
    int lowest = array[0]; // assume the first grade is the lowest
    for (int pos = 1; pos < size; pos++) {
        if (array[pos] < lowest) {
            lowest = array[pos];
        }
    }
    return lowest;
}
