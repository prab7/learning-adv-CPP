#include <iostream> 
#include <string>

struct Entity {

   // Entity() : name{"nick"}, x{4.7}, y(5.9), collection{nullptr} {
    Entity() : name{"nick"}, x{6}, y(5.9), collection{nullptr} {      // both () {} are fine depending on narrowing preferences

    }
    std::string name;
    int x {4}; // parenthesis here would mean a function call, so only {} allowed
    int y {5}; // always use curly 
    int* collection {nullptr};
};

int main(){

    Entity e{};  // set all zero or use the defaults only;

    std::cout << e.name << '\n'; // ""
    std::cout << e.x << '\n';    // 0
    std::cout << e.y << '\n';    // 0
    std::cout << e.collection << '\n';  // nullptr

    return 0;
}

// precedence
// constructor init > inclass init > zero init

// in general we don't want to rely on compiler to initialize shit for us, make it explicit, in every case.
