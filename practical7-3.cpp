/* Programmer : Prince Halpara
   Date : 05 May, 2025
   Aim : Build a simple inventory system using file handling to add, view, and search products (space-separated)
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// Add new product to file
void addProduct()
{
    ofstream fout("inventory.txt", ios::app);
    string name;
    int qty;
    float price;

    cout << "Enter product name: ";
    cin >> name;
    cout << "Enter quantity: ";
    cin >> qty;
    cout << "Enter price: ";
    cin >> price;

    fout << name << " " << qty << " " << price << "\n";
    fout.close();
    cout << "Product added.\n";
}

// View all products
void viewInventory()
{
    ifstream fin("inventory.txt");
    string name;
    int qty;
    float price;

    cout << "\nInventory:\n";
    while (fin >> name >> qty >> price)
    {
        cout << name << " " << qty << " " << price << endl;
    }

    fin.close();
}

// Search product by name
void searchProduct()
{
    ifstream fin("inventory.txt");
    string name, searchName;
    int qty;
    float price;
    bool found = false;

    cout << "Enter product name to search: ";
    cin >> searchName;

    while (fin >> name >> qty >> price)
    {
        if (name == searchName)
        {
            cout << "Found: " << name << " " << qty << " " << price << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Product not found.\n";

    fin.close();
}

int main()
{
    int choice;

    do
    {
        cout << "\n1. Add Product\n2. View Inventory\n3. Search Product\n0. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) addProduct();
        else if (choice == 2) viewInventory();
        else if (choice == 3) searchProduct();
        else if (choice != 0) cout << "Invalid choice.\n";

    }
    while (choice != 0);

    cout << "\nPrince Halpara:: 24CE038" << endl;
    cout << endl;
    return 0;
}
