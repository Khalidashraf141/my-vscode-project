#include <iostream>
#include <typeinfo>

class Org
{
    public:
        virtual ~Org(){}
};

class Dept : public Org{};
int main()
{
    Org org1;
    Dept dept1;
    Org *ptr = &dept1;

    std::cout << typeid(ptr).name() << std::endl;
    std::cout << typeid(*ptr).name() << std::endl;
    return 0;
}