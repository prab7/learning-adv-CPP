#include "IntArray.hpp"
#include <iostream>
#include <vector>


void fooo(IntArray temp){
}
IntArray foo(){
    IntArray result("foo created array");
    return result;
}


int main(){
    /*
    IntArray arr1("arr-1");
    IntArray arr2 = arr1;
    
    fooo(arr1); // pass by value semantics

    // Return value optimization
    IntArray arr3 = foo(); // compiler magic, no re-copying !!
    */
   /*
    std::vector<IntArray> myArrays;
    myArrays.reserve(10);
    for(int i = 0; i < 10;i++){
        IntArray temp(std::to_string(i));
        myArrays.push_back(temp);
    }
    */

    
    std::vector<IntArray> myArrays;
    myArrays.reserve(10);
    for(int i = 0; i < 10;i++){
        IntArray temp(std::to_string(i));
        myArrays.push_back(std::move(temp));
    }

    return 0;
}