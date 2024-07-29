#include <iostream>

struct MyStruct {

    void Function(){

        // capture by reference 
        auto fun = [&, this](){
            counter++;
            std::cout << "counter inside lambda fun  : " << counter << this->counter << std::endl;
        };
        // capture by copy
        auto func = [*this]() mutable {
            counter--;
            std::cout << "counter inside lambda func : " << counter << this->counter << std::endl;
        };
        // deprecated since C++20, use explicit this or *this instead
        auto funce = [=]() mutable {
            counter--;
            std::cout << "counter inside lambda funce: " << counter << this->counter << std::endl;
        };
        fun();
        func();
        funce();

        std::cout << "counter: " << counter << std::endl;
    }
    
    int counter;
};

// [captures] (params) {body}

int main(){

    MyStruct instance; 

    instance.Function();
    instance.Function();
    instance.Function();
    instance.Function();

    return 0;
}