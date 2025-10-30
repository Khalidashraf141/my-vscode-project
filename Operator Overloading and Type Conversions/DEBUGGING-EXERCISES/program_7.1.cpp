                                                //DEBUGGING-EXERCISES
#include <iostream>
using namespace std;
class Space
{
    int mCount;
public:
    Space() //default constructor
    {
        mCount = 0;
    }
    Space(int value):mCount(value){} //constructor with parameter (needed)

    // pre-increment(++obj)
    Space operator ++()
    {
        ++mCount;
        return Space(mCount);
    }

    // post-increment(0bj++)
    Space operator++(int)
    {
        Space temp = *this;
        ++mCount;
        return temp;
    }
    void display(void)
    {
        cout << mCount << "\n";
    }
};

int main()
{
    Space objSpace;
    objSpace++;
    objSpace.display(); //shows incremented value
    ++objSpace;
    objSpace.display(); //shows incremented value again
    return 0;
}