#include <iostream>
#include <sstream>
using namespace std;
//this function ensure that use input should be int or float
int getValidatedInt(const string &prompt)
{
    string input;
    double value;

    while(true){
        cout << prompt;
        getline(cin,input);
        stringstream ss(input);

        if(ss >> value &&  ss.eof()){
            return value;
        }else{
            cout << "Invalid input! Please enter a valid integer.\n";
        }


    }
}

int main()
{
    int code = getValidatedInt("Enter code: ");
    cout << code; 
    return 0;
}
//todo: practice this function