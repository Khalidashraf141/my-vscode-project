//Write a function that receives two matrix objects as arguments and returns a new matrix object contaning their multiplication result.
//Out of syllabus
#include <iostream>
using namespace std;

class Matrix
{
    int rows, cols;
    int **data;

    public:
        //Constructor
        Matrix(int r, int c)
        {
            rows = r;
            cols = c;
            data = new int*[rows];
            for(int i = 0; i < rows; i++)
            {
                data[i] = new int[cols];
                for(int j = 0; j < cols; j++)
                {
                    data[i][j] = 0;
                }
            }
        }

        // Copy constructor (deep copy)
        Matrix(const Matrix &m)
        {
            rows = m.rows;
            cols = m.cols;
            data = new int*[rows];
            for(int i = 0; i < rows; i++)
            {
                data[i] = new int [cols];
                for(int j = 0; j < cols; j++)
                {
                    data[i][j] = m.data[i][j];
                }
            }
        }

        //Destructor
        ~Matrix(){
            for(int i = 0; i < rows; i++)
            {
                delete[] data[i];
            }
            delete[] data;
        }

        // Input matrix elements
        void input()
        {
            cout << "Enter elements (" << rows << 'x' << cols <<"):\n";
            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < cols; j++)
                {
                    cin >> data[i][j];
                }
            }
        }
        //Display matrix
        void display() const
        {
            for(int i = 0; i < rows; i++)
            {
                for(int j = 0; j < cols; j++)
                {
                    cout << data[i][j] << " ";
                }
                cout << "\n";
            }
        }

        // Friend function for multiplication
        friend Matrix multiply(const Matrix &A, const Matrix &B);
};

//Function to multiply two matrices
Matrix multiply(const Matrix &A, const Matrix &B)
{
    if(A.cols != B.rows)
    {
        cout << "Matrix multiplication not possible! (A.cols != B.rows)\n";
        return Matrix(0,0); //return empty matrix
    }
    Matrix result(A.rows, B.cols);

    for(int i = 0; i < A.rows; i++)
    {
        for(int j = 0; j < B.cols; j++)
        {
            for(int k = 0; k < B.cols; k++)
            {
                result.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }

    }
    return result;
}

int main()
{
    int r1, c1, r2, c2;
    cout << "Enter rows and cols for Matrix A: ";
    cin >> r1 >> c1;
    cout << "Enter rows and cols for Matrix B: ";
    cin >> r2 >> c2;

    Matrix A(r1, c1), B(r2, c2);

    cout << "Matrix A:\n";
    A.input();
    cout << "Matrix B:\n";
    B.input();

    Matrix C = multiply(A, B);
    cout << "\nResultant Matrix (A x B):\n";
    C.display();

    return 0;
}