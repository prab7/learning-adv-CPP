#include <iostream>
#include "Person.hpp"

int main(){

    Person mike("mike");

    std::cout  << mike.GetAttribute() << std::endl;

    return 0;
}