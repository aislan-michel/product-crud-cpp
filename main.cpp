#include <iostream>
using namespace std;

class Product{
public:
    string Name;
    double Price;
};

int main()
{
    int productsToCreate = 0;
    const string welcome = "Welcome!";

    Product products[] = {};


    cout << welcome + " How many product you do create? ";
    cin >> productsToCreate;

    for (int i = 0; i < productsToCreate; i++)
    {
        cout << "Product name: ";
        cin >> products[i].Name;
        cout << "Product price: ";
        cin >> products[i].Price;
    }

    for (int i = 0; i < productsToCreate; i++)
    {
        cout << "\nproduct: " << products[i].Name;
        cout << "\nprice: " << products[i].Price;
    }

	system("pause>0");
}
