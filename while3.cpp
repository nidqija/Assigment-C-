#include <iostream>

using namespace std;

int main(){
  char letter = 'a';

    cout << "Please enter a letter" << endl;
    cin >> letter;

  do {
    cout << "The letter is incorrect" << endl;
    cout << "Please enter another letter" << endl;
    cin >> letter;
  }

  while (letter != 'x');

  cout << "The letter that you have entered is " << letter <<endl;



}
