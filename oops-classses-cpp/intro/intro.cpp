#include <iostream>
#include <string>

class Student{

    public:
        // Actions- Constructor (special action)
        Student(){
            std::cout << "Constructor" << std::endl;
        }
        // Actions - Destructor (special action)
        ~Student(){
            std::cout << "Destructor " << m_name << std::endl;
        }

        void printName(){
            std::cout << "name is " << m_name << std::endl;
        }

    public:
        std::string m_name;
    // Hidden 'fields' or 'attributes' or our class

};


int main(){
    std::cout << "Program starts here" << std::endl;
    {
        Student mike; //Block scoped
    }
    Student* mike = new Student; // heap alloc (outside stack)
    delete mike;
    std::cout << "Program ends here" << std::endl;
    std::cout << std::endl;



    Student nick;
    nick.m_name = "nick";
    nick.printName();

    Student Sue;
    Sue.m_name = "Sue";
    Sue.printName();


    return 0;
}

/**
 * 1. Information Hiding - public, private, protected
 */