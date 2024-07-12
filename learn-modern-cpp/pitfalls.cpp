#include <iostream>

int* returnMemory(){
    int result = 42;
    return &result;
}

int main(){

    int* px = nullptr;
    *px = 42; // dereferencing a nullptr

    int* array = new int[1000];
    // memory leak and crash

    int* ptr = returnMemory();
    std::cout << "*px: "<< *ptr << std::endl;
    // dangling pointer

    int* x = new int;
    *x = 42;
    delete x;
    delete x; // double free

    return 0;
} 