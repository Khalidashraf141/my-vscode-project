#include <iostream>
using namespace std;

class Matrix
{
    int m[3][3];
    public:
    void read(void)
    {
        cout << "Enter the elements fo the 3x3 matrix: \n";
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cout << "m["<<i<<"] ["<<j<<"] = ";
                cin >> m[i][j];
            }
        }
    }

    void display(void)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                cout << m[i][j]<<"\t";
            }
            cout << "\n";
        }
        cout << "\n";
    }
    friend Matrix transpose(Matrix m1);
};

    Matrix transpose(Matrix m1)
    {
        Matrix m2;
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                m2.m[i][j] = m1.m[j][i];
            }
        }
        return m2;
    }
int main()
{
    Matrix mat1, mat2;
    mat1.read();
    cout << "\nYou entered the following matrix:\n";
    mat1.display();
    mat2 = transpose(mat1);
    cout << "\nTranpose matrix:\n";
    mat2.display();

    return 0;
}