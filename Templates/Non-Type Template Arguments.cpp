/*
Non-type template arguments are an important concept in templates

1. What are Non-Type Template Arguments?
normally, templates use types:
    template<class T>
Here T is a type parameter (int, float, etc)


-Non-type template argument means:
    A template parameter that is NOT a type but a value.
so instead of passing a data type, we pass a constant value

*/

// 2. General Syntax
template<class T, int N>
class Sample
{
    //N is a non-type template argument
};
/*
here:
    • T -> type parameter
    • N -> non-type (value) parameter
*/

// 3 class Template with Non-Type argument
template<class T, int size>
class Array
{
    T arr[size];
public:
    void display()
    {
        for(int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    Array<int,5>a;
    return 0;
}
/*
Here:
    T = int;
    size = 5 <- non-type template argument
the value 5 is known at compile time.
*/

/*
4. Why Use Non-type Template Arguments
    Fixed size known at compile time
    Non dynamic memory allocation
    Faster execution
    Type + size safety
*/

template<int N>
void show()
{
    cout << "Value is " << N << endl;
}

//useage:
    /*
        show<10>();
        show<25>();
    here:
        n is non-type template argument
    */

/*
6 What values are allowed?
    non type template arguments must be compile-time constants

    allowed:
        int, char, bool
        enum
        constexpr values
        pointers/references (with restrictions)

    Now allowed:
        variables
        use input
        runtime values
    




*/