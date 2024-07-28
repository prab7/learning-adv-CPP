#include <iostream>
#include <string>
#include <vector>

// trailing return type
template <typename T1, typename T2>
auto Multiply(const T1& a, const T2& b) {
    return a*b;
} 

int main(){

    std::vector<int> ints;
    ints.push_back(1);
    ints.push_back(2);
    ints.push_back(3);

    // best practice
    for(std::vector<int>::iterator it = ints.begin(); it != ints.end(); it++){
        std::cout << *it << std::endl;
    }
    // std::vector<int>::iterator is a mouthful, so auto 
    for(auto it = ints.begin(); it != ints.end(); it++){
        std::cout << *it << std::endl;
    }


    auto value = 72;
    std::cout << value << std::endl;

    return 0;
}

/**
 * used to be - automatic storage duration specifier (deprecated)
 * 
 * Modern Cpp
 * - auto placeholder type specifier
 * - function declaration with trailing return type
 * - structured binding declaration 
 * 
 * 
 */