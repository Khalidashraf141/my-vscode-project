/*
-Create a class MAT of size m x n. Define all possible matrix operations for MAT type objects.
*/
#include <iostream>
using namespace std;

class MAT
{
    int m, n;       //matrix dimensions
    int a[10][10];  //fixed size array
public:
    //-----Constructor-----
    MAT()
    {
        m = n = 0;
    }
    MAT(int rows, int cols)
    {
        m = rows;
        n = cols;
    }

    // ----- Input and Output -----
    friend istream& operator>>(istream &in, MAT &x)
    {
        cout <<"Enter elements of " << x.m << "x" << x.n << " matrix:\n";
        for(int i = 0; i < x.m; i++)
        {
            for(int j = 0; j < x.n; j++)
            {
                in >> x.a[i][j];
            }
        }
        return in;
    }


    friend ostream& operator<<(ostream &out, MAT &x)
    {
        for(int i = 0; i < x.m; i++)
        {
            for(int j = 0; j < x.n; j++)
            {
                out << x.a[i][j] << "\t";
            }
            out << "\n";
        }
        return out;
    }


    // ----- Matrix Addition -----
    MAT operator+(MAT &b)
    {
        MAT temp(m,n);
        if(m != b.m || n != b.n)
        {
            cout << "Matrix dimensions must match for addition!\n";
            return temp;
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                temp.a[i][j] = a[i][j] + b.a[i][j];
            }
        }
        return temp;

    }


    // -----Matrix Subtraction -----
    MAT operator-(MAT &b)
    {
        MAT temp(m,n);
        if(m != b.m || n != b.n)
        {
            cout << "Matrix dimensions must match for subtraction!\n";
            return temp;
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                temp.a[i][j] = a[i][j] - b.a[i][j];
            }
        }
        return temp;
    }


    // ----- Matrix Multiplication -----
    MAT operator*(MAT &b)
    {
        MAT temp(m, b.n);
        if(n != b.m)
        {
            cout << "Matrix multiplication not possible!\n";
            return temp;
        }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < b.n; j++)
            {
                temp.a[i][j] = 0; //!define zero to avoid garbage value
                for(int k = 0; k < n; k++)
                {
                    temp.a[i][j] += a[i][k] * b.a[k][j]; //!wanna it will give some random value
                }
            }
            
        }
        return temp;
    }

    // ----Multiply by Scalar-----
    MAT operator*(int scalar)
    {
        MAT temp(m,n);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                temp.a[i][j] = a[i][j] * scalar;
            }
        }
        return temp;
    }

    // ---- Transpose -----
    MAT transpose()
    {
        MAT temp(n,m);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                temp.a[j][i] = a[i][j];
            }
        }
        return temp;
    }
};
// ----- Main function ------
int main()
{
    int m, n;
    cout << "Enter size of matrix (rows and columns): ";
    cin >> m >> n;

    MAT A(m,n), B(m,n);
    cin >> A;
    cin >> B;

    cout << "\nMatrix A: \n" << A;
    cout << "\nMatrix B: \n" << B;

    MAT C = A + B;
    cout << "\nA + B = \n" << C;

    MAT D = A - B;
    cout << "\nA - B = \n" << D;

    MAT E = A * 2;
    cout << "\nA * 2 = \n" << E;

    MAT F = A.transpose();
    cout << "\nTranspose of A: \n";

    //For multiplication, only valid if A.n == B.m
    if(n == m)
    {
        MAT G = A * B;
        cout << "\nA * B = \n" << G;
    }
    return 0;
}
//TODO:PRACTICE
