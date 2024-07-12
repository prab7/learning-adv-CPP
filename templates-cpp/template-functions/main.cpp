#include <iostream>

template <typename T> // 'class' keyword only in Modern cpp
T square(T input){
    return input*input;
} // generates the overload of the function needed

auto square2(auto input){  // C++20 feature only
    return input*input;
}
// Abbreviated function template
// fancy name for auto keyword in the arguments

int main(){

     // instantiation
    std::cout << square<int>(5) << std::endl;
    std::cout << square2(5) << std::endl;

    return 0;
}
