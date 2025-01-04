#include <iostream>
#include <iomanip>
using namespace std;

// This program uses a structure to hold data about a rectangle

// RAZIQ DIN BIN MOHD TASRIRI

// Fill in code to declare a structure named rectangle which has
// members length, width, area, and perimeter all of which are floats



int main()
{
   // Fill in code to define a rectangle variable named box
   float rectangleArea , rectanglePerimeter , division;
   float rectangle_length , rectangle_width;
   
   cout << "Enter the length of a rectangle: ";
   
   // Fill in code to read in the length member of box
   cin >> rectangle_length;
   
   cout << "Enter the width of a rectangle: ";

   // Fill in code to read in the width member of box
   cin >> rectangle_width;

   cout << endl << endl;

   // Fill in code to compute the area member of box
   rectangleArea = rectangle_width * rectangle_length;


   // Fill in code to compute the perimeter member of box
   rectanglePerimeter = 2*(rectangle_width) + 2*(rectangle_length);

   cout << fixed << showpoint << setprecision(2);

   // Fill in code to output the area with an appropriate message
   // Fill in code to output the perimeter with an appropriate message

   cout << "Area: " << rectangleArea << endl;
   cout << "Perimeter: " << rectanglePerimeter << endl;


 if (rectangle_width == rectangle_length){
      cout << "This rectangle is a square" << endl;
   } else {
      cout << "This rectangle is not a square" << endl;
   }


   return 0; 
}