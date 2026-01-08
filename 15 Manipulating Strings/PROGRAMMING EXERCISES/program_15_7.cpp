/*
Write a program that reads a list of countries in random order and displays them in alphabetical order. Use comparison operators and functions.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Comparison function using comparison operator <
bool compareCountries(const string &a, const string &b)
{
    return a < b;
}

int main()
{
    int n;
    vector<string> countries;
    cout << "Enter number of countries: ";
    cin >> n;
    cin.ignore();
    
    cout << "Enter country names:\n";
    for(int i = 0; i < n; i++)
    {
        string country;
        getline(cin,country);
        countries.push_back(country);
    }

    sort(countries.begin(), countries.end(),compareCountries);

    cout << "\nCountries in alphabetical order:\n";
    for(const string &country: countries)
    {
        cout << country << endl;
    }
    return 0;
}