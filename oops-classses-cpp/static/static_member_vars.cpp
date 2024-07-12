#include <iostream>

struct API{
    API(){
    }
    ~API(){
    }

    // Declarations
    static int MAJOR;
    const static int MINOR = 9; // please research more about this, it's not visible in objdump
    const static int MIDDL;
};

// Definitions
int API::MAJOR = 7;
const int API::MIDDL = 7;

// only when I define outside the class do I see them in the objdum table

// scope is within the API class
// but the variables are OUTSIDE the class (in memory)

// CANNOT leave static variable uninitialized, => linker error

int main(){

    API instance;
    instance.MAJOR += 7; // linker error (if line 13 not there)

    std::cout << "Major     : " << API::MAJOR << '\n';
    std::cout << "Minor     : " << API::MINOR << '\n';
    std::cout << "Middl     : " << API::MIDDL << '\n';
    std::cout << "API size  : " << sizeof(API)<< '\n';
    std::cout << "Major size: " << sizeof(API::MAJOR)<< '\n';
    std::cout << "Minor size: " << sizeof(API::MINOR)<< '\n';
    std::cout << "Middl size: " << sizeof(API::MIDDL)<< '\n';

    return 0;
}

// static persists forever, lifetime infinite, single initialization only
// it's allocated in the binary, there's always room for that variable

// static global variables limit the scope of that variable to that particular file, but it's again always persisted

/*
This is a linker error:

/usr/bin/ld: /tmp/cceNpJXW.o: warning: relocation against `_ZN3API5MAJORE' in read-only section `.text'
/usr/bin/ld: /tmp/cceNpJXW.o: in function `main':
/home/prab/documents/open-gl/oops-classses-cpp/static/static_member.cpp:16: undefined reference to `API::MAJOR'
/usr/bin/ld: warning: creating DT_TEXTREL in a PIE
collect2: error: ld returned 1 exit status
*/

/*

+-------------+
|             |
|     API     |
|    class    |--+--> API::MAJOR
|  Blueprint  |  +--> API::MINOR  // live outside the class, scoped within the class itself.
|             |
+-------------+


*/
