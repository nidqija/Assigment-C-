#include <iostream>
#include <fstream>

using namespace std;

int main(){

  ofstream file;
  int n;
  int num = 10;


  file.open("database.txt");

  for (n = 0; n < num; ++n){
    file << setw(20) << n << setw(20) << angle[n] << setw(20) << t[n] << setw(20) << y[n] << setw(20) << x[n] << endl;
   }

   cout << "File opened successfully!" << endl;
   file.close();

   return 0;
}
