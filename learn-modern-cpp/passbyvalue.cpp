#include <iostream>

void SetValue(int arg){
    std::cout << "val arg: " << arg << std::endl;
    arg = 9999;
    std::cout << "val arg: " << arg << std::endl;
    std::cout << "adr arg: " << &arg << std::endl;
}

int main(){
    
    int x = 42;
    std::cout << "value x: " << x << std::endl;
    std::cout << "addrs x: " << &x << std::endl;
    
    SetValue(x);
    
    std::cout << "value x: " << x << std::endl;
    std::cout << "addrs x: " << &x << std::endl;

    return 0;
}

