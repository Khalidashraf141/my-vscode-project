/*Write a program to compare two sequences using lexicographical_compare*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    /*true -> first sequence is smaller
      false -> otherwise
    */
    vector<char> A = {'a', 'd', 'q'}; 
    vector<char> B = {'a', 'b', 'f'};
    if(lexicographical_compare(A.begin(),A.end(), B.begin(),B.end()))
        cout << "True";
    else
        cout << "False";
    return 0;
}