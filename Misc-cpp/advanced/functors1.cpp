#include <iostream>
#include <vector>
#include <algorithm>

struct Value {
    int _result1{0};
    float _result2{0};

    float operator()(float newResult){
        _result2 = newResult;
        return newResult;
    }

    int operator()(int newResult){
        _result1 = newResult;
        return newResult;
    }
};

int main(){

    Value v;
    v(4.2f); v(42); // type conversions (ex double to float) are not implicit here, you can to manually write that into the class with a template maybe
    std::cout << v._result1 << std::endl;
    std::cout << v._result2 << std::endl;

    return 0;
}

// Functor = function object.
// - is an object/function with a State
//   operator() is overloaded in a class/struct

