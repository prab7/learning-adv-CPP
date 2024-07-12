#include <iostream>
#include <string>

class udt {
    public:
        explicit udt(int); // good practice
    
    public:
        int m_var;
};

udt::udt(int i){
    m_var = i;

    std::cout << "m_var: " << m_var << std::endl;
}

int main(){

    udt u1 = 500 ; // implicit conversion

    udt u2{500.0f}; // initializing with constructors (list initialization)

    // Bro you'll have to watch the vid again to understand this.

    return 0;
}
