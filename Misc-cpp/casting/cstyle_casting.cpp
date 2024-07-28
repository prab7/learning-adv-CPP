#include <iostream>
#include <iomanip>

// always use -Wall

int main(){
    
    std::cout << std::fixed;
    std::cout << std::setprecision(6);
    std::cout << 7/5                << std::endl; // int/int = int
    std::cout << (float)7/5         << std::endl; // 5 gets promoted to float  during calculation (implicit conversion)
    std::cout << (float)7/(double)5 << std::endl; // 7 gets promoted to double during calculation (implicit conversion)

    int result = 72;
    // unsigned short c = result;  // short c = (short) result;
    unsigned char  c = result; // char c = (char) result;

    std::cout << c              << std::endl;
    std::cout << (int)c         << std::endl;
    std::cout << sizeof(result) << std::endl;
    std::cout << sizeof(c)      << std::endl; // easy to overflow


    int i = -2;
    unsigned int u = 1;

    // we are comparing the bits of i to the bits of u
    // 111111110 > 0000000001 ofcourse
    // or maybe implicity conversion to unsigned for correct context
    // but we don't know what the compiler is exactly doing.
    if(i > u) std::cout << "huh??" << std::endl;

    // CPP best practice
    if(std::cmp_greater(i, u)) std::cout << "Should not print\n";


    return 0;
}

// cstyle (castes) are RUNTIME casts
// use -Wall always