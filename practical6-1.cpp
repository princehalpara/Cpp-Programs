/* Programmer : Prince Halpara
   Date : 25 April, 2025
   Aim : Implement a dynamic array using raw pointers for efficient memory use
*/

#include<iostream>
using namespace std;

class DynamicArray
{
    int size = 0;
    int capacity;
    int* data;

public:
    // Constructor
    DynamicArray(int initialCapacity = 2)
    {
        capacity = initialCapacity;
        data = new int[capacity];
    }

    // Destructor to free memory
    ~DynamicArray()
    {
        delete[] data;
    }

    // Resizing the array when capacity is full
    void resize()
    {
        capacity *= 2;
        int* newData = new int[capacity];

        // Copying old data to new array
        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
    }

    // Inserting a new value at the end of the array
    void insert(int value)
    {
        if (size == capacity)
            resize();
        data[size++] = value;
    }

    // Getting a particular value
    int getValue(int index)
    {
        if (index < 0 || index >= size)
            return -1;
        return data[index];
    }

    // Removing a particular element
    void remove(int index)
    {
        if (index < 0 || index >= size)
            return;

        // Updating the array
        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }

        size--;
    }

    // Displaying all elements of the array
    void display() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    DynamicArray arr;

    arr.insert(10);
    arr.insert(20);
    arr.insert(30);
    arr.insert(40);

    arr.display();

    int in, ch;

    // Getting value
    cout << "Enter the index: ";
    cin >> in;
    cout << "Value is: " << arr.getValue(in) << endl;

    // Removing the particular value
    cout << "Enter the index of the value you want to remove: ";
    cin >> in;
    arr.remove(in);

    // Asking user if they want to add more elements
    cout << "Do you want to add more elements (1 for Yes, 0 for No): ";
    cin >> ch;

    if (ch)
    {
        int num, value;
        cout << "Enter the number of elements: ";
        cin >> num;

        // Taking the values from the user
        for (int i = 0; i < num; i++)
        {
            cout << "Enter " << i + 1 << " number: ";
            cin >> value;
            arr.insert(value);
        }
    }

    // Displaying the final array
    arr.display();

    cout<<endl;
    cout << "\nPrince Halpara : 24CE038" << endl;

    return 0;
}
