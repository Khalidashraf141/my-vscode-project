/*Identify the error in the following program*/
#include <iostream>
using namespace std;

template <class T1, class T2>
class Person
{
    T1 m_t1;
    T2 m_t2;
public:
    Person(T1 t1, T2 t2)
    {
        m_t1 = t1;
        m_t2 = t2;
        cout << m_t1 << " " << m_t2 << endl;
    }
    Person(T2 t2, T1 t1)
    {
        m_t2 = t2;
        m_t1 = t1;
        cout << m_t1 << " " << m_t2 << endl;
    }
};

int main()
{
    Person<int,float>objPerson1(1,2.345);
    Person<int,float>objPerson2(1,2.345);
    Person<float,char>objPerson3(2.132,'r');
    return 0;
}

/*
!The bug is a design/logical error
*/