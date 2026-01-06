/*
A table gives a list of car models and the member of units sold in each type in a specified period. Write a program to store this table in a suitable container, and to display interactively the total value of a particular model sold, given the unit-cost of that model.
*/
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    // Store can model and units sold
    map<string, int> carSales;

    carSales["Swift"] = 120;
    carSales["Baleno"] = 85;
    carSales["Creta"] = 60;
    carSales["Nexon"] = 95;
    carSales["Fortuner"] = 40;

    string model;
    int unitCost;

    cout << "Enter car model: ";
    cin >> model;
    cout << "Enter unit cost: ";
    cin >> unitCost;

    if(carSales.find(model) != carSales.end())
    {
        int unitSold = carSales[model];
        int totalValue = unitSold * unitCost;

        cout << "Units Sold: " << unitSold << endl;
        cout << "Total Value: " << totalValue << endl;
    }
    else{
        cout << "Car model not found!" << endl;
    }
    return 0;
}