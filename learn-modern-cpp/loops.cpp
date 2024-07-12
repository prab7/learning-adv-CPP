#include <iostream>
#include <array>
#include <algorithm>

int main(){

    int arr[] = {1, 3, 5};
    std::array<int, 3> brr{1, 3, 5};

    for(int i = 0; i < brr.size(); i++){
        std::cout << brr[i] << std::endl;
    }
    // range based for loops
    for(int i: brr){
        std::cout << brr[i] << std::endl;
    } // wrong
    for(auto& element: brr){
        std::cout << element << std::endl;
    } // correct, avoids making copies of the elements
    
    //while(true){}
    //for(;;){}
    std::cout << std::endl;

    int countdown = 3;
    while(countdown > 0){
        std::cout << countdown << std::endl;
        countdown--;
    }

    do{
        std::cout << countdown << std::endl;
        countdown--;
    } while(countdown > 0);  // runs atleast once

    std::array<int, 4> myArray;

    std::fill(myArray.begin(), myArray.end(), 1024);

    for(int elem: myArray){
        printf("%d", elem);
        std::cout << std::endl;
    }

    return 0;
}




