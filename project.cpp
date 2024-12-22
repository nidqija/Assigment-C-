#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include  <bits/stdc++.h>
#include <string>


using namespace std;


int main(){

 char InputCommands[200];
 fstream file;
 bool isTrue = true;

while (isTrue){

//variable to take different types of input
cin.getline(InputCommands , 200);

//create a textfile
 if (InputCommands == "CREATE" || "Create" || "create")
 {

    string fileName;
    cout << "Enter filename";
    cin >> fileName;
  	file.open(fileName , ios::out | ios::app);
  	file.close();

 } 

//Open a textfile based on user input


 
} 
 
   
	



	

	

	return 0;
}
