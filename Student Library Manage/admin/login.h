#ifndef LOGIN_H
#define LOGIN_H
#include <iostream>
#include <limits>
#include <fstream>
#include <conio.h>
#include <string>

using namespace std;
class Login
{
    private:
        string userName, password;
    public:
        Login(){
            loadAdminCredentials();
        }
        bool admin()
        {
            string adminUser;
            string adminPass;

            cout << "Enter username : ";
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            getline(cin,adminUser);

            cout << "Enter password : ";
            adminPass = getPassword();

            if(userName == adminUser && password == adminPass){
                cout << "Login Successful";
                return true;
            }else{
                cout << "Login failed!";
                return false;
            }
        }

    private:
        void loadAdminCredentials(){
            ifstream file("admin/admin.txt");
            if(file.is_open()){
                getline(file,userName);
                getline(file,password);
                file.close();
            }else{
                cout << "Admin file not found!" << endl;
            }
        }

        string getPassword(){
            string pass;
            char ch;
            while(true){
                ch = _getch();
                if(ch == 13){
                    cout << endl;
                    break;
                }
                else if(ch == 8){
                    if(!pass.empty()){
                        pass.pop_back();
                    }
                }
                else{
                    pass.push_back(ch);
                }
            }
            return pass;
        }
};
#endif