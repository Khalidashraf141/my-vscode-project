#include <iostream>
#include <limits>

#include "admin/login.h"
#include "book/book.h"

using namespace std;

int safeIntInput()
{
    int x;
    while(true)
    {
        cin >> x;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input! Please enter a number: ";
        }
        else
        {
            return x;
        }
    }
}



int main()
{
    bool libraryRunning= true;
    bool adminRunning = true;
    bool studentRunning = true;
while(libraryRunning)
{


    int choice;

    cout << "\n=================================\n";
    cout << "   Library Management System\n";
    cout << "\n=================================\n";
    cout << "1. Admin\n";
    cout << "2. Student\n";
    cout << "3. Exit Library Panel\n";
    
    cout << "Enter your choice: ";
    choice = safeIntInput();

    switch(choice)
    {
        case 1:{
            Login login;
            if(login.admin())
            {
                while(adminRunning)
                {
                    int choice;
                    cout << "\n=======================\n\n";
                    cout << "     ADMIN PANEL \n";
                    cout << "\n=======================\n";
                    cout << "1. Add Book\n";
                    cout << "2. Show all Book\n";
                    cout << "3. Issue Book\n";
                    cout << "4. Find Book\n";
                    cout << "5. Return Book\n";
                    cout << "6. Exit Admin Panel\n";

                    cout << "Enter your choice: ";
                    choice = safeIntInput();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    LibraryBook library;

                    switch(choice)
                    {
                        case 1:library.addBook();break;
                        case 2:library.viewAllBooks();break;
                        case 3:library.issueBook();break;
                        case 4:library.findBook();break;
                        case 5:library.returnBook();break;
                        case 6:
                            adminRunning = false;
                            cout << "\nReturning to Library Menu...\n";
                            break;
                        default:cout << "\nInvalid choice!\n";
                    }
                }
            }
            break;
        }   
        case 2:
            {
                while(studentRunning)
                {
                    LibraryBook studentAccess;
                    int choice;
                    cout << "\n=====================\n";
                    cout << "\n   STUDENT PANEL \n";
                    cout << "\n=====================\n";
                    cout << "1. Show all Book\n";
                    cout << "2. Find Book\n";
                    cout << "3. Exit Student Panel\n";

                    cout << "Enter your choice: ";
                    choice = safeIntInput();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');

                    switch(choice)
                    {
                        case 1:studentAccess.viewAllBooks();break;
                        case 2:studentAccess.findBook();break;
                        case 3:
                            studentRunning = false;
                            cout << "\nReturning to Library Menu...\n";
                            break;
                        default:cout << "\nInvalid choice!\n";
                    }
                }
                break; 
            }

        case 3:
            libraryRunning = false;
            cout << "\n\nExiting from Library Management Panel\n";
            break;
        default:
            cout << "\nInvalid choice! Please select 1 or 2.\n";
    }

}
    return 0;
}