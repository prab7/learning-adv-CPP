#include <iostream>
#include <SDL2/SDL.h>

int gScreenHeight = 640;
int gScreenWidth = 480;
SDL_Window* gGraphicsApplicationWindow = nullptr;
SDL_GLContext gOpenGLContext = nullptr;

bool gQuit = false;

int main(int argc, char* argv[]){

    gGraphicsApplicationWindow =  SDL_CreateWindow(
                            "OpenGL Window",
                            0, 0,
                            640, 480,
                            SDL_WINDOW_OPENGL
                        );
    while(!gQuit){

        SDL_Event event;

        // Start our event loop here
        while(SDL_PollEvent(&event)){

            // Handle each specific event
            if(event.type == SDL_QUIT){
                gQuit = true;
            }
        }
    }

    SDL_DestroyWindow(gGraphicsApplicationWindow);

    SDL_Quit();

}