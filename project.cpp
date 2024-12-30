//Program : project.cpp
//Course : CCP6114 Programming Fundamentals
//Lecture Class : TC3L
//Tutorial Class : TT5L
//Trimester :2430
//Member_1: 242UC244Q7 | RAZIQ DIN BIN MOHD TASRIRI | RAZIQ.DIN.MOHD@STUDENT.MMU.EDU.MY | 019321459
//Member_2: ID | NAME | EMAIL | PHONENUMBER
//Member_3: ID | NAME | EMAIL | PHONENUMBER

//TASK DISTRIBUTION
//MEMBER_1:
//MEMBER_2:
//MEMBER_3:




#include <iostream>
#include <vector>
#include <fstream>
#include<string>

using namespace std;


void DisplayMessage();
void Create(string fileName);
void CreateTable ( string fileName , string tableName , string tableData);
void viewDatabase();

int main(){
   string fileName;
   string commands;
   DisplayMessage();
   cout << "Enter your commands" << endl;


while (true){

 getline(cin , commands);

 
 if (commands == "CREATE")
 {
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
    tableData += line + " " ;
   }
    CreateTable(fileName , tableName , tableData);
    cout << "Table created successfully!" << endl;
 }

 else if (commands == "DATABASES"){
    viewDatabase();
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





void DisplayMessage(){
  cout << "Welcome to Light Mariadb Interpreter"<< endl;
  cout << "Input your commands" << endl;
  cout << "1.CREATE" << endl;
  cout << "2.CREATE TABLE" << endl;
  cout << "3.TABLES" << endl;
  cout << "4.INSERT INTO" << endl;
  cout << "5.SELECT" << endl;
  cout << "6.UPDATE" << endl;
  cout << "7.DELETE" << endl;
  cout << "8.DATABASES" << endl;
  
}


