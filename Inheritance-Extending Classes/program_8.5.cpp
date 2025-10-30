//Hybrid Inheritance -> is a combination of two or more types of inheritance (like single, and multiple, multilevel, or hierarchical).

/*
✅Key Points
- Hybrid inheritance increases code reusability.
- can cause ambiguity (diamond problem).
- Virtual inheritance solves this by keeping only one copy of the 
   common base class.
*/

#include <iostream>
using namespace std;

class student
{
    protected:
        int roll_number;
    public:
        void get_number(int a)
        {
            roll_number = a;
        }
        void put_number(void)
        {
            cout << "Roll No: " << roll_number << "\n";
        }
};

class test : public student
{
    protected:
        float part_1, part_2;
    public:
        void get_marks(float x, float y)
        {
            part_1 = x;
            part_2 = y;
        }

        void put_marks(void)
        {
            cout << "Marks obtained: " << "\n"
                 << "Part 1 = " << part_1 << "\n"
                 << "Part 2 = " << part_2 << "\n";
        }
};

class sports
{
    protected:
        float score;
    public:
        void get_score(float s)
        {
            score = s;
        }
        void put_score(void)
        {
            cout << "Sports wt: " << score << "\n\n";
        }
};

class result: public test, public sports
{
    float total;
public:
    void display(void);
};

void result :: display(void)
{
    total = part_1 + part_2 + score;
    put_number();
    put_marks();
    put_score();

    cout << "Total Score: "<< total << "\n";

}

int main()
{
    result student_1;
    student_1.get_number(1234);
    student_1.get_marks(27.5,33.0);
    student_1.get_score(6.0);
    student_1.display();

    return 0;

}