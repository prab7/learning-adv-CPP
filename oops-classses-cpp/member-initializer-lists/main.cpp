#include "Vector3f.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Vector3f& obj){
    os << obj.x << "," << obj.y << "," << obj.z;
    return os; 
}

int main(){

    Vector3f myVector;

    std::cout << myVector << std::endl; 


    return 0;
}