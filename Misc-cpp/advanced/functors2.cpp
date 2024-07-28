#include <iostream>
#include <vector>
#include <algorithm>

struct Goblin {
    int _health;
    int _strength;
    Goblin(int h, int s) : _health(h), _strength(s){} 

    bool operator<(const Goblin& rhs){
        return this->_health < rhs._health;
    }
};

// Functor
struct GoblinComperator {
    bool operator()(const Goblin& lhs, const Goblin& rhs) const{
        return lhs._strength < rhs._strength;
    }
};

int main(){

    std::vector<Goblin> goblins { Goblin(5,205),
                                  Goblin(3,25),
                                  Goblin(100,1) };

    // we want to sort based on 2 attributes.
    std::sort(begin(goblins), end(goblins), GoblinComperator());

    for(auto g: goblins){
        std::cout << g._health << std::endl;
    }

    return 0;
}
