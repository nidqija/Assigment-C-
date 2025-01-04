#include <iostream>
#include <limits>
using namespace std;

// Define a structure to hold the information for each month
struct AirportData {
    int planesLanded;      // Total number of planes that landed in the month
    int planesDeparted;    // Total number of planes that departed in the month
    int maxLandings;       // Greatest number of planes that landed on a given day
    int minLandings;       // Least number of planes that landed on a given day
};

int main() {
    // Define an array of structures to hold data for each month
    AirportData data[12];

    // Variables to store cumulative totals and statistics
    int totalLandings = 0;
    int totalDepartures = 0;
    int greatestLandings = 0;
    int leastLandings = INT_MAX;
    int monthGreatestLandings = 0;
    int monthLeastLandings = 0;

    // Prompt the user to enter data for each month
    for (int month = 0; month < 12; ++month) {
        cout << "\nEnter data for month " << month + 1 << ":\n";

        // Get total planes that landed
        cout << "Enter total number of planes that landed: ";
        cin >> data[month].planesLanded;

        // Get total planes that departed
        cout << "Enter total number of planes that departed: ";
        cin >> data[month].planesDeparted;

        // Get the greatest number of planes that landed in a given day
        cout << "Enter the greatest number of planes that landed in a single day: ";
        cin >> data[month].maxLandings;

        // Get the least number of planes that landed in a given day
        cout << "Enter the least number of planes that landed in a single day: ";
        cin >> data[month].minLandings;

        // Update cumulative totals
        totalLandings += data[month].planesLanded;
        totalDepartures += data[month].planesDeparted;

        // Update the greatest and least landings and track the month
        if (data[month].maxLandings > greatestLandings) {
            greatestLandings = data[month].maxLandings;
            monthGreatestLandings = month + 1; // Store the month number
        }

        if (data[month].minLandings < leastLandings) {
            leastLandings = data[month].minLandings;
            monthLeastLandings = month + 1; // Store the month number
        }
    }

    // Calculate the average monthly landings and departures
    double avgLandings = static_cast<double>(totalLandings) / 12.0;
    double avgDepartures = static_cast<double>(totalDepartures) / 12.0;

    // Output the results
    cout << "\nYearly Statistics:\n";
    cout << "Total number of planes that landed this year: " << totalLandings << endl;
    cout << "Total number of planes that departed this year: " << totalDepartures << endl;
    cout << "Average monthly number of landings: " << avgLandings << endl;
    cout << "Average monthly number of departures: " << avgDepartures << endl;
    cout << "The greatest number of planes that landed on a single day: " << greatestLandings
         << " in month " << monthGreatestLandings << endl;
    cout << "The least number of planes that landed on a single day: " << leastLandings
         << " in month " << monthLeastLandings << endl;

    return 0;
}
