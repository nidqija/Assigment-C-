#include <iostream>
using namespace std;

// Declaration of the Square class
class Square
{
private:
    float side; // Holds the length of a side of the square

public:
    // Default constructor
    Square();

    // Parameterized constructor
    Square(float length);

    // Destructor
    ~Square();

    // Sets the side length of the square
    void setSide(float length);

    // Calculates and returns the area of the square
    float findArea();

    // Calculates and returns the perimeter of the square
    float findPerimeter();
};

// Implementation of the default constructor
Square::Square()
{
    side = 1; // Default side length is set to 1
    cout << "Default constructor called. Side initialized to 1." << endl;
}

// Implementation of the parameterized constructor
Square::Square(float length)
{
    side = length; // Initialize the side with the given length
    cout << "Parameterized constructor called. Side initialized to " << side << "." << endl;
}

// Implementation of the destructor
Square::~Square()
{
    cout << "Destructor called for a square with side " << side << "." << endl;
}

// Implementation of setSide
void Square::setSide(float length)
{
    side = length;
}

// Implementation of findArea
float Square::findArea()
{
    return side * side;
}

// Implementation of findPerimeter
float Square::findPerimeter()
{
    return 4 * side;
}

int main()
{
    // Default constructor
    Square box; // box is defined as an object of the Square class

    float size; // size contains the length of a side of the square
    cout << "Enter the length of a side of the square: ";
    cin >> size;

    // Call setSide to set the length of the square's side
    box.setSide(size);

    // Call findArea and print the area to the screen
    cout << "The area of the square is: " << box.findArea() << endl;

    // Call findPerimeter and print the perimeter to the screen
    cout << "The perimeter of the square is: " << box.findPerimeter() << endl;

    // Parameterized constructor
    Square box1(9); // box1 is defined with an initial side length of 9
    cout << "The area of box1 is: " << box1.findArea() << endl;
    cout << "The perimeter of box1 is: " << box1.findPerimeter() << endl;

    return 0;
}
