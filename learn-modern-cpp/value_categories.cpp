#include <iostream>
#include <string>

int get42(){
    return 42;
}

void setValueTo99(const int& changeMe){
    // changeMe = 99;
}

int main(){
    
    int i = 10;
    setValueTo99(i);
    // 10 = i;


    // lvalue reference
    int& lvref = i;
    // int& ref1 = 1; // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    const int& lvrefc = 10; // works!! check out compiler explorer
    // here 10 ends up being a temp variable in the compiler somewhere
    int temp = 10;
    const int& lvreff = temp;

    setValueTo99(10);


    // rvalue reference
    int&& rvref = 10; 
    std::cout << rvref << std::endl;

    std::string s1 = "long string Hello";
    std::string s2 = " World long string";
    std::string s3 = s1 + s2; // elavuate the result and copy it into s3

    std::string&& srvref = s1+s2; // alias for r value, effiecient, no copying

    std::cout << srvref << std::endl;

    // examples
    int a = 2;
    int b = 3;
    int c = (a+b); 

    int array[100];
    array[10+a];


    // get42() = 100; this is an rvalue not lvalue

    return 0;
}

/**
 * lvalue | rvalue
 * -------+--------
 * a,b,c  | 1, 2
 *        | (a+b), 10+a --> xvalue (expiring value)
 */

/**
 * lvalue: something with a memory location.  ex. &(i)
 * 
 * lval
 * int i = 10;
 *         rval
 * 
 * rvalue: (on the right side of an assignment) doesn't point anywhere 
 */

/**
 * lvalue reference: int& lvref = i
 */

