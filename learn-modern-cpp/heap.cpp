// new expression
/* Creates and initializes objects with dynamic storage duration, that is, objects whose lifetime is not necessarily
    limited by the scope in which they were created 
*/
#include <iostream>
#include <array>

int* AllocateMemory(){
    return new int;
}

int main(){
    int* ptr = AllocateMemory();
    int* y = new int;
    int* z = new int; //20 mem intervals mein allocate ho rha hai
    int x = 7;

    std::cout << "val  ptr : " << ptr          << std::endl;  
    std::cout << "adrs ptr : " << &ptr         << std::endl;
    std::cout << "size ptr : " << sizeof(ptr)  << std::endl;
    std::cout << "val    y : " << y            << std::endl;  
    std::cout << "adrs   y : " << &y           << std::endl;
    std::cout << "size   y : " << sizeof(y)    << std::endl;
    std::cout << "val    z : " << z            << std::endl;  
    std::cout << "adrs   x : " << &x           << std::endl;
    std::cout << "size   x : " << sizeof(x)    << std::endl;
    std::cout << "deref ptr: " << *ptr         << std::endl;
    std::cout <<  std::endl;




    int numberOfStudents = 0;

    std::cout << "How many students do you have?" << std::endl;
    std::cin >> numberOfStudents;

    // int students[numberOfStudents];          SEGMENTATION FAULT :: overflows the stack
    int* students = new int[numberOfStudents];

    for(auto i = 0; i < numberOfStudents; i++){
        
        students[i] = i;
        //std::cout << students[i] << std::endl;
        //std::cout << &students[i] << std::endl;
    }

    delete[] students;

    /* new allows us to allocate resources at runtime
      resource is returned to us in a pointer
    */
    return 0;
}

/*
val  ptr : 0x55e9fc1f9eb0
adrs ptr : 0x7fffc4157088
size ptr : 8
val    y : 0x55e9fc1f9ed0
adrs   y : 0x7fffc4157090
size   y : 8
val    z : 0x55e9fc1f9ef0
adrs   x : 0x7fffc415707c
size   x : 4
deref ptr: 0

How many students do you have?
1000000000

NO SEGFAULT WHEN HEAP
*/