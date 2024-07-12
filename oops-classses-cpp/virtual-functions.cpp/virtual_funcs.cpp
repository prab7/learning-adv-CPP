#include <iostream>

class Base {
    public:
        Base() { std::cout << "Base Constructor" << std::endl; }
        ~Base(){ std::cout << "Base Destructor"  << std::endl; }

        virtual void MemberFunc(){
            std::cout << "Base::MemberFunc()\n";
        }
};

class Derived : public Base {
    public:
        Derived() { std::cout << "Derived Constructor" << std::endl; }
        ~Derived(){ std::cout << "Derived Destructor"  << std::endl; }

        virtual void MemberFunc() override {
            std::cout << "Derived::MemberFunc()\n";
        }
        // override keyword isn't necessary, but always a good practice
};

int main(){

   // Derived instance;
   // instance.MemberFunc();

    Base* instance = new Derived; // Inheritance based polymorphism

   // Base& alias = *instance;
   // alias.MemberFunc();
   // (*instance).MemberFunc();

    instance->MemberFunc();
    instance->Base::MemberFunc();
    delete instance;
    

    return 0;
}

 