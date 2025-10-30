//Question - Write a function to read a matrix of size m x n from the keyboard. both 4.1 and 4.2 and 4.3 (default arguments)
//Practice it.
#include <iostream>
#include <vector>
#include <string>
using namespace std;


void readandDisplayMatrix(int column, int row)
{
    // int matrix[100][100];
    vector<vector<int>> matrix(column, vector<int>(row));

    cout << "Enter elements of matrix (" << row << "x" << column << "):" << "\n";

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++){
            cin >> matrix[i][j];
        }
    }

    cout << "The matrix is: " << "\n";
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            cout << matrix[i][j] <<"     ";
        }
        cout << "\n";
    }
}

int main()
{   string input;
    int row, column;

    cout << "Enter row (press Enter for default 4): ";
    getline(cin,input); //input as string
    if(input.empty()){
        row = 4; //default
    }
    else{
        row = stoi(input); // convert sring - int
    }

    cout << "Enter the column: ";
    cin >> column;

    readandDisplayMatrix(row,column);
    return 0;

}