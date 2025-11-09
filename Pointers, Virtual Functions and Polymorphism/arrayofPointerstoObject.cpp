#include <iostream>
#include <cstring>

using namespace std;

class City
{
    protected:
        char *name;
        int len;
    public:
        City()
        {
            len = 0;
            name = new char[len+1];
        }
        void getname(void)
        {
            char *s;
            s = new char[30];
            cout << "Enter city name: ";
            cin >> s;
            len = strlen(s);
            name = new char[len+1];
            strcpy(name,s);
        }
        void printname(void)
        {
            cout << name << "\n";
        }
};

int main()
{
    City *cptr[10]; //array of 10 pointers to cities

    int n = 1;
    int option;

    do
    {
        cptr[n] = new City; // create new city
        cptr[n]->getname();
        n++;
        cout << "Do you want to enter on more name?\n";
        cout << "(Enter 1 for yes 0 for no): ";
        cin >> option;
    }
    while(option);

    cout << "\n\n";
    for(int i = 0; i<=n; i++)
    {
        cptr[i]->printname();
    }
    return 0;
};