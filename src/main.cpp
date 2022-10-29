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

    Product products[10] = {};

    cout << welcome + " How many product you do create? ";
    cin >> productsToCreate;

    for (int i = 0; i < productsToCreate; i++)
    {
        cout << "\nProduct name: ";
        cin >> products[i].Name;
        cout << "Product price: ";
        cin >> products[i].Price;
    }

    cout << "\nProducts:\n";
    for (int i = 0; i < productsToCreate; i++)
    {
        cout << "product: " << products[i].Name + " - price: " << products[i].Price << "$\n";
    }

    cout << "\n";

	system("pause>0");
}
