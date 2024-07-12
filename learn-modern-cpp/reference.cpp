// reference and Alias
#include <iostream>
#include <typeinfo>

int main(){

    int x = 42;
    int& ref = x;
    // "int&" is the datatype for "reference type"

    x = 43;

    int* y = nullptr;
    int*& refy = y; // illegal
    // -Wall unused variable, but this is illegal generally, although no error is raised
    // can't have null as reference

    std::cout << "valueof x: " << x << std::endl;
    std::cout << "type of x: " << typeid(x).name() << std::endl;
    std::cout << "address x: " << &x << std::endl;

    std::cout << "value ref: " "concat    :" << ref << std::endl;
    std::cout << "type  ref: " << typeid(ref).name() << std::endl;
    std::cout << "addrs ref: " << &ref << std::endl;

    return 0;
}