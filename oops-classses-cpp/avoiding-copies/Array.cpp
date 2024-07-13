#include "Array.hpp"
#include <iostream>

Array::Array(){
    std::cout << "Constructor" << std::endl;

    for(int i = 0; i < 1000000; i++){
        data.push_back(i);
    }
}
Array::~Array(){
    std::cout << "Destructer" << std::endl;
}

Array::Array(const Array& rhs){
    std::cout << "Copy Constructor" << std::endl;
    for(int i = 0; i < rhs.data.size(); i++){
        data.push_back(rhs.data[i]);
    }
}

Array& Array::operator=(const Array& rhs){

    std::cout << "Copy-Assignment Operator" << std::endl;

    if(&rhs == this){
        return *this;
    }
    data.clear();
    for(int i = 0; i < rhs.data.size(); i++){
        data.push_back(rhs.data[i]);
    }
    return *this;
}

void Array::PrintingData(){
    for(int i = 0; i < data.size(); i   ++){
        std::cout << data[i] << std::endl;
    }
}

void Array::SetData(int idx, int value){
    data[idx] = value;
}