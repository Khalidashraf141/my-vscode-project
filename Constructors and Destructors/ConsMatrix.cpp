#include <iostream>
using namespace std;

class matrix
{
    int **p; //pointer to matrix
    int d1,d2; //dimensions
    public:
        matrix(int x, int y);
        void get_element(int i, int j, int value)
        {
            p[i][j] = value;
        }
        int &put_element(int i, int j)
        {
            return p[i][j];
        }
        ~matrix()
        {
            for(int i = 0; i < d1; i++)
            {
                cout << "destructor is called:  .."; 
                delete[] p[i];
            }
            delete[] p; //it should be outside the loop othewise i will be called multiple times and crash the program
        }
};

matrix :: matrix(int x, int y)
{
    d1 = x;
    d2 = y;
    p = new int *[d1];
    for(int i = 0; i < d1; i++ )
    {
        p[i] = new int[d2];
    }
}

int main()
{
    int m, n;
    cout << "Enter size of Matrix: ";
    cin >> m >> n;
    matrix A(m,n); //matrix object A constructed

    cout << "Enter matrix elements row by row\n";
    int i, j , value;

    for(i = 0; i < m; i++ )
    {
        for(j = 0; j < n; j++)
        {
            cin >> value;
            A.get_element(i,j,value);
        }
    }
    cout << "\n";
    cout << A.put_element(0,0)<<"\n";

    return 0;
}