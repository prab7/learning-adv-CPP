#include <iostream>
#include <memory> // weak_ptr

class UDT{
    public:
        UDT(){ std::cout << "UDT Created" << std::endl;}
        ~UDT(){ std::cout << "UDT Destroyed" << std::endl;}
};

int main(){
    
    std::weak_ptr<UDT> ptr2;
    {
        std::shared_ptr<UDT> ptr1 = std::make_shared<UDT>();
        {
            ptr2 = ptr1;
            std::cout << "(inside scope) use count = " << ptr2.use_count() << std::endl;
        } 
        std::cout << "use count                = " << ptr1.use_count() << std::endl;
    }
    std::cout << "Is weak ptr (object that it points to) valid: " << ptr2.expired() <<  std::endl;
    std::cout << "We should see our destructor call before this " << std::endl;

    return 0;

    return 0;
}

/**
 * WEAK Pointer
 * - non-owning pointer
 * - does not incrase the reference count
 * - safer way to have "dangling pointers"
 * - break cycles
 * 
 * - used to break reference cycles formed by objects managed by std::
 */

/**
 * spr1 - > spr2 - > spr3 +
 *  ^    ref cycle        |
 *  +---------------------+
 * 
 * spr1 - > sp2 -> 
 * 
 * 
 * 
 */