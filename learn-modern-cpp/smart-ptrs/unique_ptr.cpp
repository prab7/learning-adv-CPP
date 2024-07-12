#include <iostream>
#include <memory>

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
 
    //RAII scoped
    std::unique_ptr<UDT> mike = std::unique_ptr<UDT>(new UDT);

    std::unique_ptr<UDT[]> mike_arr = std::unique_ptr<UDT[]>(new UDT[10]);

    // Equivalent syntax
    std::unique_ptr<UDT[]> mike_arr2 = std::make_unique<UDT[]>(10); // factory pattern
    // std::unique_ptr<UDT> joe  = mike;  // this class is not copy constructable
    // We are allowed to std::move

    std::unique_ptr<UDT> joe = std::move(mike); //transers ownership

    //delete mike; //error: type ‘class std::unique_ptr<UDT>’ argument given to ‘delete’, expected pointer

    return 0;
}

/**
 * UNIQUE PTR 
 * 
 * - We cannot share, (no copies allowed)
 * - We don't hace to delete (deletes within the scope [block scope])
 */

