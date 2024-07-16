#include "object.h"
#include <stdio.h>

void printSomething(){
    printf("hello\n");
}

void init_programObject(programObject_t* o){
    o->value = 0;
    o->pfnMemberFunc = printSomething;
}

