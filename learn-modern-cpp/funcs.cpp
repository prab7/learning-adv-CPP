#include <iostream>

//function declaration
int add(int, int);
auto add(float, float) -> float; 

void print(std::string string){
    std::cout << string << std::endl;
}

int main (){
    
    int sum = add(1, 2);
    int sum2 = add((double)2.6, (float)3.4); //idk why this works but it does

    std::cout << sum << std::endl; 
    std::cout << sum2 << std::endl; 

    return 0;
}

int add(int a, int b){
    std::cout << "int add(int, int)" << std::endl;
    return a + b;
}
float add(float a, float b){
    std::cout << "float add(float, float)" << std::endl;
    return a + b;
}

