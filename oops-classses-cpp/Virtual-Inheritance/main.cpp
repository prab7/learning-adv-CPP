#include <iostream>

struct Entity {
    int x {4}, y {5};
};
struct Warrior : virtual public Entity {
    int power {10};
};
struct Goblin : virtual public Entity {
    int power{7};
};
//struct Player : virtual public Goblin, virtual  public Warrior { // redundant
struct Player : public Goblin,  public Warrior { 
};

int main(){

    Player mike;
    std::cout << mike.x << std::endl;  // works with virtual inheritance
    std::cout << mike.y << std::endl;  // works with virtual inheritance

    std::cout << mike.Warrior::x << std::endl;
    std::cout << mike.Warrior::y << std::endl;

    std::cout << mike.Goblin::x << std::endl;
    std::cout << mike.Goblin::y << std::endl;

    std::cout << mike.Warrior::power << std::endl;
    std::cout << mike.Goblin::power << std::endl;

    // std::cout << mike.power << std::endl;


    return 0;
}

//   Inheritance

// Entity    Entity
//   |         |
// Warrior   Goblin
//   +----+----+
//        |
//     Player




// Virtual Inheritance 

/**
 *        Entity 
 *          +
 *    +-----+-----+
 * Warrior     Goblin
 *    +-----+-----+
 *        Player
 */