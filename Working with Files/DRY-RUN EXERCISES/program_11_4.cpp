#include <iostream>
#include <fstream>

int main()
{
    char ch;
    std::ofstream fout;
    fout.open("Text.txt");
    // fout = (std::ofstream)std::cout;
    fout << "Hello" << "\n";
    fout << "how" << "\n";
    fout << "are" << "\n";
    fout << "you" << "\n";
    fout << "you" << "\n";
    return 0;
}