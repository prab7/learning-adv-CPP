#include <SDL2/SDL.h>
#include "./include/glad/glad.h" // this gets be intellisense, just include -I./include/ for glad to work

//g++ -std=c++20 codesetup.cpp ./src/glad.c -I./include/ -o prog -lSDL2 -ldl && ./prog 
//#include <glad/glad.h> //but this is better

#include <iostream>

// Globals
int gScreenWidth = 640;
int gScreenHeight = 480;
SDL_Window* gGraphicsApplicationWindow = nullptr;
SDL_GLContext gOpenGLContext = nullptr;

bool gQuit = false; // if true we quit


void GetOpenGLVersionInfo(){
    std::cout << "Vendor          : " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Rendered        : " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "Version         : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "Shading Language: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

void InitializeProgram(void){

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cerr << "SDL2 couldnt initialize video subsystem: "<< SDL_GetError() << std::endl;
        exit(1);
    }
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 4);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 4);

    gGraphicsApplicationWindow =  SDL_CreateWindow(
                            "OpenGL Window",
                            0, 0,
                            gScreenWidth, gScreenHeight,
                            SDL_WINDOW_OPENGL
                        );
    

    if(gGraphicsApplicationWindow == nullptr) {
        std::cout << "SDL_Window was not able to be created" << std::endl;
        exit(1);
    }

    gOpenGLContext = SDL_GL_CreateContext(gGraphicsApplicationWindow);

    if(gOpenGLContext == nullptr){
        std::cout << "OpenGL context not available\n";
    }

    // initialize the glad library
    if(!gladLoadGLLoader(SDL_GL_GetProcAddress)){
        std::cout << "glad was not initialized" << std::endl;
        exit(1);
    }

    GetOpenGLVersionInfo();
}


void Input(){
    SDL_Event e;

    while(SDL_PollEvent(&e) != 0){
        if(e.type == SDL_QUIT){
            std::cout << "Goodbye" << std::endl;
            gQuit = true;
        }
    }
}
 
void PreDraw(){

}

void Draw(){

}


void MainLoop(void){
    
    while(!gQuit){

        Input();

        PreDraw();

        Draw();

        // Update the screen
        SDL_GL_SwapWindow(gGraphicsApplicationWindow);
    }
}



void CleanUp(void){
    SDL_DestroyWindow(gGraphicsApplicationWindow);
    SDL_Quit();
}



int main(){

    InitializeProgram();

    MainLoop();

    SDL_Delay(1);
    CleanUp();

    return 0;
}