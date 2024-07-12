#include <iostream>
#include <vector>

template <typename first, typename second>
struct Entry {
    Entry(first key, second value) : m_key(key), m_value(value){
    }
    first m_key;
    second m_value;
};

int main(){

    Entry entry(5, 100.1f); // despite this error, it works! (C++17 ▲)

    std::cout << entry.m_key << std::endl;
    std::cout << entry.m_value << std::endl;

    std::vector v1{1,2,3,4,5}; // still compiles    
    // std::vector v1{1,2,3.0f,4,5}; // this doesn't

    return 0;
}

// Class template argument deduction (CTAD)