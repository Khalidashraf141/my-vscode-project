/*Write a program to display the value of 22/7 in different precision setting*/
#include <iostream>
#include <iomanip>

int main()
{
    long double pi = 22.0L / 7.0L;

    std::cout << std::fixed << std::setprecision(3) << pi << std::endl;
    std::cout << std::fixed << std::setprecision(20) << pi << std::endl;
    std::cout.unsetf(std::ios::fixed);
    std::cout << std::showpoint << std::setprecision(6) << pi << std::endl;
    return 0;
}