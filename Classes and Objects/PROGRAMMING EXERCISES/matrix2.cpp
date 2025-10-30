#include <iostream>
using namespace std;

class Matrix
{
    int m[3][3];
    public:
        void read()
        {
            cout << "Enter elements of 3x3 matrix:\n";
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    cin >> m[i][j];
                }
            }
        }

        void display()
        {
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    cout << m[i][j] << "\t";
                }
                cout << "\n";
            }
        }

        //Friend function for multiplication
        friend Matrix multiply(Matrix a, Matrix b);

};

Matrix multiply (Matrix a, Matrix b)
{
    Matrix result;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            result.m[i][j] = 0; //resutl matrix initial value is 0 if we don't specify the the value the compiler will auto store some garbage value that will give wrong calcualtion from our expetation 
            for(int k = 0; k < 3; k++)
            {
                result.m[i][j] += a.m[i][k] * b.m[k][j];
            }
        }
    }
    return result; //returning object
}

int main()
{
    Matrix m1, m2, m3;

    cout << "Enter first matrix: \n";
    m1.read();

    cout << "Enter second matrix: \n";
    m2.read();

    m3 = multiply(m1,m2);
    cout << "\nResult of Multiplication:\n";
    m3.display();
    
    return 0;
}