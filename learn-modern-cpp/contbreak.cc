#include <iostream>

int main(){

    for(int j = 0; j < 10; j++){
        continue;
        for(int i = 0; i < 10; i++){
            std::cout << "start of loop" << std::endl;
            break;
            std::cout << "i is :" << i << std::endl;
            continue;
        }
        std::cout << "j is :" << j << std::endl;
    }

    return 0;
}