#include <iostream>
#include <cmath>

template <typename T>
bool equal(T a, T b){
    return (a==b);
}

template<>
bool equal<float>(float a, float b){ // still works without <float>
    std::cout << "equal<float>\n";
    return fabs(a-b) < 0.00001f;
}
template<>
bool equal<double>(double a, double b){ // still works without <double>
    std::cout << "equal<double>\n";
    return abs(a-b) < 0.00000001f;
}

int main(){

    std::cout << equal<int>(2,2) << std::endl;
    std::cout << equal<int>(2,3) << std::endl; 

    std::cout << equal<float>(1.0f-0.999999f, 0.000001f) << std::endl;
    std::cout << equal<float>(1.0f, -2.38f) << std::endl;

    std::cout << equal<double>(1.0f-0.9999999999f, 0.0000000001f) << std::endl;

    return 0;
}