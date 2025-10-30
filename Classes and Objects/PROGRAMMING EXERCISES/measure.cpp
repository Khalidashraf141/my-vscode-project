#include <iostream>
using namespace std;

class DB; 

class DM
{
    float meter;
    float centimeter;

    public:
        DM(float m = 0, float cm = 0)
        {
            meter = m;
            centimeter = cm;
        }

        void input()
        {
            cout << "Enter distance in meters and centimeters: ";
            cin >> meter >> centimeter;
        }

        void display()
        {
            cout << meter << " meters " << centimeter << " centimeters" << "\n";
        }

        friend DM addDistance(DM d1, DB d2);
};

class DB
{
    float feet;
    float inches;

    public:
        DB(float f = 0, float in = 0)
        {
            feet = f;
            inches = in;
        }

        void input()
        {
            cout << "Enter distance in feet and inches: ";
            cin >> feet >> inches;
        }

        void display()
        {
            cout << feet << " feet " << inches << " inches " << "\n";
        }

        friend DM addDistance(DM d1, DB d2);
};

DM addDistance(DM d1, DB d2)
{
    float cm1 = (d1.meter*100) + d1.centimeter;

    float cm2 = (d2.feet*30.48) + (d2.inches*2.54);

    float total_cm = cm1 + cm2;

    float m = (int)(total_cm/100);
    float cm = total_cm - (m*100);

    return DM(m,cm); // return result in DM format
}

int main()
{
    DM d1;
    DB d2;

    d1.input(); //input in meters + cm
    d2.input(); // input in feet + inch

    cout << "\nFirst distance (DM): ";
    d1.display();

    cout << "Second distance (DB): ";
    d2.display();

    DM result = addDistance(d1, d2);

    cout << "\nResultant Distance (in meters and centimeters): ";
    result.display();

    return 0;
}