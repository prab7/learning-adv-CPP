#include "IntArray.hpp"
#include <iostream>

// Constructor
IntArray::IntArray(std::string name): m_name(name), m_data(new int[10]){
    std::cout << m_name << " was constructed" << std::endl;
}

// Destructor
IntArray::~IntArray(){
    std::cout << m_name << " was destructed" << std::endl;
    delete[] m_data;

}
// Copy Constructor policy
IntArray::IntArray(const IntArray& rhs){
    m_name = rhs.m_name+" (copy)";
    std::cout << "was copy constructed from: " << rhs.m_name << std::endl;
    m_data = new int[10];
    for(int i = 0; i < 10; i++){
        m_data[i] = rhs.m_data[i];      
    }
}

// Copy Assignment operator policy
IntArray& IntArray::operator = (const IntArray& rhs){

    if(this != &rhs){

        delete[] m_data;
        m_name = rhs.m_name+" (copy)";
        std::cout << "was copy assigned from: " << rhs.m_name << std::endl;
        m_data = new int[10];
        for(int i = 0; i < 10; i++){
            m_data[i] = rhs.m_data[i];
        }
    }
    return *this;
}


// Move Constructor policy

IntArray::IntArray(IntArray&& source){

    m_name = source.m_name;
    source.m_name = "";
    m_data = source.m_data;
    source.m_data = nullptr;

    std::cout << m_name << " was move constructed" << std::endl;
}



// Move Assignment Operator policy

IntArray& IntArray::operator = (IntArray&& source) {
    if(this != &source) {

        m_name = source.m_name;
        source.m_name = "";
        m_data = source.m_data;
        source.m_data = nullptr;

        std::cout << m_name << " was move assignment" << std::endl;
    }
    return *this;
}

 