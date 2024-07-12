#include <iostream> 
#include <string>

struct Entity {
    //Entity() = default;
    Entity() : name("nick"), x(0), y(0), collection(nullptr){
    }

    std::string name;
    int* collection;
    int x;
    int y;
};

struct vec3 {
    float x, y, z;
};

int main(){

    Entity e{}; // This zero initializes every member variable string is ""

    std::cout << e.name << '\n';  // ""
    std::cout << e.collection << '\n';  // nullptr
    std::cout << e.x << '\n';   // 0
    std::cout << e.y << '\n' << std::endl;;   // 0

    vec3 v{};

    std::cout << v.x << '\n';   // 0
    std::cout << v.y << '\n';   // 0
    std::cout << v.z << '\n';   // 0


    return 0;
}