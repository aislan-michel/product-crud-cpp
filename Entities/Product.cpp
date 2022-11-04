#include "Product.h"

#include <string>

using namespace std;

Product::Product( )
{

}

Product::Product(const string _name, const double _price)
{
    id = RandomNumber();
    name = _name;
    price = _price;
}

string Product::toString( ) const
{
    return "\nid: " + to_string(id) + " | name: " + name + " | price: " + to_string(price);
}


