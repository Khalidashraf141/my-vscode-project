#include <iostream>
#include <windows.h>
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
        void admin()
        {
            string adminUser;
            string adminPass;
            cout << "Enter username : ";
            getline(cin,adminUser);
            cout << "Enter password : ";
            adminPass = getPassword();

            if(userName == adminUser && password == adminPass){
                cout << "Login Successful";
            }else{
                cout << "Login failed!";
            }
        }
    private:
        
        void loadAdminCredentials(){
            ifstream file("admin.txt");
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

int main()
{
    Login l;
}