#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}


int main()
{
    vector<int> v;      // Create a vector of type int
    cout << "Initial size = " << v.size() << "\n";
        // Putting values into the vector
    int x;
    cout << "Enter five integer values: ";

    for(int i = 0; i < 5; i++)
    {
        cin >> x;
        v.push_back(x);
    }
    cout << "Size after adding 5 values: ";
    cout << v.size() << "\n";

    // Displaying the contents
    cout << "Current contents: \n";
    display(v);

    // Add one more value
    v.push_back(6.6);       // float value truncated to int

    // Display size and contents
    cout << "\nSize = " << v.size() << "\n";
    cout << "Contents now: \n";
    display(v);

    // Inserting elements
    vector<int> ::iterator itr = v.begin(); // iterator
    itr = itr + 3;      // itr points to 4th element
    v.insert(itr,1,9); // the value 1 specifies the number of time the element 9 is inserted into the vector
    
    // Display the contents
    cout << "\nContents after inserting: \n";
    display(v);

    // Removing 4th and 5th elements
    v.erase(v.begin()+3, v.begin()+5); // Removes 4th and 5th element (first) is included
                                                                //    (last) is excluded

    // Display the contents
    cout << "\nContents after deletion: \n";
    display(v);
    cout << "END\n";
    return 0;
}