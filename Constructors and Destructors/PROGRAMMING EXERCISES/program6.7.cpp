//Write a program to display car features and specification overloading constructor.
#include <iostream>
#include <cstring>
using namespace std;            //TODO:PRACTICE

class Car
{
    char name[30];
    char model[30];
    char engineType[30];
    float price;

public:
    //Default Constructor
    Car()
    {                                           
        strcpy(name,"Unknown");
        strcpy(model,"Not specified");
        strcpy(engineType, "Not specified");
        price = 0;
    }

    //Constructor with 2 arguments
    Car(const char* n, const char* m)
    {
        strcpy(name,n);
        strcpy(model,m);
        strcpy(engineType,"Petrol"); //default engine
        price = 0; //default price
    }

    // Constructor with 4 arguments
    Car(const char *n, const char *m, const char* e, float p)
    {
        strcpy(name,n);
        strcpy(model,m);
        strcpy(engineType,e);
        price = p;
    }

    void display()
    {
        cout << "\nCar Name: " << name;
        cout << "\nModel: " << model;
        cout << "\nEngine Type: " << engineType;
        cout << "\nPrice: $" << price << "\n";
    }
};

int main()
{
    //Using default constructor
    Car c1;
    cout << "\n--- Default Car Details ---";
    c1.display();


    //Using constructor with 2 arguments
    Car c2("Honda","Civic");
    cout << "\n--- Car with Partial Info ---";
    c2.display();

    //Using constructor with 4 arguments
    Car c3("Tesla", "Model S", "Electric", 89999);
    cout << "\n--- Car with Full Info ---";
    c3.display();

    return 0;
}