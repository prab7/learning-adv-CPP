#include <iostream>

class Person {
    public:
        Person(int age){
           // age = age;
           this->age = age;
        }/*
        Person(int age) : age(age){
        } // better
        */

        int GetAge() const {
            return this->age;
        }

        Person* GetThisAddress(){
            return this;
        }

        ~Person(){
            delete this;  // something happens but not recommended, usually just gives a uncomprehensible seggsfault
        }

    private:
        int age;
};

int main(){

    Person mike(500);
    std::cout << mike.GetAge() << std::endl; 
    std::cout << mike.GetThisAddress() << std::endl; 
    std::cout << &mike << std::endl; 

    Person* rishit = new Person(700);
    std::cout << rishit->GetThisAddress() << std::endl; 
    std::cout << &rishit << std::endl; 

    delete rishit;  
    
    return 0;
}

// 'this' is a ptr to the current instance of the object.