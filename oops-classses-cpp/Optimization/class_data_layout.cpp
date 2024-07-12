#include <iostream>
#include <string>

struct GameState {
    bool checkpoint;
    float score;
    short numberOfPlayers;
};
/**
 *  struct -> 12 bytes
 *  
 *  bool 1 byte + 3 bytes padding
 *  float 4 bytes
 *  short 2 bytes + 2 bytes padding
 * 
 */

struct GameStateOpt {
    double score; //float 
    short numberOfPlayers;
    bool checkpoint;
};
/**
 *  struct -> 8 bytes
 *  
 *  float 4 bytes
 *  short 2 bytes 
 *  bool 1 byte + 1 bytes padding
 * 
 */
struct GameStateOptPrac {
    double score;
    short numberOfPlayers;
    bool checkpoint;
    bool checkpoint;
    bool checkpoint;
    bool checkpoint;
    bool checkpoint;
}; // still 16 bytes mem

int main(){

    for(int i = 0; i < 1000; i++){
        GameState* gs = new GameState;
    }

    GameStateOpt gsop;

    std::cout << alignof(gsop) << std::endl;  // 4/8 largest type we have

    std::cout << sizeof(gsop) << std::endl;
    std::cout << sizeof(gsop.checkpoint) << std::endl;
    std::cout << sizeof(gsop.score) << std::endl;
    std::cout << sizeof(gsop.numberOfPlayers) << std::endl;

    return 0;
}