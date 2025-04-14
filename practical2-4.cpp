/* Programmer : Prince Halpara
   Aim : Build a system for efficient inventory tracking and stock management
   Date : 24 February, 2025
   */

#include <iostream>
using namespace std;

class Item {
private:
    int item_id;
    string item_name;
    double item_price;
    int item_quantity;

public:
    // Constructor with default values
    Item(int id = 0, string n = "Unknown", double p = 0.0, int q = 0)
        : item_id(id), item_name(n), item_price(p), item_quantity(q) {}

    // Method to add stock
    void addItem(int q) {
        if (q > 0) {
            item_quantity += q;
            cout << "Item added successfully!" << endl;
            cout << "New quantity: " << item_quantity << endl;
        } else {
            cout << "Invalid quantity!" << endl;
        }
    }

    // Method to sell items
    void sellItem(int q) {
        if (q > 0 && item_quantity >= q) {
            item_quantity -= q;
            cout << "Item sold successfully!" << endl;
            cout << "New quantity: " << item_quantity << endl;
        } else {
            cout << "Invalid quantity or insufficient stock!" << endl;
        }
    }

    // Display method
    void display() {
        cout << "Item Details:" << endl;
        cout << "ID: " << item_id << endl;
        cout << "Name: " << item_name << endl;
        cout << "Price: " << item_price << endl;
        cout << "Quantity: " << item_quantity << endl;
    }

    // Getter for item ID
    int getID() { return item_id; }
};

int main() {
    int choice, id, q;

    // Correct initialization of the array
    Item items[3] = {
        Item(),
        Item(101, "Mobile", 1000, 10),
        Item(102, "Power Bank", 550, 10)
    };

    do
    {
        cout << "1. Add Items\n2. Sell Items\n3. Display Details\n4. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter the ID of the item: ";
                cin >> id;
                cout << "Enter the quantity to add: ";
                cin >> q;

                if (id == 101 || id == 102)
                {
                    items[id - 100].addItem(q);
                }
                else
                {
                    cout << "Invalid item ID!" << endl;
                }
                break;

            case 2:
                cout << "Enter the ID of the item: ";
                cin >> id;
                cout << "Enter the quantity to sell: ";
                cin >> q;

                if (id == 101 || id == 102)
                {
                    items[id - 100].sellItem(q);  // Adjust index
                }
                else
                {
                    cout << "Invalid item ID!" << endl;
                }
                break;

            case 3:
                // Displaying details
                for (int i = 1; i < 3; i++)
                // Start from 1 to skip default item
                {
                    items[i].display();
                    cout << "------------------------" << endl;
                }
                break;

            case 4:
                cout<<"Exiting the program.."<<endl;
                break;

            default:
                cout << "Invalid Input. Try again." << endl;
                break;
        }
    }while(choice !=4);

    return 0;
}
