#include <iostream>
#include <string>
using namespace std;

class Car{
    public:
        string brand;
        string model;
        int year;
        Car(string brand, string model, int year){
            this->brand = brand;
            this->model = model;
            this->year = year;
        }
        void printCarDetails(){
            cout<<"brand : "<<brand<<"\n";
            cout<<"model : "<<model<<"\n";
            cout<<"year : "<<year<<"\n";
        } 
};

// Function to print car information
int main(){
    Car car1("Toyota" , "gli" , 2005);
    Car car2("alto" , "vxr" , 2020);
    car1.printCarDetails();
    car2.printCarDetails();
    return 0;
}