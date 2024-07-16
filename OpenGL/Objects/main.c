#include "object.h"

int main(){

    programObject_t example;
    init_programObject(&example);
    example.pfnMemberFunc();

    return 0;
}

// it's a c based library, part of the reason why we dont just have
// methods on an objects, but rather a function for literally everything in openGL
