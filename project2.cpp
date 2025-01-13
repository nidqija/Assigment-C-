#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void DisplayMessage();
int InsertInto(vector<vector<string>>& NameVector, ifstream& inputFiles);
int InsertTable(vector<vector<string>>& NameVector2, ifstream& inputFiles);

int main() {
    ifstream inputFiles("input.txt");
    ofstream outputFiles("output.txt");
    string tableDataValues;
    string tableColumnValues;
    vector<vector<string>> wordsVector;
    vector<vector<string>> wordsVector2;

    // Check if input and output files are open
    if (!inputFiles.is_open()) {
        cout << "Cannot open input file" << endl;
        return -1;
    }

    if (!outputFiles.is_open()) {
        cout << "Cannot open output file" << endl;
        return -1;
    }

    // Display the welcome message
    DisplayMessage();

    // Insert table into the vector
    InsertTable(wordsVector2, inputFiles);

    // Reset file cursor for reuse
    inputFiles.clear();
    inputFiles.seekg(0, ios::beg);

    // Insert data into the vector
    InsertInto(wordsVector, inputFiles);

    // Process and write table data
    for (const vector<string>& row2 : wordsVector2) {
        tableColumnValues.clear();
        for (const string& word2 : row2) {
            tableColumnValues += word2 + ",";
            cout << word2 << " ";
        }
        cout << endl;
        outputFiles << tableColumnValues << endl;
    }

    // Process and write row data
    for (const vector<string>& row : wordsVector) {
        tableDataValues.clear();
        for (const string& word : row) {
            tableDataValues += word + ",";
            cout << word << " ";
        }
        cout << endl; // Print each row on a new line
        outputFiles << tableDataValues << endl;
    }

    inputFiles.close();
    outputFiles.close();

    return 0;
}

int InsertInto(vector<vector<string>>& NameVector, ifstream& inputFiles) {
    string line;
    while (getline(inputFiles, line)) {
        if (line.find("VALUES(") != string::npos && line.find(");") != string::npos) {
            int valuesStartPosition = line.find("VALUES(") + 7;
            int valueEndPosition = line.find(");");

            string valuesData = line.substr(valuesStartPosition, valueEndPosition - valuesStartPosition);
            stringstream valuesDataSS(valuesData);
            string word;
            vector<string> row; // for 2D vector

            while (getline(valuesDataSS, word, ',')) {
                // Remove leading and trailing single quotes
                if (word.front() == '\'' && word.back() == '\'' && word.size() > 1) {
                    word = word.substr(1, word.size() - 2);
                }
                row.push_back(word);
            }

            NameVector.push_back(row);
        }
    }

    return 0;
}

int InsertTable(vector<vector<string>>& NameVector2, ifstream& inputFiles) {
    string line2;
    while (getline(inputFiles, line2)) {
        if (line2.find("customer(") != string::npos && line2.find(");") != string::npos) {
            int valuesStartPosition = line2.find("customer(") + 9; // take out line for "customer("
            int valueEndPosition = line2.find(");"); // take out line for ");" at the end of the line
            string valuesData2 = line2.substr(valuesStartPosition, valueEndPosition - valuesStartPosition);
            stringstream valuesDataSS2(valuesData2);
            string word2;
            vector<string> row2;

            while (getline(valuesDataSS2, word2, ',')) {
                size_t not_tFirst = word2.find_first_not_of(" \t"); //eliminate the word "INT" in the line
                size_t not_tLast = word2.find_last_not_of(" \t"); //eliminate the word "TEXT" in the line
                if (not_tFirst != string::npos && not_tLast != string::npos) {
                    word2 = word2.substr(not_tFirst, not_tLast - not_tFirst + 1);
                }

                size_t PositionSpace = word2.find(" "); 
                if (PositionSpace != string::npos) {
                    word2 = word2.substr(0, PositionSpace); 
                }

                row2.push_back(word2); // Add column name to the row
            }
            NameVector2.push_back(row2); // Add row to the table
        }
    }
    return 0;
}


void DisplayMessage() {
    cout << "Welcome to Light Mariadb Interpreter" << endl;
    cout << "Input your commands" << endl;
    cout << "1. CREATE" << endl;
    cout << "2. CREATE TABLE" << endl;
    cout << "3. VIEW TABLE" << endl;
    cout << "4. INSERT INTO" << endl;
    cout << "5. SELECT" << endl;
    cout << "6. UPDATE" << endl;
    cout << "7. DELETE" << endl;
    cout << "8. DATABASES" << endl;
    cout << "9. VIEW CSV" << endl;
}
