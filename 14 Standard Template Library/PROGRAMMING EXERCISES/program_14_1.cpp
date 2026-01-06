/*
Write a code segment that does the following:
    (a) Defines a vector v with maximum size of 10.
    (b) Sets the first element of v to 0
    (c) Sets the last element of v to 9
    (d) Sets the other elements to 1
    (e) Displays the contents of v
*/
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v(10,1);  // Maximum size of 10
    v[0] = 0; // first element 0
    v[9] = 9; // last element  9
    // for(int i = 1; i < 9; i++)
    // {
    //     v[i] = 1; // set other elements to 1
    // }
    //Display
    for(int i = 0; i < 10; i++)
    {
        cout<< v[i] << " ";
    }
    return 0;
}

/*
Improvement
    vector<int>v(10,1);
*/