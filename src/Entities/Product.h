#include <iostream>
#include <string>
#include <random>

using namespace std;

class Product
{
public:
    int Id;
    string Name;
    double Price;

    bool operator == (const Product& s) const { return Name == s.Name && Id == s.Id; }
    bool operator != (const Product& s) const { return !operator==(s); }

    Product( )
    {

    }

    Product(string name, double price)
    {
        Id = RandomNumber();
        Name = name;
        Price = price;
    }

private:
    int RandomNumber()
    {
	    random_device rd; // obtain a random number from hardware
        mt19937 gen(rd()); // seed the generator
        uniform_int_distribution<> distr(1, 100); // define the range

	    return distr(gen);
    }
};