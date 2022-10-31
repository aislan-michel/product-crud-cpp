#include <iostream>
#include <vector>

using namespace std;

static int _id = 0;

class Product
{
public:
    int Id;
    string Name;
    double Price;

    Product( )
    {

    }

    Product(string name, double price)
    {
        Id = _id++;
        Name = name;
        Price = price;
    }

    void Update(string name, double price) 
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

    cout << "\nWelcome! What do you want to do?" << endl;
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

                cout << "created!" << endl;

                break;
            }
            case 2:
            {
                if (products.size() == 0)
                {
                    cout << "\nno data\n" << endl;
                    break;
                }

                string list("\nProducts:");
                for(Product product : products)
                {
                    list.append("\nid: " + to_string(product.Id) + " | name: " + product.Name + " | price: " + to_string(product.Price));
                }

                cout << list << endl;

                break;
            }

            case 3:
            {
                int id = 0;

                cout << "Product Id: ";
                cin >> id;

                Product productToUpdate;
                int productToUpdateIndex;

                for (int i = 0; i < products.size(); i++)
                {
                    if (products[i].Id == id)
                    {
                        productToUpdate = products[i];
                        productToUpdateIndex = i;
                        break;
                    }
                }

                if (productToUpdate.Id != id)
                {
                    cout << "not found" << endl;
                    break;
                }

                cout << "\nid: " + to_string(productToUpdate.Id) + " | name: " + productToUpdate.Name + " | price: " + to_string(productToUpdate.Price) + "\n" << endl;

                string name = "";
                double price = 0.0;

                cout << "\nNew product name: ";
                cin >> name;
                cout << "New product price: ";
                cin >> price;

                productToUpdate.Update(name, price);

                products[productToUpdateIndex] = productToUpdate;

                cout << "updated!" << endl;

                break;
            }

            default:
            {
                cout << "\ninvalid option\n" << endl;
                cout << options;
                cin >> option;
            }
        }

        cout << options;
        cin >> option;
    }

    cout << "\nsee you later!" << endl;

    system("pause>0");
}
