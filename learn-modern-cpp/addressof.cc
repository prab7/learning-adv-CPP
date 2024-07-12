#include <iostream>

void foo(){
 //   x = 72;
}

int main(){

    int x = 42;
    float y = 72;
    char a = 'a';
    signed char b = 'b';
    unsigned char c = 'c';

    //this is stored in a stack , evident from below

    std::cout << "x: " << &x << std::endl;
    std::cout << sizeof(x) << std::endl;
    std::cout << "y: " << &y << std::endl;

    std::cout << "a: " << (void*)&a << std::endl; // C++ starts interpreting this as strings, when using & on characters
    std::cout << "b: " << (void*)&b << std::endl; // need to know standard string representation
    std::cout << "c: " << (void*)&c << std::endl; // we type cast this into something different, for now
    // (void*) to treat this as an address, explicitly

    std::cout << "foo: " << &foo << std::endl;
    std::cout << "main: " << &main << std::endl;
    std::cout << "foo: " << (void*)&foo << std::endl;
    std::cout << "main: " << (void*)&main << std::endl;
    
    return 0;
}