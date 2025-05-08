/* Programmer : Prince Halpara
   Date : 25 April, 2025
   Aim :  Enable chained point updates using pointers
*/

#include<iostream>
using namespace std;

class Point
{
    int x,y;

public:
    Point(int x=0, int y=0) : x(x) , y(y) {}

    Point* move(int dx, int dy)
    {
        x += dx;
        y += dy;
        return this;
    }

    void display() const
    {
        cout<<"x coordinate: "<<x<<endl;
        cout<<"y coordinate: "<<y<<endl;
    }
};

int main()
{
    int x,y;
    cout<<"Enter the x and y coordinates: ";
    cin>>x>>y;

    Point* p = new Point (x,y);
    p->display();

    int dx1,dx2,dy1,dy2;
    cout<<"Enter the first x and y coordinates: ";
    cin>>dx1>>dy1;
    cout<<"Enter the second x and y coordinates: ";
    cin>>dx2>>dy2;

    p->move(dx1,dy1)->move(dx2,dy2);

    cout<<"Coordinates after moving the point: "<<endl;
    p->display();

    cout<<endl;
    cout << "\nPrince Halpara : 24CE038" << endl;

    return 0;
}
