                    //DEBUGGING-EXERCISE
#include <iostream>
using namespace std; //that was missing in the code
class Room
{
    float mwidth;
    float mLength;
public:
    Room():mwidth(0),mLength(0)
    {

    }
    Room(float w, float h):mwidth(w), mLength(h)
    {

    }

    operator float()
    {
        return (float)mwidth * mLength;
    }
    float getWidth()
    {
        return mwidth;
    }

};

int main()
{
    Room objRoom1(2.5,2.5);
    float fTotalArea;
    fTotalArea = objRoom1;
    cout << fTotalArea;
    return 0;
}