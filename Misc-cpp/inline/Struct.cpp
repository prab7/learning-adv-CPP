#include "Struct.hpp"

// because error: ISO forbids in-class initialization of non-cost static member 'Struct::SomeValue'
int Struct::SomeOtherValue = 8;

