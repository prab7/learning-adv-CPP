#include <iostream>
#include <variant> // C++17 ▲

union U {
    int i;
    short s;
};

int main(){

    std::variant<int, float> data; // not as compact as unions
    data = 7.0f; // wouldnt terminate if you explicitly type 1.0f

    std::cout << "U    : " << sizeof(U) << std::endl;
    std::cout << "data : " << sizeof(data) << std::endl;
    
    // constexpr somewhere ??

    std::cout << data.index() << std::endl;
    if(auto attempt = std::get_if<float>(&data)){
        std::cout << "We found a float" << std::endl;
    }

    std::cout << "data : " << get<float>(data) << std::endl; // hmm, wierd. program terminates
    std::cout << "data : " << get<int>(data) << std::endl; // alt + ▲▼

    return 0;
}

// std::variants is just tagged unions

// std::variant represents a type-safe union

// if you need type-safety, and not *that* optimized code. 