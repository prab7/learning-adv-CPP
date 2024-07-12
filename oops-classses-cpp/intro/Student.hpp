#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>


class Student{
    public:
        // Actions - Constructor
        Student();
        Student(std::string name);
        // Actions - Destructor
        ~Student();
        // Actions - Print student name
        void printName();

    private:
        std::string m_name;
};

#endif