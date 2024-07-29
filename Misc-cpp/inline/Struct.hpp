#pragma once

struct Struct {
    static int SomeOtherValue;
    
    inline static int ThisValue = 69; // this works, ,no need for a seperate c++
    
    static const int SomeValue = 10;
    static constexpr int SomeMoreValue = 10;

    inline static int noCppDef; // does not cause linked errors
};