#include <iostream>
using namespace std;

template <class T = int> //template class
class MyStack
{
    T* arr;
    int size;
    int top;
public:
    MyStack()
    {
        size = 100;
        arr = new T[100];
        top = -1;
    }
    MyStack(int s)
    {
        size = s;
        arr = new T[s];
        top = -1;
    }

    ~MyStack()
    {
        delete[] arr;
    }
    void push(T d)
    {
        try{
            if(top == size-1)
                throw size;
            else arr[++top] = d;
        }
        catch(int x)
        {
            cout << "The stack is full" << endl;
            exit(1);
        }
    }

    T pop()
    {
        try{
            if(top == -1)
                throw top;
            else return arr[top--];
        }
        catch(int x)
        {
            cout << "The stack is empty" << endl;
            exit(1);
        }
    }

    bool is_empty()
    {
        if(top == -1)
            return true;
        else return false;
    }

    bool is_full()
    {
        if(top == size -1)
            return true;
        else return false;
    }
    int stackcount()
    {
        return top + 1;
    }
};
