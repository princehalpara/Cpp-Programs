/* Programmer :Prince Halpara
   Aim : To develop an efficient inventory management system using either procedural or OOP approach
   Date : 07 February, 2025
   */

#include<iostream>
using namespace std;

class Product
{
public:

    int id;
    string name;
    int quantity;
    float price;

    void add_product()
    {
        cout<<"Enter the id of the product: ";
        cin>>id;
        cout<<"Enter the name of the product: ";
        cin>>name;
        cout<<"Enter the quantity of the product: ";
        cin>>quantity;
        cout<<"Enter the price of the product: ";
        cin>>price;
    }

    void update(int newQuantity)
    {
        quantity = newQuantity;
    }

    float calculation()
    {
        float p;
        p = price * quantity;
        return p;
    }
};

int main()
{
    Product P[3];
    int i,newid,newQuantity;
    float total_value;

    for(i=0; i<3; i++)
    {
        cout<<"("<<i+1<<")Product Details:: \n";
        P[i].add_product();
    }

    cout<<"For upadation enter 1:";
    cin>>i;

    if(i==1)
    {
        cout<<"Enter the id of the existing product: ";
        cin>>newid;

        for(i=0; i<3; i++)
        {
            if(P[i].id == newid)
            {
                cout<<"Enter the remaining quantity of this existing product: ";
                cin>>newQuantity;
                P[i].update(newQuantity);
            }
        }
    }

    for(i=0; i<3; i++)
    {
        total_value += P[i].calculation();
    }

    cout<<"The total value of all the product is: "<<total_value;

    return 0;
}
