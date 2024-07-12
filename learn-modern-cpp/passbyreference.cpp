#include <iostream>
#include <vector>
#include <algorithm>

void PassByValue(int arg){
    std::cout << "adr arg: " << &arg << std::endl; 
    arg = 9999;
}
void PassByReference(int& arg){
    std::cout << "adr arg: " << &arg << std::endl;
    arg = 9999;
}
void PassByValue(std::vector<int> arg){
    std::cout << "adr arg: " << &arg << std::endl; 
    arg[0] = 1;
}
void PassByReference(std::vector<int>& arg){
    std::cout << "adr arg: " << &arg << std::endl;
    arg[0] = 2;
}

// Pass by Value makes a copy  -- EXPENSIVE
// Pass by Reference doesn't   -- EFFICIENT

// Mutate data   --- REFERENCE
// use Argvalue  --- VALUE

int main(){
    
    int x = 42;
    std::cout << "value x: " << x << std::endl;
    std::cout << "addrs x: " << &x << std::endl;
    
    PassByReference(x);
    
    std::cout << "value x: " << x << std::endl;
    std::cout << "addrs x: " << &x << std::endl;

    std::vector<int> w(10000);
    //w.reserve(1000);
    std::fill(w.begin(), w.end(), 1);

    PassByReference(w); 
    PassByValue(w); 

    return 0;
}   










