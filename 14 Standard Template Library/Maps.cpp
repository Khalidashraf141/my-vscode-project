#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef map<string, int> phoneMap;

int main()
{
    string name;
    int number;
    phoneMap phone;
    cout << "Enter three sets of name and number\n";
    for(int i = 0; i < 3; i++)
    {
        cin >> name; // Get key
        cin >> number; // Get value
        phone[name] = number; // put them in map
    }

    phone["Jacob"] = 4444; // insert Jacob

    phone.insert(pair<string,int>("Bose",5555));
    int n = phone.size();
    cout << "\nSize of Map: " << n << "\n\n";
    cout << "List of telephone numbers \n";
    phoneMap::iterator p;
    for(p = phone.begin(); p!=phone.end(); p++)
    {
        cout << (*p).first << " " << (*p).second << "\n";
    }
    cout << "\n";
    cout << "Enter name: ";
    cin >> name;
    number = phone[name];
    cout << "Number: " << number << "\n";
    return 0;
}