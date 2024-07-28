#include <iostream>
#include <cstring>

struct GameState {
    int level;
    int health;
    int points;
    bool GameComplete;
    bool BossDefeated;
};
// this has 2 bytes of padding below.


int main(){

    // Example 1 start

    float pi=3.14f;

    // C-Style cast
    // ---- Might get some errors, but otherwise you can cast somewhat freely
    //      this is going through a hierarchy static -> dynamic -> const -> reinterpret
    std::cout << (int)(pi) << std::endl;
    // reinterpret_cast literally interprets the bytes as whatever type
    // that you decide to treat the raw bytes
    std::cout << *reinterpret_cast<int*>(&pi) << std::endl; 
    std::cout << *reinterpret_cast<float*>(&pi) << std::endl; 

    // Example 2

    // Load some game state
    GameState gs = {66, 100, 99, false, false};

    // Allocate some memory
    char bagOfbytes[sizeof(GameState)];

    // Let's just store some ata structure into 'bag of bytes'
    std::memcpy(bagOfbytes, &gs, sizeof(GameState));
    // this is ugly, this is Ass.
    std::cout << *((int*)bagOfbytes) << std::endl;

    // This is beuatiful! (sort of)
    std::cout << *reinterpret_cast<int*>(bagOfbytes)                                 << std::endl;
    std::cout << *reinterpret_cast<int*>(bagOfbytes + sizeof(int))                   << std::endl;
    std::cout << *reinterpret_cast<int*>(bagOfbytes + sizeof(int)*2)                 << std::endl;
    std::cout << *reinterpret_cast<bool*>(bagOfbytes + sizeof(int)*3)                << std::endl;
    std::cout << *reinterpret_cast<bool*>(bagOfbytes + sizeof(int)*3 + sizeof(bool)) << std::endl;

    return 0;
}