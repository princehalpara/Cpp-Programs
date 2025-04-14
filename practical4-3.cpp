#include<iostream>
#include<queue>
using namespace std;
class fuel{
    private:
    string fuel_type;
    public:
    fuel (string f){
        fuel_type = f;
    }
    void display_f(){
        cout<<"Fuel type is "<<fuel_type<<endl;
    }
};
class brand{
    private:
    string brand_name;
    public:
    brand (string b){
        brand_name = b;
    }
    void display_b(){
        cout<<"Brand name is "<<brand_name<<endl;
    }
};
class car : private fuel, private brand{
    public:
    car(string f, string b) : fuel(f), brand(b) {}
    void display_car(){
        display_f();
        display_b();
        cout<<endl;
    }
};
int main(){
    queue<car> serviceQueue;
    car car1("petrol", "Honda");
    car car2("diesel", "Toyota");
    car car3("CNG", "Maruti Suzuki");
    car car4("electric", "Mahindra");
    serviceQueue.push(car1);
    serviceQueue.push(car2);
    serviceQueue.push(car3);
    serviceQueue.push(car4);
    while (!serviceQueue.empty()) {
        car currentCar = serviceQueue.front();
        currentCar.display_car();
        serviceQueue.pop();
    }
    
    return 0;
}