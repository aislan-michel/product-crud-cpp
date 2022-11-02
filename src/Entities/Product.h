#ifndef PRODUCT_H
#define PRODUCT_H
#include <random>

using namespace std;

class Product
{
private:
    static int RandomNumber()
    {
	    random_device rd; // obtain a random number from hardware
        mt19937 gen(rd()); // seed the generator
        uniform_int_distribution<> distr(1, 100); // define the range

	    return distr(gen);
    }

public:
    int id;
    string name;
    double price;

    bool operator == (const Product& s) const { return name == s.name && id == s.id; }
    bool operator != (const Product& s) const { return !operator==(s); }

    Product( );

    Product(string name, double price);

    string toString() const;

};
#endif // PRODUCT_H
