#include <iostream>

class Base {
    public:
        Base() {
            std::cout << "Base Constructor" << std::endl;
        }
        virtual ~Base(){
            std::cout << "Base Destructor"  << std::endl;
        }
        virtual void MemberFunc(){
            std::cout << "Base::MemberFunc()\n";
        }
};

class Derived : public Base {
    public:
        Derived() {
            std::cout << "Derived Constructor" << std::endl;
        }
        ~Derived(){
            std::cout << "Derived Destructor"  << std::endl;
        }
        void MemberFunc() override {
            std::cout << "Derived::MemberFunc()\n";
        }
};

void swap(int& x, int& y){
    x = x^y;
    y = y^x;
    x = x^y;
}

int main(){

    // Create a Base pointer that can point to 'Base' or 'Derived', i.e. anything that 'is-a'
    // We also have a vtable that is created for this instance of the object
    Base* instance = new Derived;
    // When we call a member function, the vtable points us to the correct
    // MemberFunction()
    instance->MemberFunc(); // runtime polymorphism
    delete instance;

    instance = new Base;
    instance-> MemberFunc();
    delete instance;


    // fun
    int a = 10;
    int b = 20;
    swap(a, b);
    std::cout << a << " " << b << std::endl;

    return 0;
}

  // Virtual tables - supports dynamic dispatch
/**
 * +--------------+
 * |    Base      |
 * +--------------+
 * |  Base()      |
 * | ~Base()      |             __vtable
 * | MemberFunc() | v        +---------------+
 * | __vptr*----|--------> |     Base      |
 * +--------------+          +---------------+   
 *                           | MemberFunc()  |
 * +--------------+          +---------------+
 * |   Derived    |
 * +--------------+
 * |  Derived     |
 * | ~Derived     |             __vptr
 * | MemberFunc() |<---+     +---------------+
 * | __vptr*----|----+---> |   Derived     |
 * +--------------+    |     +---------------+
 *                     +-----|-MemberFunc()  |
 *                           +---------------+
 *    
 * - __vptr* is a pointer to a table 
 * - vtables are static
 * - all objects point to the same vtable
 */