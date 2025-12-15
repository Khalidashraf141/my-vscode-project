                    // An Application of Template Function
#include <iostream>
using namespace std;

#define ARR_MAX 5   // Maximum number of elements in an array

template <class T>
T find_min(T ARR[])
{
    int i = 0;
    T MIN = ARR[0];
    for(i = 1; i < ARR_MAX; i++)
    {
        if(ARR[i]<MIN)
        {
            MIN = ARR[i];
        }
    }
    return MIN;
};

int main()
{
    int I_MIN;
    float F_MIN;
    char C_MIN;

    //Defining different array types
    int I[5] = {20,4,2,38,97};
    float F[5] = {-9.9,12.2,3.1,9.9,8.9};
    char C[5] = {'a','A','/','4',','};

    // Finding minimum value in each array
    I_MIN = find_min<int>(I);
    F_MIN = find_min<float>(F);
    C_MIN = find_min<char>(C);

    //Printing the results
    cout << "Minimum value in integer array = " << I_MIN;
    cout << "\nMinimum value in float array = " << F_MIN;
    cout << "\nMinimum value (as per ASCII) in character array = " << C_MIN;
    return 0;
}