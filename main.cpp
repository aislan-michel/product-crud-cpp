// C++ program to display "Hello World"

// Header file for input output functions
#include <iostream>
using namespace std;

// Main() function: where the execution of program begins

//cout << "print"

class Product{
public:
    string Name;
    double Price;
};

int main()
{
    const string welcome = "Welcome!";

    Product products[] = {};

    Product newProduct;

    cout << "Product name: ";
    cin >> newProduct.Name;
    cout << "Product price: ";
	cin >> newProduct.Price;

    cout << "\nproduct: " << newProduct.Name;
    cout << "\nprice: " << newProduct.Price;

    

	system("pause>0");
}
