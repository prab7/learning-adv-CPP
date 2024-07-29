// intent of 'inline' specifier is to serve as a hint to the compiler to perform optimizations,
// such as function inlining
// compilers usually just ignore the presence or absence of the inline specifier for the purpose of optimization

// compileroptimization.com

// put this code in godbolt
#include <iostream>

// caution: this will also ignore the flag -fno-inline
__attribute__((always_inline)) inline 
auto add(int a, int b){
    int d = 6;
    int e = 7;
    int f = 8;
    int g = 9;
    return a+b;
}
// in asm it can be seen that this gets embedded in main due to inline
// -O2 optimization will get rid of these lines not doing shit

int main(){

    int value = add(4,5);

    return 0;
}

// for every function call, compiler has to create a frame or "activation context" 
// it goes through the entire function decl, body, ret, etc.

// inlining just inserts the body of the code into the function call;
// no jumping, easy on hardware because it does not harm "locality"

// locality -> hardware can guess the next instructions easily
//          -> other optimizations enabled (ex. 4+5 = 9 transformation)
// cons: 1. code size increases.
//       2. debugging may be more difficult, control flow lost.
