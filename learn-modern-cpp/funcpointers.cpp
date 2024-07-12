#include <iostream>
#include <functional>

// best practice (C) function pointer as a type
typedef int (*PFnIntegerOperations)(int, int); 

int add(int x, int y){
    return x + y;
}

int multiply(int x, int y){
    return x * y;
}

int main(){

    int (*wop)(int, int); //function pointer
    PFnIntegerOperations cop; //best practice (C) function pointer

    std::function<int(int, int)> op; // modern cpp PFn

    std::cout << "1 for add, 2 for multiply" << std::endl;
    int n;
    std::cin >> n;

    if(n == 1){
        op = add;
    } else if (n == 2){
        op = multiply;
    }

    int x, y;
    std::cin >> x;
    std::cin >> y;
    std::cout << "Operation: " << op(x,y) << std::endl;

    return 0;

    // change which function the ptr points to at runtime
}
