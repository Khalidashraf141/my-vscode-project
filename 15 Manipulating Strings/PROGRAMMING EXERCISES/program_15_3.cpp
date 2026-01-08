/*
Write a program that reads several city names form the keyboard and displays only those names beginning with characters "B" or "C".
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string cityName;
    cin >> cityName;
    if(cityName[0]=='B' || cityName[0] == 'C')
    {
        cout << cityName;
    }
    return 0;
}