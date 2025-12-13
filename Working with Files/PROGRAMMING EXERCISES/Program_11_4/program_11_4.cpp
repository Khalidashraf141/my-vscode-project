#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

class Contact
{
private:
    char name[30];
    char phone[15];
public:
// Function to accept input from user
    void getDetails()
    {
        cout << "Enter Name: "<<endl;
        cin.ignore();
        cin.getline(name,30);
        cout << "Enter Phone Number: "<<endl;
        cin.getline(phone,15);
    }

// Function to display details
    void showDetails()const{
        cout << left << setw(20) << name << setw(15) << phone << endl;
    }

    // Accessor for Name
    char* getName()
    {
        return name;
    }

    // Accessor for Phone
    char* getPhone()
    {
        return phone;
    }

    // Mutator to update Phone
    void updatePhone(char* newPhone)
    {
        strcpy(phone,newPhone);
    }
};

// --- Helper Functions ---

void addRecord(){
    Contact c;
    ofstream outfile("phonebook.dat",ios::binary | ios::app); // Open in append mode
    c.getDetails();
    outfile.write((char*)&c, sizeof(c));
    outfile.close();
    cout << ">> Record Added Successfully.\n";
}


// (a) Determine the telephone number of the specified person
    void searchByName(){
        Contact c;
        char targetName[80];
        bool found = false;

        cout << "Enter Name of search: ";
        cin.ignore();
        cin.getline(targetName, 30);

        ifstream infile("phonebook.dat",ios::binary);
        if(!infile){
            cout << "Error: File could not be opened.\n";
            return;
        }

        while(infile.read((char*)&c,sizeof(c))){
            if(strcasecmp(c.getName(),targetName)== 0){
                cout << "\n>>Match Found!\n";
                cout << "Name: " << c.getName() << "\nPhone: " << c.getPhone() << endl;
                found = true;
                break;
            }
        }
        infile.close();
        if(!found)cout << ">> No record found for that name.\n";
    }


// (b) Determine the name if a telephone number is known
    void searchByPhone(){
        Contact c;
        char targetPhone[15];
        bool found = false;

        cout << "Enter Phone Number to search: ";
        cin.ignore();
        cin.getline(targetPhone,15);

        ifstream infile("phonebook.dat",ios::binary);
        if(!infile){
            cout << "Error: File could not be opened.\n";
            return;
        }

        while(infile.read((char*)&c, sizeof(c)))
        {
            if(strcmp(c.getPhone(),targetPhone) == 0){
                cout << "\n>> Match Found!\n";
                cout << "Name: " << c.getName() << "\nPhone: " << c.getPhone() << endl;
                found = true;
                break;
            }
        }
        infile.close();
        if(!found) cout << ">> No record found for that number.\n";
    }


// (c) Update the telephone number, whenever there is a change
    void updateRecord()
    {
        Contact c;
        char targetName[30];
        bool found = false;

        cout << "Enter the Name of the person to update: ";
        cin.ignore();
        cin.getline(targetName,30);
        
        fstream file("phonebook.dat",ios::binary | ios::in | ios::out);
        if(!file){
            cout << "Error: File could not be opened.\n";
            return;
        }
        while(file.read((char*)&c,sizeof(c))&& !found){
            if(strcasecmp(c.getName(),targetName) ==0){
                c.showDetails();
                cout << "\nEnter new Phone Number: ";
                char newPhone[15];
                cin.getline(newPhone,15);
                c.updatePhone(newPhone);


                // Move the file pointer back by one record size
                // seekp (offset, direction) -> move 'put' pointer
                int pos = -1*static_cast<int>(sizeof(c));
                file.seekp(pos,ios::cur);

                // Write the modified object
                file.write((char*)&c,sizeof(c));

                cout << ">> Record Updated Successfully.\n";
                found = true;
            }
            file.close();
            if (!file) cout << ">> Person not found in directory.\n";
        }
    }


    void displayAll()
    {
        Contact c;
        ifstream infile("phonebook.dat",ios::binary);
        if(!infile){
            cout << "File not created yet.\n";
            return;
        }
        cout << "\n--- DIRECTORY LISTING ---\n";
        cout << left << setw(20) << "NAME" <<setw(15) << "PHONE" << endl;
        cout << "----------------------------------------\n";
        while(infile.read((char*)&c,sizeof(c))){
            c.showDetails();

        }
        infile.close();
    }
int main()
{
    int choice;
    do{
        cout << "\n================================\n";
        cout << "   TELEPHONE DIRECTORY MENU    \n";
        cout << "================================\n";
        cout << "1. Add New Record (Setup)\n";
        cout << "2. Search by Name\n";
        cout << "3. Search by Phone Number\n";
        cout << "4. Update Telephone Number\n";
        cout << "5. Display All Records\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice)
        {
        case 1: addRecord();break;
        case 2: searchByName();break;
        case 3: searchByPhone();break;
        case 4: updateRecord();break;
        case 5: displayAll();break;
        case 6: cout << "Exiting program..";break;
        default: cout << "Invalid choice! Try again.\n";
        }
    }while (choice!=6);
    return 0;
}