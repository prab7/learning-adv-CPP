#include <iostream>

int main(){

    int arr[] = {1,3,5,7,9};
    int* px = arr;
    
    std::cout << arr[0]    << std::endl;
    std::cout << "px val     : " << px       << std::endl;
    std::cout << "px deref   : " << *px      << std::endl;
    std::cout << "px++ val   : " << ++px     << std::endl;
    std::cout << "px++ deref : " << *px      << std::endl;
    std::cout << "arr++ deref: " << *(arr+1) << std::endl;
    std::cout << "arr++ deref: " << *(arr+2) << std::endl;
    std::cout << "arr++ deref: " << *(arr+3) << std::endl;
    std::cout << "arr++ deref: " << *(arr+4) << std::endl;
    std::cout << "arr++ deref: " << *(arr+5) << std::endl;
    std::cout << "arr++ deref: " << *(arr+6) << std::endl;

    return 0;
}