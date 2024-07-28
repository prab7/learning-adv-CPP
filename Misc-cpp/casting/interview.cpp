// static_cast v/s dynamic_cast

// Which C++ 'feature' would you use to cast a pointer to class B into a derived class D?
#include <iostream>

class Base{
    public:
    virtual void someFunction(){
        std::cout << "Base::someFunction\n";
    }
};
class Derived : public Base{
    int a;
    public:
    virtual void someFunction() override {
        std::cout << "Derived::someFunction\n";
    }

    virtual void DoAction(){
        std::cout << "Derived::DoAction\n";
    }
};

void myFunction(Base* b){
    if(dynamic_cast<Derived*>(b)){
        // is this valid?
    }
}

int main(){

    Base* B = new Base;
    // if 'object' is a complete type for 'Derived' then we can cast.
    Base* object = new Derived;
    Derived* D = new Derived;

    // returns nullptr 
    if(dynamic_cast<Derived*>(B)){
        std::cout << "1 dynamic_cast, this works! (in the compiler)\n";
    };
    if(dynamic_cast<Derived*>(object)){
        std::cout << "2 dynamic_cast, this works! (in the compiler)\n";
        dynamic_cast<Derived*>(object)->someFunction();
        dynamic_cast<Derived*>(object)->DoAction();
    };

    if(static_cast<Derived*>(object)){
        std::cout << "3 static_cast, this works! (in the compiler)\n";
        static_cast<Derived*>(object)->someFunction();
        static_cast<Derived*>(object)->DoAction();
    };
    if(static_cast<Derived*>(B)){
        std::cout << "4 static_cast, this works! (in the compiler)\n";
        static_cast<Derived*>(B)->someFunction();
        static_cast<Derived*>(B)->DoAction(); // seg fault
    };

    return 0;
}

// Answer
// Use dynamic_cast because you can do a run-time check to ensure that 
// we have a complete type here, 
// i.e. Are all the member functions that are to be used, available? (for the particular type)
//     if not, then don't do it. 

// Cost of run-time check: RTTI, vtables
// once you know something is safe to do, you can do it with static_cast.

// please don't do a regular cstyle cast.
 