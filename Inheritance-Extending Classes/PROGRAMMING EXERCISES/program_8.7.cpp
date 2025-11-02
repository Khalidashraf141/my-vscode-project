/*
8.7 Question-> We have learned that OOP is well suited for designing simulation programs. Using the techniques and tricks learned so far, design a program that would simulate a simple real-world system familiar to you.

                       💡 Project: Smart Parking System

*/

#include <iostream>
#include <vector>
#include <cstring>
#include <iomanip>
using namespace std;

// Base Abstract Class
class Vehicle
{
protected:
    string vehicleNo;
    int hoursParked;
    double charge;

public:
    Vehicle(string vNo = "Unknown", int hrs = 0):vehicleNo(vNo), hoursParked(hrs), charge(0.0){}

    virtual void calculateFee() = 0; //pure virtual -> abstraction

    virtual void display(){
        cout << left << setw(12) << vehicleNo
             << setw(10) << hoursParked
             << setw(10) << charge << endl;
    }


    double getCharge()const{return charge;}
    virtual ~Vehicle(){

    }
};

// Derived class: Car
class Car : public Vehicle
{
public:
    Car(string vNo, int hrs) : Vehicle(vNo,hrs){}

    void calculateFee()override{
        charge = 20 + (hoursParked*10); // base + per hour
    }


    void display()override{
        cout << "[Car]";
        Vehicle::display();
    }
};

// Derived class: Bike
class Bike : public Vehicle
{
public:
    Bike (string vNo, int hrs):Vehicle(vNo,hrs){}

    void calculateFee()override{
        charge = 10 + (hoursParked * 5);
    }

    void display()override{
        cout << "[Bike]";
        Vehicle::display();
    }
};

// Derived class: Truck
class Truck : public Vehicle
{
    public:
        Truck(string vNo, int hrs): Vehicle(vNo, hrs){}

        void calculateFee()override{
            charge = 50 + (hoursParked * 20);
        }

        void display()override{
            cout << "[Truck]";
            Vehicle::display();
        }
};

// Parking Lot class (Composition + Static Members)
class ParkingLot
{
    vector<Vehicle*>vehicles; // Composition
    static double totalEarnings;
public:
    void addVehicle(Vehicle* v)
    {
        v->calculateFee();
        totalEarnings +=v->getCharge();
        vehicles.push_back(v);
        cout << "✅ Vehicle added successfully!\n";
    }

    void showAllVehicles()
    {
        cout << "\n--- Parked Vehicles --\n";
        cout << left << setw(8) << "Type" << setw(12) << "Number"
             << setw(10) << "Hours" << setw(10) << "Charge" << endl;
        cout <<"---------------------------------------\n";
        for(auto v: vehicles)
            v->display();
        cout << "--------------------------------------\n";
    }


    static void showEarnings(){
        cout << "Total Earnings: Rs. " << totalEarnings << endl;
    }

    ~ParkingLot(){
        //free allocated memory
        for(auto v: vehicles)
            delete v;
    }
};

double ParkingLot :: totalEarnings = 0.0;

int main()
{
    ParkingLot lot;
    int choice;

    do{
        cout << "\n========= SMART PARKING SYSTEM ========";
        cout << "\n1. Park Car\n2. Park Bike\n3. Park Truck\n4. Show All Vehicles\n5. Show Earnings\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if(choice == 1 || choice == 2 || choice == 3){
            string number;
            int hours;
            cout << "Enter Vehicle Number: ";
            cin >> number;
            cout << "Enter Hours Parked: ";
            cin >> hours;

            Vehicle* v = nullptr;
            switch(choice){
                case 1: v = new Car(number, hours); break;
                case 2: v = new Bike(number, hours);break;
                case 3: v = new Truck(number,hours);break;
            }
            lot.addVehicle(v);
        }
        else if(choice == 4){
            lot.showAllVehicles();
        }
        else if(choice == 5){
            ParkingLot::showEarnings();
        }
    }while (choice!=0);

    cout <<"\n Simulation Ended. Goodbye!\n";
    return 0;
}