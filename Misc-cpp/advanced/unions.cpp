#include <iostream>

union U {
    int i;
    short s;
    float f;
    double d;

    void printi(){
        std::cout << i << std::endl;
    }
};
// just big enough for the largest type

union Uni {
    int i;
    short s;
};
struct Struni {
    int i;
    short s;
};

int main(){

    U myUnion;
    myUnion.i = 2003;
    myUnion.printi();
    std::cout << myUnion.s << std::endl;
    std::cout << myUnion.f << std::endl;

    std::cout << sizeof(myUnion) << std::endl;
    std::cout << sizeof(int) << std::endl;
    std::cout << sizeof(short) << std::endl;
    std::cout << sizeof(float) << std::endl;
    std::cout << sizeof(double) << std::endl;
    std::cout << std::endl;


    Uni myUni;
    myUni.i = 2003;

    std::cout << sizeof(Uni) << std::endl;
    std::cout << sizeof(Struni) << std::endl;

    return 0;
}

// Union differs from a struct in an important way
// in that -
// it only holds the largest type

// This just used to pass different types of data around
// Compacts a shit ton of datatypes together

/**
 * +------------+
 * |            | --+
 * |            |   |
 * |     U      |   +-- sizeof(max(i, s, f))
 * |            |   |
 * |            | --+
 * +------------+
 */

// Cannot have or used as a base class
// Cannot have non-static data members of reference types
// Can have member function (including Constructors and Destructors) but
// Cannot have virtual functions