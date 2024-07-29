//                     +flags+
//     g++      main.cpp -o prog 
// +executble+  +---arguments---+

/**
 * argc - count
 * argv - values as c-string
 */

#include <iostream>

int main(int argc, char* argv[], char* env[]){

    std::cout << "argc: " << argc << std::endl;
    if(argc < 2){
        std::cout << "Usage: ./prog some" << std::endl;
        exit(1);
    }

    for(int i = 0; i < argc; i++){
        std::cout << "[" << i << "] " << argv[i] << std::endl;
    }

    std::cout << "env : " << env << std::endl;

    int i = 0;
    while(true){
        std::cout << env[i++] << '\n';
        if(env[i] == nullptr){
            break;
        }
    }
    std::cout << "\n\n\n\n\n";


    // getenv
    std::cout << std::getenv("PATH") << std::endl;


    return 0;
}

// linux
// getopt
// argparse