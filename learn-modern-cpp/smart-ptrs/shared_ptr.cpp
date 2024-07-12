#include <iostream>
#include <memory> // shared ptr

class UDT{
    public:
        // Constructor (called on creation)
        UDT(){
            std::cout << "UDT Created" << std::endl;
        }
        // Destructor (called on destruction)
        ~UDT(){
            std::cout << "UDT Destroyed" << std::endl;
        }
};

int main(){
    {
        // Creating our shared pointer
        std::shared_ptr<UDT> ptr1 = std::make_shared<UDT>();
        {
            // Then in a new scope, I share the resource 
            std::shared_ptr<UDT> ptr2 = ptr1;
            // Our reference count is updated 
            std::cout << "use count = " << ptr2.use_count() << std::endl;
        } // Then ptr2 is freed

        // Then we chack our updated reference count
        std::cout << "use count = " << ptr1.use_count() << std::endl;
        //std::cout << "use count = " << ptr2.use_count() << std::endl;
    }
    std::cout << "We should see our destructor call before this" << std::endl;

    return 0;
}

// shared_ptr helps use avoid calling new/delete

/**
 * 2 shared pointers can have different lifetimes
 * 
 *  ptr1 ---+   +----------+
 *    |     +-->| RESOURCE |
 *  ptr2----+   +----------+
 *    |
 *    |     +-------------+
 *    +---->|control block| = 2 (reference count)
 *          +-------------+
 * 
 *                     Resource is destroyed here
 * ptr1------>         |
 *      ptr2---------->|
 * --------------------------->
 * Timeline 
 */

/**
 * - reference count is thread-safe
 * 
 */


