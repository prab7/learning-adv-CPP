#include <iostream>

int main(){

    int x = 10;
    int* ptr = &x;

    *ptr = 12;

    std::cout << "value x  : "<< x <<std::endl;
    std::cout << "addrs x  : "<< &x <<std::endl;
    std::cout << "size  x  : "<< sizeof(x) <<std::endl;
    std::cout << "val ptr  : "<< ptr <<std::endl;
    std::cout << "adr ptr  : "<< &ptr <<std::endl;
    std::cout << "deref ptr: "<< *ptr <<std::endl;
    std::cout << "size ptr : "<< sizeof(ptr) <<std::endl;
 
    return 0;
}