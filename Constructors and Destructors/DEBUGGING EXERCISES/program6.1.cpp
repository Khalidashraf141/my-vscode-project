//6.1 Find the error in the following program
#include <iostream>
using namespace std;
class cube
{
    private:
        int length;
        int breadth;
        int width;
    public:
        cube(): length(5), breadth(5), width(5) { }
        cube (int l, int b = 5) : length(l), breadth(b) { } //here was the error
        int area_of_cube() { return length*breadth;}
        int volume_of_cube() {return length*breadth*width;}

        void display(int temp)
        {
            cout << temp << "\n";
        }
};

int main()
{
    cube A1(4), B1,A2(4,4); //A1 was taking one argument which was not valid so i add a default number at line number 12 b = 5
    int temp;
    cout << "Default Area " << "\n";
    temp = A1.area_of_cube();
    A1.display(temp);
    cout << "Default volume" << "\n";
    temp = B1.volume_of_cube();
    A1.display(temp);
    cout << "Area when argument is 4" << "\n";
    temp = A2.area_of_cube();
    B1.display(temp);
    return 0;
}