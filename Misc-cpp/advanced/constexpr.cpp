#include <iostream>

constexpr int add(int a, int b){
    return a+b;
}

int main(){

    int j = add(7,16);
    constexpr int i = add(7,9); // evaluated at compile time

    // gotcha!
    constexpr float f = 3.14152694f * 3.0f; // varies with compiler but, answer may vary depending on compiletime and runtime

    return 0;
}

// Would you rather find a bug in your code in -
// Compiletime, Runtime, or Linktime ?

// Compiletime!! (maybe linktime)

// how to do stuff during compile time ?
/**
 * auto
 * Templates
 * constexpr
 */