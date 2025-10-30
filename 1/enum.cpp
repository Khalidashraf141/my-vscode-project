#include <iostream>
using namespace std;
enum Level {
    LOW,    //0
    MEDIUM, //1
    HIGH    //2
};

int main(){
    enum Level myvar = MEDIUM;
    cout << myvar << endl;

    enum Level days = HIGH;
    switch (days)
    {
    case 1:
        cout << "SUNDAY";
        break;
    case 2:
        cout << "MONDAY";
        break;
    case 3:
        cout << "TUESDAY";
        break;
    case 4:
        cout << "WEDNESDAY";
        break;
    case 5:
        cout << "THUSDAY";
        break;
    case 6:
        cout << "FRIDAY";
        break;
    case 7:
        cout << "SATURDAY";
        break;
    default:
        cout << "END";
        break;
    }
}