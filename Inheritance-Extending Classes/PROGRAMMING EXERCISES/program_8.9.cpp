/*
8.9 Question-> Define all the functions and classes as per the relationship for a shopkeeper of following type of items,
    (a) Two wheeler manual, electric and automatic
    (b) Three wheeler manual, electric and automatic
    (c) Four wheeler automatic
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

//Base Class
class Vehicle
{
protected:
    string name;
    string brand;
    float price;
public:
    void inputVehicleData()
    {
        cout << "Enter Vehicle Name: ";
        cin >> name;
        cin.ignore();
        cout << "Enter Brand Name: ";
        cin >> brand;
        cout << "Enter Price: ";
        cin >> price;
    }

    void displayVehicleData()
    {
        cout << "Name: " << name
             << ", Brand: " << brand
             << ", Price: $" << price;
    }
};

// TwoWheeler Class
class TwoWheeler : public Vehicle
{
protected:
    string type; // manual/electric/automatic
public:
    void inputTwoWheelerData(){
        inputVehicleData();
        cout << "Enter Type (Manual/Electric/Automatic): ";
        cin >> type;
    }

    void displayTwoWheelerData(){
        cout << "TwoWheeler -> ";
        displayVehicleData();
        cout << ", Type: " << type << endl;
    }
};

// ThreeWheeler
class ThreeWheeler : public Vehicle
{
protected:
    string type;
public:
    void inputThreeWheelerData()
    {
        inputVehicleData();
        cout << "Enter Type (Manual/Electric/Automatic): ";
        cin >> type;
    }

    void displayThreeWheelerData(){
        cout << "ThreeWheeler -> ";
        displayVehicleData();
        cout << ", Type: " << type << endl;
    }
};


// FourWheeler Class (only automatic)
class FourWheeler : public Vehicle
{
public:
    void inputFourWheelerData()
    {
        inputVehicleData();
        cout << "Type: Automatic (fixed)\n";
    }
    void displayFourWheelerData()
    {
        cout << "FourWheeler -> ";
        displayVehicleData();
        cout << ", Type: Automatic" << endl;
    }
};

// Shopkeeper Class
class Shopkeeper
{
    string shopName;
    vector<TwoWheeler> twoWheelers;
    vector<ThreeWheeler> threeWheelers;
    vector<FourWheeler> fourWheelers;

public:
    void inputShopDetails()
    {
        cout << "Enter Shop Name: ";
        cin >> shopName;
    }

    void addVehicle()
    {
        int choice;
        cout << "\n1. TwoWheeler\n2. ThreeWheeler\n3. FourWheeler\nEnter Choice: ";
        cin >> choice;

        if(choice == 1)
        {
            TwoWheeler t;
            t.inputTwoWheelerData();
            twoWheelers.push_back(t);
        }
        else if(choice == 2)
        {
            ThreeWheeler t;
            t.inputThreeWheelerData();
            threeWheelers.push_back(t);
        }
        else if(choice == 3)
        {
            FourWheeler t;
            t.inputFourWheelerData();
            fourWheelers.push_back(t);

        }
        else{
            cout << "Invalid choice!\n";
        }
    }

    void displayAllVehicles()
    {
        cout << "\n===== Vehicle Stock of " << shopName << " ======\n";

        cout << "\n--- TwoWheelers --\n";
        for(auto &v : twoWheelers)
            v.displayTwoWheelerData();
        
        cout << "\n-- ThreeWheelers --\n";
        for(auto &v : threeWheelers)
            v.displayThreeWheelerData();
        
        cout << "\n--- FourWheelers ---\n";
        for(auto &v : fourWheelers)
            v.displayFourWheelerData();
    }
};

int main()
{
    Shopkeeper s;
    s.inputShopDetails();

    int n;
    cout << "How many vehicles you want to add? ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        s.addVehicle();

    }
    s.displayAllVehicles();

    return 0;
}