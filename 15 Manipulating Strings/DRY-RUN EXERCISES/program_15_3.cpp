#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1;
    cout << "Enter String : ";
    cin >> s1;
    for(int i = 0; i < s1.length()/2; i++)
    {
        if(s1.at(i) != s1.at(s1.length() - i - 1))
        {
            cout << "Not Same" << "\n";
            break;
        }
    }
    return 0;
}
//H e l l
