//Program : project.cpp
//Course : CCP6114 Programming Fundamentals
//Lecture Class : TC3L
//Tutorial Class : TT5L
//Trimester :2430
//Member_1: 242UC244Q7 | RAZIQ DIN BIN MOHD TASRIRI | RAZIQ.DIN.MOHD@STUDENT.MMU.EDU.MY | 0193214659
//Member_2: 242UC244M5 | JIREH CHAI E-LOK | JIREH.CHAI.ELOK@student.mmu.edu.my | 0125131505


//TASK DISTRIBUTION
//MEMBER_1:
//MEMBER_2:
//MEMBER_3:




#include <iostream>
#include <vector>
#include <fstream>
#include<string>
#include<sstream>
using namespace std;


void DisplayMessage();
void Create(string fileName);
void CreateTable ( string fileName , string tableName , string tableData);
void viewDatabase();
void InsertInto(string fileName);
void viewTables(string fileName);




int main(){
   string fileName;
   string commands;
   const int size=10;
   const char comma = ",";
   string CSVline , CSVrow;
   DisplayMessage();
   cout << "Enter your commands" << endl;


while (true){

 getline(cin , commands);


 if (commands == "CREATE")
 { 
    cout << "Enter your the name of your file" << endl;
    cin >> fileName;
    Create(fileName);
 }

 else if (commands == "CREATE TABLE")
 {
   string tableName;
   string tableData;
   cout << "Enter file name: ";
   cin >> fileName;
   cin >> tableName;
   while (true){
    string line;
    getline(cin , line);

    if (line == ";"){
      cout << "Thank you!" << endl;
      break;
    }
    tableData += line + "," ;
   }
    CreateTable(fileName , tableName , tableData);
    cout << "Table created successfully!" << endl;
 }

 else if (commands == "DATABASES"){
    viewDatabase();
 }

 else if (commands == "INSERT INTO"){
    cout << "Enter file name:" << endl;
    cin >> fileName;
    InsertInto(fileName);
 }

 else if (commands == "VIEW TABLE"){
    cout << "Enter file name to view table:" << endl;
    cin >> fileName;
    viewTables(fileName);
    }

 


}






return 0;

}


// Create a new textfile

void Create(string fileName){
   fstream file;
   fstream fileDatabase;
   fileDatabase.open("databases.txt" , ios :: out | ios :: app);
   fileDatabase << fileName << endl;
   fileDatabase.close();
   file.open(fileName , ios::out | ios::app);
   file.close();
   cout << "file created successfully" << endl;



}


// Create a new table

void CreateTable(string fileName, string tableName, string tableData) {
    ofstream file;
    file.open(fileName, ios::out | ios::app);
    if (file.is_open()) {
        file << "Table name: " << tableName << endl;
        file << tableData << endl;
        file.close();
    } else {
        cout << "Error opening file" << endl;
    }
}


// View Databases

void viewDatabase(){
  ifstream f("databases.txt");
  string s;
  while (getline(f,s))
    cout << s << endl;
    f.close();
}


//Insert Key Values in table

void InsertInto(string fileName)

{
  const int size = 10;

  string Data[size];
  string tableKeyValues;
  string s;
  ofstream file;
  ifstream f(fileName);

  while(getline(f,s))
    cout << s << endl;
    f.close();

  cout << "Enter your key values" << endl;
  file.open(fileName, ios::out | ios::app);
  if (file.is_open()){
    while(true){
        getline(cin,Data[0]) ;
        tableKeyValues += Data[0] + "," ;
        if (Data[0] == ";"){
        cout << "thank you for the input , saving!" << endl;
         file << tableKeyValues<< endl;
         file.close();
         break; 
       }
       } 


  } else{
    cout << "Error opening file" << endl;
  }

   
    cout << "Thank you for the key values!" << endl;

}






//Display Messages and Instructions

void DisplayMessage(){
  cout << "Welcome to Light Mariadb Interpreter"<< endl;
  cout << "Input your commands" << endl;
  cout << "1.CREATE" << endl;
  cout << "2.CREATE TABLE" << endl;
  cout << "3.VIEW TABLE" << endl;
  cout << "4.INSERT INTO" << endl;
  cout << "5.SELECT" << endl;
  cout << "6.UPDATE" << endl;
  cout << "7.DELETE" << endl;
  cout << "8.DATABASES" << endl;
  cout << "9.VIEW CSV" << endl;

}

void viewTables(string fileName){
    ifstream file(fileName);
    string line;

    if (file.is_open()){
        cout << "contents of " << fileName << ":\n";
        while (getline(file, line)){
            cout << line << endl;
        }
        file.close();
    } else {
    cout << "Error: could not open file " << fileName << endl;
    }
}


void UpdateData(string fileName){
  ifstream file(fileName);

}


