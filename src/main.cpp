#include <iostream>
#include <vector>

using namespace std;

class Product
{
public:
    string Name;
    double Price;

    Product(string name, double price)
    {
        Name = name;
        Price = price;
    }
};

int main()
{
    vector<Product> products;

    int productsToCreate = 0;
    int option = 0;

    cout << "\nWelcome! What do you want to do?";
    string options("");
    options.append("\n1 - Create");
    options.append("\n2 - Read");
    options.append("\n3 - Update");
    options.append("\n4 - Delete");
    options.append("\n0 - Quit\n");
    options.append("\nType number of option: ");
    cout << options;
    cin >> option;

    while (option > 0)
    {
        switch (option)
        {
            case 1:
            {
                string name = "";
                double price = 0.0;
                cout << "\nProduct name: ";
                cin >> name;
                cout << "Product price: ";
                cin >> price;

                products.push_back(Product(name, price));

                break;
            }
            case 2:
                if (products.size() == 0)
                {
                    cout << "\nno data\n";
                    break;
                }

                cout << "\nProducts:\n";
                for (int i = 0; i < products.size(); i++)
                {
                    cout << "product: " << products[i].Name + " - price: " << products[i].Price << "$\n";
                }

                break;

            default:
                cout << "\ninvalid option\n";
                cout << options;
                cin >> option;
        }

        cout << options;
        cin >> option;
    }

    cout << "\nsee you later!";

    system("pause>0");
}
