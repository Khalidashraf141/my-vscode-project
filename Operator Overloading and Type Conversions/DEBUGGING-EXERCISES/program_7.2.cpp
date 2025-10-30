#include <iostream>
using namespace std;

enum WeekDays
{
    mSunday,
    mMonday,
    mTuesday,
    mWednesday,
    mThrusday,
    mFriday,
    mSaturday
};

bool op(WeekDays w1, WeekDays w2)
{
    return w1 == w2;
}

int main()
{
    WeekDays w1 = mSunday, w2 = mSunday;
    if(op(w1,w2))
    {
        cout << "Same Day";
    }
    else
    {
        cout << "Different Day";
    }
    return 0;
}