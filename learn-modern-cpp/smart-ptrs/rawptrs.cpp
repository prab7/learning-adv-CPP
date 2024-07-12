#include <iostream>

int main(){

    int x = 42;
    int* px = &x;
    int* px2 = px;
    // raw pointers allow sharing  -- allow room for errors, forgetting to dealloc, Ownership

    int* arr = new int[100];
    
    for(auto i = 0; i < 100; i++){
        arr[i] = i+1;
    }

    int* ptr = arr;

    delete[] arr;
    float* newarray = new float[100];

    int* ptr2 = ptr;

    std::cout << "*ptr   : " << *ptr << std::endl;
    std::cout << "*ptr2  : " << *ptr2 << std::endl;


    return 0;
}