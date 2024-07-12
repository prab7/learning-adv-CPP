#include <iostream>
#include <type_traits>
#include <vector>
#include <algorithm>

void PassByReference(const std::vector<int>& arg){
    // arg[0] = 2;
}

int main(){

    std::vector<int> w(1000000000);
    std::fill(w.begin(), w.end(), 1);

    PassByReference(w);



    const int x = 42;
    std::cout << "x: " << x << std::endl;
    std::cout << std::is_const_v<int> << std::endl;
    std::cout << std::is_const_v<const int> << std::endl;
    std::cout << std::is_const<decltype(x)>::value << std::endl;
    //x = 37;

    return 0; 
}