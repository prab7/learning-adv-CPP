#include <iostream>
#include <vector>

template <typename T1, typename T2>
auto Multiply(const T1& a, const T2& b){
    return a*b;
} // compiler will De-juice the type C++14 ▲ 

template <typename T1, typename T2>
auto Multiply2(const T1& a, const T2& b) -> decltype(a*b){
    return a*b;
} 
// trailing returntype with decltype C++11 ▼


int main(){ 

    std::cout << Multiply2<float, int>(7.25f, 5) << std::endl; // works fine with primitive types

    return 0;
}

/**
 * Matrix x Vect2 
 */