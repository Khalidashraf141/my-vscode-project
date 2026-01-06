/*
Create an array with even numbers and a list with odd numbers. Merge two sequences of members into a vector using the algorithm merge(). Display the vector
*/
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

int main()
{
    int arr[] = {2, 4, 6, 8, 10};
    list<int>oddNum = {1, 3, 5, 7, 9};
    vector<int>result(sizeof(arr)/sizeof(arr[0])+oddNum.size());
    merge(arr, arr+5,oddNum.begin(),oddNum.end(),result.begin());
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;

}