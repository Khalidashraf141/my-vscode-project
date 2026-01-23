#include <iostream>
#include <cstdlib>
#include "mystack.h"
using namespace std;

// int post(char *);

int post(char *P)
{
    MyStack<>S;
    int i = 0, j, d, arg1, arg2;
    char num[5];

    while(P[i] != '\0')
    {
        if(P[i] == '+' || P[i] == '-' || P[i] == '*' || P[i] == '/')
        {
            arg1 = S.pop();
            arg2 = S.pop();
            switch(P[i])
            {
                case '+': S.push(arg2 + arg1);
                          break;
                case '-': S.push(arg2 - arg1);
                          break;
                case '*': S.push(arg2 * arg1);
                          break;
                case '/': S.push(arg2 / arg1);
            }
        }
        else if(P[i]>='0' && P[i]<='9')
        {
            j = 0;
            while(P[i]>='0' && P[i]<='9')
            num[j++] = P[i++];

            num[j] = '\0';
            d = atoi(num);
            S.push(d);
            continue;
        }
        i++;
    }
    if(S.stackcount() == 1)
        return S.pop();
    else return -9999;
}

int main()
{
    char P[80];
    int result;

    cout << "\nEnter the Postfix expression : ";
    cin.getline(P,80);
    result = post(P);

    if(result == -9999)
        cout << "\nThere is an error in the expression";
    else
        cout << "\nThe result is : " << result;
    return 0;
}

