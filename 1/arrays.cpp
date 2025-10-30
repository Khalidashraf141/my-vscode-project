#include <iostream>
#include <vector> //resizable arrays
using namespace std;


int main(){
    //string arrays
    string myCar[4] = {"BMW","Buggati","Audi","Range Rover"};
    cout << myCar[0]<<endl;
    
    //change the value of specific element,refer to the index number
    myCar[0] = "Ford";
    cout << myCar[0]<<endl;

    //integers arrays
    int code[4] = {234,441,141,786};
    cout << code[0]<<endl;

    //array elements with the for loop
    string cars[5] = {"Ford","Mustang","NissanGTR","Audi","Lamborghini"};
    for(int i = 0; i<=4; i++){
        cout << cars[i] << endl;
    }

    //foreach loop Numbers
    for(int i : code){
        cout << i << endl;
    }
    //foreach loop string
    for(string car : cars){
        cout << car << endl;
    }

    //omit array size
/*if we don't specify the size of the array The compiler is smart enough to determine the size of the array based on the number of inserted values
-It is also possible to declare an array without specifying the elements on declaration and add them later-It only works when you have specified the size of the array.If you don't specify the array size an error occurs

Fixed size (Arrays) vs. Dynamic Size (Vectors)
-Size of any array in C++ is fixed, meaning you cannot add or remove elements after it is created

Vectors
-For operations that require adding and removing array elements C++ provides vectors which is resizable arrays.
-The size of vector is dynamic meaning it can grow and shrink as needed.Vectors is found in <vectors> library

*/

    string names[3] = {"Khalid","Fahad","Osama"};
    string newName[5];
    newName[0] = "Riko";
    newName[1] = "WatchDog";
    newName[2] = "Jarvis";
    for(string name : newName){
        cout << name<<endl;
    }
    for(string name_1 : names){
        cout << name_1 << endl;
    }

/*    string error_test[];
    error_test[0] = "Hello"; This will throw error*/ 
    
// -sizeof() operator return the size of a type in bytes.

    string animals[4] = {"Dog","Cat","Lion"};//24bytes each
    cout << sizeof(animals)<<endl;
    animals[3]="Cheetah";
    cout << sizeof(animals)<<endl; 

/*
            (1Byte = 8Bit)      
-why did result show 20 insted of 5,
Data Types chapter that an int type is usually 4 bytes, so from the example above (4bytes * 5 elements) = 20bytes

*/
    int rollNumber[5] = {12,13,14,15,56};//4bytes
    cout << sizeof(rollNumber);

//Vectors - Dynamic Size
    vector<string> studentList = {"Patrik","Joe","Faraday"};
    studentList.push_back("Helio");

//Size of array
    int customerId[5] = {121,454,786,121,98};
    for(int i = 0; i<sizeof(customerId)/sizeof(customerId[0]);i++){
        cout << customerId[i] << endl;

    }
            //Real Life Examples
//Calculate the average of different ages:
    int ages[8] = {20,25,67,88,21,18,16,10};
    float avg;
    int sum = 0;

    int length = sizeof(ages)/sizeof(ages[0]);
    for(int age:ages){
        sum+=age;
    }
    
    avg = sum/length;
    cout << "The average age is: "<< avg << endl;

//Lowest age among different ages:
    int newages[] = {12,34,66,45,6,98,10};
    int lowestage = newages[0]; //Initialize with the first element to ensure proper comparison with all elements.
    for(int age:newages){
        if(lowestage>age){
            lowestage=age;
        }
    }
    cout<<"The lowest age is: "<< lowestage << endl;


                      //Multidimensional Arrays

    string letters[2][4]={
        {"A", "B", "C", "D"},
        {"E", "F", "G", "H"}
    };
    cout << letters[0][2]<<endl;
    letters[0][2] = "Z";
    cout << letters[0][2]<<endl;

    //loop for outputs all elements in the letters array.
    for(int i = 0; i<2; i++){
        cout<<endl;
        for(int j = 0; j<4; j++){
            cout <<letters[i][j];
        }
    }
    //Game of Battleship:
//We put "1" to indicate there is a ship
    bool ships[4][4] = {
        {0, 1, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0}
    };

    //Keep track of how many hits the player has and how many turns they have played in these variables
    int hits = 0;
    int numberOfTurns = 0;

    //Allow the player to keep going unit they have hit all four ships
    while(hits<4){
        int  row,column;

        cout << "Selecting coordinates"<<endl;

        //ask player for a row
        cout << "Choose a row number between 0 and 3: ";
        cin >> row;

        //ask player for a column
        cout << "Choose a column number between 0 and 3: ";
        cin >> column;

        if(ships[row][column]){
            ships[row][column] = 0;
            hits++;
            cout << "Hit!" << (4-hits) <<"left"<<endl;
        }else{
            cout << "Miss"<<endl;
        }
        numberOfTurns++;
    }
    cout << "Victory!"<<endl;
    cout << "You won in"<< numberOfTurns << "Turns";
    return 0;
}