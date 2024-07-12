#include <iostream>

void foo(){

    static int s_variable = 0;   // allocated in the executable, one time only with init=0, then live and persist within scope::foo
    s_variable += 1;

    std::cout << s_variable << std::endl;
}

int main(){
 
    int x = 0; // x is a local variable allocated on the stack
    int* p = new int;  // p is a local variable, points to memory allocated on the heap. The memory on the heap leaves until we say so.
    delete p;


    for(int i = 0; i < 10; i++){
        foo();
    }

    return 0;
}

// stack heap static
// static are allocated in the binary/executable-object

// objdump tool
// objdump -t ./prog 
// objdump -t ./prog | grep s_variable 
