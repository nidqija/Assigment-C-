#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include  <bits/stdc++.h>
#include <string>


using namespace std;


int main(){

 string InputCommands;
 fstream file;
 string fileName;
 bool isTrue = true;

while (isTrue) {


//variable to take different types of input
cin >> InputCommands;

//create a textfile
 if (InputCommands == "CREATE")
 {

    cout << "Enter filename";
    cin >> fileName;
  	 file.open(fileName , ios::out | ios::app);
 	 file.close();
    cout << "File successfully created!";

 }


else if (InputCommands == "DATABASES")
{
	
   ifstream f(fileName);
   string s;
   while (getline(f,s))
   cout << s << endl;
   f.close();

}
else if (InputCommands == "CREATE DATABASE")
{

}
  }


	

	return 0;


}
