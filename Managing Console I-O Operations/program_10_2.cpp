#include <iostream>
#include <cstring>
#include <limits>
using namespace std;

int main()
{
    int size = 20;
    char city[20];
    cout << "Enter city name:  \n";
    cin >> city;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "City name: " << city << "\n\n";

    cout << "Enter city name again: \n";
    cin.getline(city,size);
    cout << "City name now: " << city <<"\n\n";

    cout << "Enter another city name: \n";
    cin.getline(city,size);
    cout << "New city name: " << city << "\n\n";

    return 0;
}