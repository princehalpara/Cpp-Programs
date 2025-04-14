#include <iostream>
#include <vector>
#define pi 3.14
using namespace std;
class shape{
    protected:
    float radius;
    public:
    shape(float x)
    {
        radius=x;
    }
};
class circle : protected shape
{
    float area;
    public:
    circle(float y) : shape(y) {}
    void display(){
        area= radius * radius * pi;
        cout<<"area: "<<area<<endl;
    }
};
int main(){
    vector<circle>c;
    int n;
    float r;
    cout<<"Enter no of radius: ";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter radius: ";
        cin>>r;
        c.push_back(circle(r));
    }
    for (int i = 0; i < n; i++)
    {
        c[i].display();
    }
}