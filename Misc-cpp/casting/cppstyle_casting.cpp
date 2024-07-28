/**
 * Avoid casting where possible, prefer dynamic_cast
 * if you must, so you can check at runtime the safety of the cast
 * unless ofcourse, you really need performance, then try to use static_cast.
 * 
 * Core Guidelines:
 * See: ES.49: If you must use a cast, use a named cast, why? More searchable, shows intent!.
 * 
 * See: C.146
 */

#include <iostream>

struct Base {
    int basedata{1};

    Base(){
        basedata = 11;
    }
    virtual void Do(){
        std::cout << "Base::Do()\t" << basedata << '\n';
    }
};

struct Derived: Base {
    int deriveddata{2};

    Derived(){
        deriveddata = 22;
    }
    virtual void Do() override {
        std::cout << "Derived::Do()\t" << deriveddata << '\n';
    }
};
 
struct Unrelated {
    int unrelateddata{2};

    Unrelated(){
        unrelateddata = 22;
    }
    void Do(){
        std::cout << "Unrelated::Do()\t" << unrelateddata << '\n';
    }
};

int main(){

    // Again, C-style casts are a little too liberal
    // this is was reinterpret_cast is doing anyway.
    //int* p = 0xFFFF1234; // you can override this error with -fpermissive (not recommended)
    int x;
    int*p = &x;
    // Cast to type big enough for pointer
    std::cout << (long)p << std::endl;

    // Here's a safer example of a cast using static_cast, of a type we absolutely know
    // that we can cast.
    float f {3.14f};
    int i = static_cast<int>(f);
    //int i = (int)f;  // bothersome, kinda looks like function pointer syntax
    std::cout << i << std::endl;

    // This scenario is allowed 
    // Note: We can use concrete classes with static_cast, but it doesn't really get us much.
    Derived der;
    Base base;

    der.Do();
    base.Do();
    // Treat 'der' as Base
    (static_cast<Base>(der)).Do();
    // Treating 'base' as derived not safe though. 
    // We need pointers for this (polymorphism)
//    (static_cast<Derived>(base)).Do();

    // Note: Allowable with pointers to do a static_cast, but no run-time checks to see if this 
    //       is something we *should* be able to do
    Base*    b1 = new Base;
    Derived* d1 =  new Derived;

    // If our classes are not polymorphic (i.e. concrete classes without vtable)
    // then we have some strange behaviour....
    // TODO: :) Make 'Do' virtual in Base and rerun
    static_cast<Derived*>(b1)->Do();  // This is actually NOT ALLOWED, but static_cast doesn't throw errors, or nullptr like dynamic_cast
    d1->Do();
    // Output: Derived::Do()   0   // we dont have any v_table information, so this is sort of allowed to happen but works wierd.
    //         Derived::Do()   22
    // Output: Base::Do()      11
    //         Derived::Do()   22

    // Typically we want a 'dynamic_cast'
    // This *only works* with pointer or reference types.
    // The types themselves must be polymorphic
    // i.e. have a 'vtable' (so you need 'virtual') in your class.
    Base*    b = new Base;
    Derived* d = new Derived;

    // Not valid -- good thing we tested!
    if(dynamic_cast<Derived*>(b)){
        std::cout << "Treating 'b' like Derived\n";
    }

    // Valid -- 'd' is a type of Base
    if(dynamic_cast<Base*>(d)){
        std::cout << "Treating 'd' like Base\n";

        // Regular function call
        d->Do();
        // Can call explicitely different member functions in hierarchy
        d->Base::Do();
        d->Derived::Do();

        // Specified Base Version (our cast)
        // That we could replace the above dynamic_cast with if we wanted to 'feel better' now that
        // we know it's a valid cast.
        // No run-time cost here.
        (static_cast<Base*>(d))->Base::Do();

        // 'd' is still a Derived object, so we call it's version of 'Derived::Do()' regardless of the cast.
        // static_cast does not effect the virtual call
        // however, even if we cast to Base, we follow rules for the 'type'
        (static_cast<Base*>(d))->Do();
        (dynamic_cast<Base*>(d))->Do();
        // think of it like, d is already a Base class. (maybe, i am not sure)
    }

    // Strange Scenario (Why use casts)
    // This is a little bit stranger scenario, We have a derived class, and it does 
    // the right sort of thing
    Derived* d_ptr = new Derived;
    static_cast<Base*>(d_ptr)->Do();

    // Again, C-Style casts are a little 'wild'
    // You really have to be sure of what you are doing.
    // You might actually want to do this when using a void* for instance, 
    // but generally, this style cast or reinterpret_cast is when the programmer really knows 
    // what they are doing above the compiler
    ((Unrelated*)(d))->Do();
    //static_cast<Unrelated*>(d)->Do();  // won't even compile
    reinterpret_cast<Unrelated*>(d)->Do();
    dynamic_cast<Unrelated*>(d)->Do(); // Seggsfault because dereferencing nullptr;

    return 0;
}

// static_cast
// primitive to primitive 
// Base --> Derived class

// dynamic_cast
// pointers and references
// returns nullptr upon failure.

/**
 * +-----------+        +-----------+
 * |   Base    | -----> |  Derived  |
 * +-----------+        +-----------+
 * |  v_table*----+
 * +-----------+  |
 *                +---> v_table to find the correct virtual funcitons to call
 * 
 * dynamic_cast<Derived*>(Base) uses -
 * 
 * 1. virtual tables
 * 2. RTTI 
 * 
 * to figure out wether is a valid conversion
 * 
 */