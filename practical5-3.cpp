/* Programmer : Prince Halpara
   Aim : To simulate and manage 2D point operations with undo functionality using operator overloading and a stack
   Date : 18 April, 2025
*/

#include<iostream>
#include<stack>

using namespace std;

class Point
{
    double x,y;
public:
    Point(double a=0,double b=0): x(a), y(b) {}

    // Function for adding points
    Point operator+ (const Point& obj)
    {
        Point p;
        p.x = x + obj.x;
        p.y = y + obj.y;
        return p;
    }

    // Function for doing negation of point
    Point operator- ()
    {
        Point p;
        p.x = -x;
        p.y = -y;
        return p;
    }

    // Function for comparing points
    int operator== (const Point& obj)
    {
        if(x == obj.x && y == obj.y)
            return 1;
        else
            return 0;
    }

    // Returning the value of x
    double getX()
    {
        return x;
    }

    // Returning the value of y
    double getY()
    {
        return y;
    }

    // Displaying the value of x and y
    void display() const
    {
        cout<<"x="<<x<<", y="<<y<<endl;
    }
};

int main()
{
    stack<Point> points;

    Point P1(1.2,3.5);
    points.push(P1);

    Point P2(4.5,5.8);
    points.push(P2);


    // Addition of two object
    Point P3 = P1 + P2;
    cout<<"Addition :  x="<<P3.getX()<<", y="<<P3.getY() <<endl;

    // Negation of the object
    P3 = -P1;
    points.push(P3);
    cout<<"Negation :  x="<<P3.getX()<<", y="<<P3.getY() <<endl;

    // Comparing the two objects
    if(P1 == P2)
        cout<<"Both points are equal."<<endl;
    else
        cout<<"Both points are not equal."<<endl;

    // Undoing the last operation
    int ch;
    cout<<"Are you want to undo the last operation(1 or 0): ";
    cin>>ch;

    if(ch && !points.empty())
    {
        Point p = points.top();
        points.pop();
        cout<<"Undid the last operation: ";
        p.display();
    }

    // Displaying the stack
    while(!points.empty())
    {
        Point p;
        p = points.top();
        cout<<"x="<<p.getX()<<", y="<<p.getY()<<endl;
        points.pop();
    }

    cout<<endl;
    cout << "\nPrince Halpara: 24CE038" << endl;
    return 0;
}
