/*Identify the error in the following program*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    const int size = 100;
    char buffer[size];

    ifstream in("ch11_1.cpp");  //reading
    ofstream out("ch11_1Temp.cpp"); //writing

    while(in.get(buffer,size)){
        in.get();//it simply eats the newline so the next call works properly
        cout <<buffer<<endl;
        out <<buffer << endl;
    }
    in.close();
    out.close();
    return 0;
}

