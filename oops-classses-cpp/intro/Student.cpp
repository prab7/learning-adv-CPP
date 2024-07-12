#include <iostream>
#include "Student.hpp"

// Actions- Constructor (special action)
Student::Student(){
    m_name = "no name";
    std::cout << "Constructor" << std::endl;
    std::cout << "m_name is " << m_name << std::endl;
}
Student::Student(std::string name){
    m_name = name;
    std::cout << "Constructor" << std::endl;
    std::cout << "m_name is " << m_name << std::endl;
}
// Actions - Destructor (special action)
Student::~Student(){
    std::cout << "Destructor " << m_name << std::endl;
}

void Student::printName(){
    std::cout << "name   is " << m_name << std::endl;
}