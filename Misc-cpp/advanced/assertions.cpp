#include <iostream>
#include <cassert>

void checkAge(int inputAge){
    assert(inputAge > 0 && "age was less than 0");
}

constexpr int add(int a, int b){
    return a+b;
}

int main(){

    int age = 7; // make this -7 to break the assert below

    // if(age < 0){
    //     std::cout << "error" << std::endl;
    //     return 42;
    // }

    checkAge(age); // checkpoint, the proper thing to do is just crash the program if this statement is not true
    assert(age > 0); // gives a relevant line number


    constexpr bool schlong = false;
    constexpr int  num = 4;

    static_assert(sizeof(int) == 4, "int is 4 bytes");
    static_assert(add(2,2)==4, "2+2 is 4");
    static_assert(schlong == true, " \"schlong\" didn't forget the time he committed warcrimes in 'nam back in 1994 for nothin' ");


    // vscode is not happy about static_asserts being wrong

    return 0;
}

// Used for error handling
// for something that is a logical impossibility

// gives Line number on crashing, amazing.

// ERROR CAUGHT AT RUNTIME, crashes program to assert the error
// Compile time ?
// static_assert(bool-constexpr, message)
// static_assert(bool-constexpr) 



