#include <SDL2/SDL.h>
#include "./include/glad/glad.h"
//g++ -std=c++20 codesetup.cpp ./src/glad.c -I./include/ -o prog -lSDL2 -ldl && ./prog 
//#include <glad/glad.h> //but this is better
#include <iostream>
#include <vector>

const std::string gVertexShaderSource = 
"#version 410 core\n"
"in vec4 position;\n"
"void main()\n"
"{\n"
"    gl_Position = vec4(position.x, position.y, position.z, position.w);\n"
"}\n";

const std::string gFragmentShaderSource = 
"#version 410 core\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"    color = vec4(1.0f, 0.0f, 0.0f, 1.0f);\n"
"}\n";


int gScreenWidth = 640;
int gScreenHeight = 480;
SDL_Window* gGraphicsApplicationWindow = nullptr;
SDL_GLContext gOpenGLContext = nullptr;

bool gQuit = false;

// VAO
GLuint gVertexArrayObject = 0;
// VBO
GLuint gVertexBufferObject = 0;

// Program Object (for our shaders) 
GLuint gGraphicsPipelineShaderProgram = 0;


// Debugging 
void debugMessage(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
                  const GLchar *message, const void *userParam)
{
    // Print, log, whatever based on the enums and message
    std::string message_str(message, length);
    std::cout << message_str << '\n';
}

/*------------------------------Main------------------------------*/

void GetOpenGLVersionInfo(){
    std::cout << "Vendor           : " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Rendered         : " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "Version          : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "Shading Language : " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

void VertexSpecification(){

    // lives on the CPU
    const std::vector<GLfloat> vertexPosition{
        -0.8f, -0.8f, 0.0f,    // vertex 1
        0.8f, -0.8f, 0.0f,      // vertex 2
        0.0f, 0.8f, 0.0f,       // vertex 3
    };

    // We start setting things up
    // on the GPU 
    glGenVertexArrays(1, &gVertexArrayObject); // VAO
    glBindVertexArray(gVertexArrayObject);

    // Start generating our VBO
    glGenBuffers(1, &gVertexBufferObject);  
    glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject);
    glBufferData(
        GL_ARRAY_BUFFER,
        vertexPosition.size() * sizeof(GLfloat),
        vertexPosition.data(),
        GL_STATIC_DRAW
    );

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
        0,
        3,
        GL_FLOAT,
        GL_FALSE,
        0,
        (void*)0
    );

    glBindVertexArray(0);
    glDisableVertexAttribArray(0);
    
}

GLuint CompileShader(GLuint type, const std::string& source){

    GLuint shaderObject;

    if(type == GL_VERTEX_SHADER){
        shaderObject = glCreateShader(GL_VERTEX_SHADER);
    } else if(type == GL_FRAGMENT_SHADER){
        shaderObject = glCreateShader(GL_FRAGMENT_SHADER);
    }

    const char* src = source.c_str();
    glShaderSource(shaderObject, 1, &src, nullptr);
    glCompileShader(shaderObject);

    return shaderObject;
}

// vs = VertexShaderSource | fs = FragmentShaderSource
GLuint CreateShaderProgram(const std::string& VertexShaderSource, const std::string& FragmentShaderSource){

    GLuint programObject = glCreateProgram();

    GLuint myVertexShader   = CompileShader(GL_VERTEX_SHADER, VertexShaderSource);
    GLuint myFragmentShader = CompileShader(GL_FRAGMENT_SHADER, FragmentShaderSource);

    glAttachShader(programObject, myVertexShader);
    glAttachShader(programObject, myFragmentShader);
    glLinkProgram(programObject);

    // Validate our program
    glValidateProgram(programObject);
    // glDetachShader, glDeleteShader

    return programObject;

}

void CreateGraphicsPipeline(){

    const std::string& vs = gVertexShaderSource;
    const std::string& fs = gFragmentShaderSource;
    gGraphicsPipelineShaderProgram = CreateShaderProgram(gVertexShaderSource, gFragmentShaderSource);
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
                            "OpenGL Triangle",
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

    // Debugger 
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(debugMessage, NULL);

    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE);
}


/*---------------Main Loop---------------*/
void Input(){
    SDL_Event e;

    while(SDL_PollEvent(&e) != 0){
        if(e.type == SDL_QUIT){
            std::cout << "Goodbye!" << std::endl;
            gQuit = true;
        }
    }
}
 
void PreDraw(){

    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);    

    glViewport(0,0,gScreenWidth, gScreenHeight);
    glClearColor(0.f, 1.f, 1.f, 1.f);

    glClear(GL_DEPTH_BUFFER_BIT |  GL_COLOR_BUFFER_BIT);

    glUseProgram(gGraphicsPipelineShaderProgram);
}

void Draw(){

    glBindVertexArray(gVertexArrayObject);
    glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}
/*---------------Main Loop---------------*/


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

/*------------------------------Main------------------------------*/


int main(){

    InitializeProgram();

    // responsible for getting some vertex data on our GPU 
    VertexSpecification();

    // once we have our initial geometry, this will be responsible for 
    // creating a pipeline with a vertex and a fragment shader
    CreateGraphicsPipeline();

    // handle input
    MainLoop();

    SDL_Delay(1);
    CleanUp();

    return 0;
}