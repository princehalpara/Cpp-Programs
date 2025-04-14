/* Programmer : Prince Halpara
   Aim : To develop a system for managing and analyzing rectangles by calculating area and perimeter
   Date : 10 February, 2025
*/

#include <iostream>
using namespace std;

class Rectangle
{
    float length, width, area, perimeter;

public:
    void get_dimension()
    {
        cout << "Enter the length of the rectangle: ";
        cin >> length;
        cout << "Enter the width of the rectangle: ";
        cin >> width;
    }

    void update_dimension()
    {
        cout << "Enter the new length and width of the rectangle: ";
        cin >> length >> width;
    }

    void calculateArea()
    {
        area = length * width;
        cout << "The area of the rectangle is: " << area << endl;
    }

    void calculatePerimeter()
    {
        perimeter = 2 * (length + width);
        cout << "The perimeter of the rectangle is: " << perimeter << endl;
    }

    void display()
    {
        cout << "Rectangle Length: " << length << endl;
        cout << "Rectangle Width: " << width << endl;
        cout << "Rectangle Area: " << area << endl;
        cout << "Rectangle Perimeter: " << perimeter << endl;
    }
};

int main()
{
    int num, choice;

    cout << "Enter the number of rectangles: ";
    cin >> num;

    Rectangle* R = new Rectangle[num];  // Using dynamic allocation to avoid VLAs

    do {
        cout << "\nRectangle Management System" << endl;
        cout << "1. Enter the details of Rectangles" << endl;
        cout << "2. Update Rectangle Dimensions" << endl;
        cout << "3. Display All Rectangles" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                for (int i = 0; i < num; i++)
                {
                    cout << "\n(" << i + 1 << ") Rectangle Details: \n";
                    R[i].get_dimension();
                    R[i].calculateArea();
                    R[i].calculatePerimeter();
                }
                break;

            case 2:
            {
                int index;
                cout << "Enter the rectangle number you want to update (1-" << num << "): ";
                cin >> index;
                if (index < 1 || index > num)
                {
                    cout << "Invalid rectangle number!\n";
                }
                else
                {
                    R[index - 1].update_dimension();
                    R[index - 1].calculateArea();
                    R[index - 1].calculatePerimeter();
                }
                break;
            }

            case 3:
                for (int i = 0; i < num; i++)
                {
                    cout << "\n(" << i + 1 << ") Rectangle Details: \n";
                    R[i].display();
                }
                break;

            case 4:
                cout << "Exiting......";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    delete[] R;  // Free dynamically allocated memory
    return 0;
}
