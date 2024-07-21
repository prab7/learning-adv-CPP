#ifndef OBJECT_H
#define OBJECT_H

typedef struct {
    // attributes
    int value;
    // function pointers
    void (*pfnMemberFunc)(void);    
} programObject_t;

void init_programObject(programObject_t*);

#endif