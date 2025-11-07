//Program 9.6 Searching a Substring within a Main String
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
    int i , j;
    char str[] = "\nC++ is better than C";
    int len = strlen(str);

    cout << len << endl;
    char *substr = new char[len];

    cout << "The main string is : " << str;
    cout << "\n\nEnter the substring to be searched: ";
    cin >> substr;

    int k, len2=strlen(substr);
    cout << len2 << endl;

    for(i = 0; i < len; i++)
    {
        k = i;
        for(j = 0; j < len2; j++)
        {
            if(str[k]==substr[j])
            {
                if(j==len2-1)
                {
                    cout << "\nThe substring is present in the main string";

                    exit(0);
                }
                k++;
            }
            else    
                break; //if str[k] != substr[j] then break the loop and give k new value k = i then k[i] j[0] ko check kare ga
        }
    }
    if(i==len)
    cout << "\nThe substring is not present in the main string";

    return 0;
}