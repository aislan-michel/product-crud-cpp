#include "Entities/Product.h"
#include <iostream>
#include <list>  
#include <string>

using namespace std;

list<Product> products;

Product getById(const int id)
{
    for(Product product : products)
    {
        if (product.id == id)
        {
            return product;
        }
    }

    return {};
}

int main()
{
    int option = 0;

    cout << "\nWelcome! What do you want to do?" << endl;
    string options;
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
                string name;
                double price = 0.0;
                cout << "\nProduct name: ";
                cin >> name;
                cout << "Product price: ";
                cin >> price;

                products.emplace_back(name, price);

                cout << "created!" << endl;

                break;
            }
            case 2:
            {
                if (products.empty())
                {
                    cout << "\nno data\n" << endl;
                    break;
                }

                string list("\nProducts:");
                for(const Product& product : products)
                {
                    list.append(product.toString());
                }

                cout << list << endl;

                break;
            }
            
            case 3:
            {
                int id = 0;

                cout << "Product Id: ";
                cin >> id;

                Product productToUpdate = getById(id);

                if (productToUpdate.id != id)
                {
                    cout << "not found" << endl;
                    break;
                }

                cout << productToUpdate.toString() << endl;

                string name;
                double price = 0.0;

                cout << "\nNew product name: ";
                cin >> name;
                cout << "New product price: ";
                cin >> price;

                for (auto product = products.rbegin( ); product != products.rend( ); ++product)
                {
                    if (product->id == productToUpdate.id)
                    {
                        product->name = name;
                        product->price = price;
                    }
                }

                cout << "updated!" << endl;

                break;
            }
            
            case 4:
            {
                int id = 0;

                cout << "Product Id: ";
                cin >> id;

                Product productToDelete = getById(id);

                if (productToDelete.id != id)
                {
                    cout << "not found" << endl;
                    break;
                }

                cout << productToDelete.toString() << endl;

                string response;

                cout << "\nArea you sure (y/n)? ";
                cin >> response;

                if (response == "y")
                {
                    products.remove(productToDelete);

                    cout << "deleted!" << endl;

                    break;
                }

                cout << "not deleted!" << endl;

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

