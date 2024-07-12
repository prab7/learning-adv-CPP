#include <iostream>

int countdown(int n){
    // 1. Base case
    if(n==0){
        std::cout << "0...blast off!" << std::endl;
        return 0;
    }
    // 2. Recursive case
    std::cout << n << std::endl;
    return countdown(n-1);
}

int main(){

    countdown(500000); //Seggs fault
    // Stack overflow HAHAHAHAAAA
    return 0;
}