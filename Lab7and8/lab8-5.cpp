#include <iostream>
using namespace std;

// Class declaration section
class Circles
{
public:
    // Overloaded constructors
    Circles(float r, int x, int y); // Constructor for radius and center
    Circles(float r);               // Constructor for radius only
    Circles(int x, int y);          // Constructor for center only
    Circles();                      // Default constructor

    // Destructor
    ~Circles();                    // Destructor

    // Member functions
    void setCenter(int x, int y);
    double findArea();
    double findCircumference();
    void printCircleStats();

private:
    float radius;
    int center_x;
    int center_y;
};

const double PI = 3.14;

// Client section
int main()
{
    // Create objects using different constructors
    Circles sphere1(2);            // Radius = 2, center defaults to (0, 0)
    Circles sphere2;               // Default radius and center
    Circles sphere3(15, 16);       // Radius defaults to 1, center = (15, 16)

    // Display details for sphere1
    cout << "Sphere 1:" << endl;
    sphere1.printCircleStats();
    cout << "The area of the circle is " << sphere1.findArea() << endl;
    cout << "The circumference of the circle is "
         << sphere1.findCircumference() << endl
         << endl;

    // Display details for sphere2
    cout << "Sphere 2:" << endl;
    sphere2.printCircleStats();
    cout << "The area of the circle is " << sphere2.findArea() << endl;
    cout << "The circumference of the circle is "
         << sphere2.findCircumference() << endl
         << endl;

    // Display details for sphere3
    cout << "Sphere 3:" << endl;
    sphere3.printCircleStats();
    cout << "The area of the circle is " << sphere3.findArea() << endl;
    cout << "The circumference of the circle is "
         << sphere3.findCircumference() << endl
         << endl;

    return 0;
}

// Implementation section

// Constructor for radius and center
Circles::Circles(float r, int x, int y) : radius(r), center_x(x), center_y(y)
{
    cout << "Constructor called: radius = " << radius
         << ", center = (" << center_x << ", " << center_y << ")" << endl;
}

// Constructor for radius only
Circles::Circles(float r) : radius(r), center_x(0), center_y(0)
{
    cout << "Constructor called: radius = " << radius
         << ", center = (0, 0)" << endl;
}

// Constructor for center only
Circles::Circles(int x, int y) : radius(1), center_x(x), center_y(y)
{
    cout << "Constructor called: radius = 1"
         << ", center = (" << center_x << ", " << center_y << ")" << endl;
}

// Default constructor
Circles::Circles() : radius(1), center_x(0), center_y(0)
{
    cout << "Default constructor called: radius = 1, center = (0, 0)" << endl;
}

// Destructor
Circles::~Circles()
{
    cout << "This concludes the Circles class" << endl;
}

// Member function to calculate area
double Circles::findArea()
{
    return PI * radius * radius;
}

// Member function to calculate circumference
double Circles::findCircumference()
{
    return 2 * PI * radius;
}

// Member function to print circle stats
void Circles::printCircleStats()
{
    cout << "The radius of the circle is " << radius << endl;
    cout << "The center of the circle is (" << center_x << ", " << center_y << ")" << endl;
}

// Member function to set the center of the circle
void Circles::setCenter(int x, int y)
{
    center_x = x;
    center_y = y;
}
