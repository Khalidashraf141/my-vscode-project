//ellipses
#include <iostream>
#include <cstdarg>
using namespace std;

int findmaximum (int count, ...)
{
    int max, value;
    va_list list;  //declare variable argument list

    va_start(list, count); //start accessing variable list

    max = va_arg(list,int); //extract the first element of list , or use can predefine max like INT_MIN or max can already have garbage value if we not sotre any value (but garbage value is unpreditable it can be in - or greater than the number we want to compare so its better to take value from our give data here it will store 14 in max then start form 78 comparing also the loop starting from the 1 not form the zero)

    for (int arg = 1; arg < count; ++arg){
        value = va_arg(list,int); //extract each successive element from list
              if(max<value){
                    max = value;
                }
    }
    va_end(list); //end the access of the variable argument list
    return max;
}

int main(){
    cout << findmaximum(5,14,78,90,34,23,1000); // the first arguments 5 is telling the functions that i will give 5 numbers             |   //1000 is not included because we already told that i will give 5 number...
    return 0;
}