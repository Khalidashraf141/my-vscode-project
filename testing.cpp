#include <iostream>
#include <typeinfo>
using namespace std;
class Person{};
int main()
{
    Person John;
    cout << "John is a ";
    cout << typeid(John).name() << "\n";
    return 0;
}