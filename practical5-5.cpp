/* Programmer : Prince Halpara
   Aim : Calculate areas of shapes using polymorphism
   Date : 18 April, 2025
*/

#include <iostream>
#include <vector>
using namespace std;

// Base class
class Shape {
public:
    virtual double Area() const = 0; // Pure virtual function
    virtual ~Shape() {}               // Virtual destructor
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double Area() const override {
        return length * width;
    }
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double Area() const override {
        return 3.14159 * radius * radius;
    }
};

int main() {
    // Create a dynamic collection of Shape pointers
    vector<Shape*> shapes;

    // Add different shapes
    shapes.push_back(new Rectangle(5.0, 3.0));
    shapes.push_back(new Circle(2.0));
    shapes.push_back(new Rectangle(4.5, 6.0));
    shapes.push_back(new Circle(3.5));

    // Calculate and print the area of each shape
    for (size_t i = 0; i < shapes.size(); ++i) {
        cout << "Shape " << (i + 1) << " Area: " << shapes[i]->Area() << endl;
    }

    // Clean up memory
    for (size_t i = 0; i < shapes.size(); ++i) {
        delete shapes[i];
    }
    shapes.clear();

    cout<<endl;
    cout << "\nPrince Halpara  : 24CE038" << endl;

    return 0;
}
