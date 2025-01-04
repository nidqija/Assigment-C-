#include <iostream>
#include <fstream>
using namespace std;

// This program declares a class called Inventory that has itemNumber (which
// contains the id number of a product) and numOfItem (which contains the
// quantity on hand of the corresponding product) as private data members.
// The program will read these values from a file and store them in an
// array of objects (of type Inventory). It will then print these values
// to the screen.

const int NUMOFPROD = 10; // This holds the number of products a store sells

// Class Inventory
class Inventory
{
public:
    void getId(int item)   // This puts item in the private data member
                           // itemNumber of the object that calls it.
    {
        itemNumber = item;
    }

    void getAmount(int num) // This puts num in the private data member
                            // numOfItem of the object that calls it.
    {
        numOfItem = num;
    }

    void display()          // This prints to the screen the value of itemNumber
                            // and numOfItem of the object that calls it.
    {
        cout << "Item number " << itemNumber << " has " << numOfItem
             << " items in stock" << endl;
    }

private:
    int itemNumber;    // This is an id number of the product
    int numOfItem;     // This is the number of items in stock
};

int main()
{
    ifstream infile;  // Input file to read values into array
    infile.open("Inventory.dat");  // Open the file for reading

    if (!infile) {  // Check if the file was successfully opened
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Define an array of objects of class Inventory called products.
    Inventory products[NUMOFPROD];

    int pos = 0; // loop counter
    int id;      // variable holding the id number
    int total;   // variable holding the total for each id number

    // Read inventory numbers and number of items from a file into the array of objects
    while (infile >> id >> total && pos < NUMOFPROD)
    {
        products[pos].getId(id);    // Call getId to set the id number
        products[pos].getAmount(total); // Call getAmount to set the number of items
        pos++;  // Move to the next position in the array
    }

    // Close the file after reading the data
    infile.close();

    // Print out the values (itemNumber and numOfItem) for each object in the array products
    for (int i = 0; i < pos; i++) {
        products[i].display();  // Call display to print the item details
    }

    return 0;
}
