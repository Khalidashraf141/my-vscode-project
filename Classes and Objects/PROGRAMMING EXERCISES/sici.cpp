//Write a program to calculate simple and compound intrest by using access operator
#include <iostream>
#include <cmath>
using namespace std;

class Calculate
{
    float principle;
    float rateOfinterest;
    float time;
    float amount;
    float CI;
    public:
        float simpleIntrest(float p, float r, float t)
        {
            principle = p;
            rateOfinterest = r;
            time = t;
        }
        void SiDisplay(void)
        {
            amount = (principle*rateOfinterest*time)/100;
            cout << "The Simple Intrest is: "<< amount << "\n";
        }

        float compoundIntrest(float p, float r, float t)
        {
            principle = p;
            rateOfinterest = r;
            time = t;
        }
        void CiDisplay(void)
        {
            amount = principle*pow(1+rateOfinterest/100,time);
            CI = amount-principle;
            cout << "The compound Intrest is: "<< CI << "\n";
        }
};

int main()
{
    Calculate c1;
    c1.simpleIntrest(100,5,2);
    c1.CiDisplay();

    c1.compoundIntrest(800,2,5);
    c1.CiDisplay();

    return 0;
    
}