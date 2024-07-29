// Preprocessor directives
// Macros, #define, __LINE__, std::souce_location (C++20)

// header guards 
// or pragma once
#pragma once

#ifndef MAIN_HPP
#define MAIN_HPP

// g++ -E preprocessor.cpp | nl
// this will NOT compile our code, only preprocess the file
#include <iostream>
#include <source_location>

#ifndef DEBUG
#   define PI 3.1415926
#endif
// this is just a replacement, Here we dont know wether PI is being treated as a float, double or what implicit conversions may be happening
// #define PI 3.1415926

// preferred modern cpp style
constexpr float _PI = 3.1415926;

// #define DEBUG 1
// g++ -E -DDEBUG=0 preprocessor.cpp | nl


// function-lije Macros
#define LOG(param) std::cout << "LOG: " << #param << ' '; param; std::cout << std::endl;


// RESERVED MACROS __FILE__ __LINE__ __DATE__ __TIME__ etc.
// std::source_location, replacement for all this in C++20

int add(int a, int b){
    // std::cout << __LINE__ << ':' << __FILE__;;

    // C++20
    std::source_location location = std::source_location::current();
    std::cout << location.line() << ':' <<  location.function_name();

    return a+b;
}


int main(){

#ifdef DEBUG
    LOG(add(7,2);)
#else
    add(7, 2);
#endif

#ifdef PI
    std::cout << PI << std::endl;
#else 
    std::cout << (float)22/7 << '\n';
#endif

    return 0;
}

#endif