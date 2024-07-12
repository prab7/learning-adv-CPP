#include <iostream> 
#include <string>

struct Entity {
    /*
    Entity() : name{}, x{0}, y(0), collection{nullptr} {
        name = std::to_string(x) + std::to_string(y);
        // Compute some algorithm
        // Add our entity to some data structure
    }

    Entity(std::string _name) : name(_name), x{0}, y(0), collection{nullptr}{
        
        // Compute some algorithm
        // Add our entity to some data structure
    }*/


    Entity() : name{}, x{0}, y(0), collection{nullptr} {
        name = std::to_string(x) + std::to_string(y);
        // Compute some algorithm
        // Add our entity to some data structure
    }

    Entity(std::string _name) : Entity::Entity() {  // delegate constructor
        name = _name;
    }

    // a delegating constructor cannot have other mem-initializers
    //Entity(int _x, int _y) : Entity::Entity(), name("test") {
    Entity(int _x, int _y) : Entity::Entity() {
        x = _x;
        y = _y;
    }


    std::string name;
    int x {0}; 
    int y {0}; 
    int* collection {nullptr};


private:
    /*
    void init(){
        name = std::to_string(x) + std::to_string(y);
        // Compute some algorithm
        // Add our entity to some data structure
    }
    */

};

int main(){

    Entity e("nick");
    Entity e2(9, 7);

    std::cout << e.name << '\n'; 
    std::cout << e2.x << '\n';    
    std::cout << e2.y << '\n';    
    std::cout << e.collection << '\n';

    return 0;
}

// The pragmatic programmer