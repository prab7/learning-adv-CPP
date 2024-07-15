// g++ -std=c++20 main.cpp -o prog && ./prog

// C++ Standard library
#include <iostream>

// Third-party library
#include <SDL2/SDL.h>

int main(int argc, char* argv[]){

    // Create a Window data type
    SDL_Window* window = nullptr;

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL couldn't be initialized: " << SDL_GetError() << std::endl;;
    } else {  
        std::cout << "SDL video system is ready to do\n";
    }

    // Request a window to be created for our platform
    // The parameters are for the title, x and y position,
    // and the width and height of the window
    window = SDL_CreateWindow(
        "C++ SDL2 Window",          // window title
        0,                          // initial x position
        2500,                          // initial y position
        640,                        // width, in pixels
        480,                        // hieght, in pixels   
        SDL_WINDOW_OPENGL            // flags
    );


    // Infinite loop for our application
    bool gameIsRunning = true;

    while(gameIsRunning){

        SDL_Event event;

        // Start our event loop here
        while(SDL_PollEvent(&event)){

            // Handle each specific event
            if(event.type == SDL_QUIT){
                gameIsRunning = false;
            }
            if(event.type == SDL_MOUSEMOTION){
                std::cout << "mouse has been moved\n";
            }
            if(event.type == SDL_KEYDOWN){
                std::cout << "some key was pressed\n";
                if(event.key.keysym.sym == SDLK_0){ // KEYCODE
                    std::cout << "0 was pressed\n";
                } else {
                    std::cout << "0 was not pressed\n";
                }
            }

            const Uint8* state = SDL_GetKeyboardState(NULL);
            if(state[SDL_SCANCODE_RIGHT]){  // SCANCODE
                std::cout << "right arrow key was pressed\n";
            }
        }
    }

// Event is a union type, essentially it just takes up the type of whatever it needs to handle
// Remember Difference between SCANCODE and KEYCODE

    SDL_Delay(1);   // Pause Execution for 3000 milliseconds

    // Close and destroy the window
    SDL_DestroyWindow(window);        // Reclaim memory, No destructors because C

    // Clean up
    SDL_Quit();

    return 0;
}

// Event loop (infinite)
// Event Queue 