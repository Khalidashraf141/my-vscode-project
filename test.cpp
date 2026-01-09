#include <iostream>
using namespace std;

class Person{
    public:
        virtual ~Person(){}
};

class Student : public Person
{
    public:
        void study(){
            cout << "Student is studying" << endl;
        }
};

int main()
{
    Person* p = new Student();
    Student* s = dynamic_cast<Student*>(p);

    if(s != nullptr){
        s->study();
    }

    delete p;
}