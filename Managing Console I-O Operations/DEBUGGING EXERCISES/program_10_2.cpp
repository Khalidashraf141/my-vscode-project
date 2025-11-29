/*Will the statement cout.setf(ios::right) work or not?*/
#include <iostream>
using namespace std;

int main()
{
    cout.width(5);
    cout << "99" << endl;

    cout.setf(ios::left);
    cout.width(5);
    cout << "99" << endl;

    cout.setf(ios::right);
    cout << "99" << endl;
    return 0;
}

/*
🔍 Explanation
    => Alignment flags (left,right,internal) work ONLY with width.
    if no width -> alignment is ignored
*/