#include <iostream>
#include <string>

class TopLvlClass {
    public:
        TopLvlClass(std::string arg){
            std::cout << "top level class Constructor" << std::endl;
        }
        ~TopLvlClass(){
            std::cout << "top level class Destructor" << std::endl;
        }
};

class EntityBase : public TopLvlClass{
    public:
        EntityBase() : TopLvlClass("arg"){
            std::cout << "EntityBase Constructor" << std::endl;
        }
        EntityBase(std::string name) : TopLvlClass("arg"), m_name(name) {
            std::cout << "EntityBase(" << name <<") Constructor" << std::endl;
        }
        ~EntityBase(){
            std::cout << "EntityBase Destructor" << std::endl;
        }
    
    private:
        std::string m_name;
};

class Monster : public EntityBase {
    public:
        Monster() : EntityBase("default"){
            std::cout << "Monster Constructor" << std::endl;
        }
        ~Monster(){
            std::cout << "Monster Destructor" << std::endl;
        }
};


int main(){

    Monster BadMonster;


    return 0;
}