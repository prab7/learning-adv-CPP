#include <iostream>
#include <memory>

// Custom Deleters

struct IntDeleter {
    void operator()(int* int_ptr){
        std::cout << "IntDeleter called" << std::endl;
        delete int_ptr;
    }
    static size_t counter; // tag memory and do some interesting operations in here
};

size_t IntDeleter::counter = 0;

int main(){

 // std::unique_ptr<int, IntDeleter> my_ptr = std::make_unique<int>();
    std::unique_ptr<int, IntDeleter> my_ptr(new int);

    return 0;
}