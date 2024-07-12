#include <iostream>
#include <vector>

int main(){

    int x = 7;
    int* px = &x;

    // STACK allocated array
    int array[] = {1,3,5,7,9};

    // HEAP allocated array
    int* dynamicallyAllocatedArray = new int[1000];

    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);

    std::cout <<"sizeof x                        : " << sizeof(x)                         << std::endl;
    std::cout <<"sizeof px                       : " << sizeof(px)                        << std::endl;
    std::cout <<"sizeof array                    : " << sizeof(array)                     << std::endl;
    std::cout <<"sizeof dynamicallyAllocatedArray: " << sizeof(dynamicallyAllocatedArray) << std::endl; // This is a pointer
    std::cout <<"sizeof vec (data structure)     : " << sizeof(vec)                       << std::endl; // size of data structure only
    std::cout <<"# of elems in vec (vec.size())  : " << vec.size()                        << std::endl; 
 
    return 0;
}