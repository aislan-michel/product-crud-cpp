#include <iostream>
#include <vector>
#include <list>  
#include "Entities/Product.h"

using namespace std;

int main()
{
    list<Product> products;

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

                for(Product product : products)
                {
                    if (product.Id == id)
                    {
                        productToUpdate = product;
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

                for (auto product = products.rbegin( ); product != products.rend( ); product++)
                {
                    if (product->Id == productToUpdate.Id)
                    {
                        product->Name = name;
                        product->Price = price;
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

                Product productToDelete;

                for(Product product : products)
                {
                    if (product.Id == id)
                    {
                        productToDelete = product;
                        break;
                    }
                }

                if (productToDelete.Id != id)
                {
                    cout << "not found" << endl;
                    break;
                }

                cout << "\nid: " + to_string(productToDelete.Id) + " | name: " + productToDelete.Name + " | price: " + to_string(productToDelete.Price) + "\n" << endl;

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
