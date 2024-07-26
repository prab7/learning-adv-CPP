/*
Compilation on Linux:
export runthis="g++ -std=c++20 *filename*.cpp ../Thirdparty/GLAD/src/*.c -I../Thirdparty/GLAD/include/ -I../Thirdparty/glm-master -o prog -lSDL2 -ldl"
$runthis
./prog
*/

// Third Party Libraries
#include <SDL2/SDL.h>
#include <glad/glad.h>

#define GLM_FORCE_SWIZZLE
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

// C++ Standard Template Library (STL)
#include <iostream>
#include <vector>
#include <string>
#include <fstream>


bool quit = false;
int ScreenWidth  = 640;
int ScreenHeight = 480;

SDL_Window* AppWindow = nullptr;
SDL_GLContext OpenGLContext = nullptr;

GLuint shader_pipeline_program = 0;

GLuint VAO = 0;
GLuint VBO = 0;

// Index Buffer Object (IBO)
// This is used to store the array of indices that we want to draw from,
// when we do indexed drawing 
GLuint IBO = 0;

// Shaders
// Here we setup 2 shaders, a vertex shader and a fragment shader.
// At a minimum, every Modern OpenGL program needs a vertex and a fragment shader

float g_uOffset = 0.0f;
float g_uOffsetti = 0.0f;
float g_uOffsetz = -0.8f;
float g_uRotate = 0.0f;
float g_uScale = 0.5f;

/*⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄ DEBUGG ⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄*/
void debugMessage(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
                  const GLchar *message, const void *userParam)
{
    std::string message_str(message, length);
    std::cout << message_str << '\n';
    exit(EXIT_FAILURE);
}

void GetOpenGLVersionInfo(){
    std::cout << "Vendor           : " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Rendered         : " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "Version          : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "Shading Language : " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ DEBUGG ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/


void Init(){

/*⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄ DEBUGG ⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄*/
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cerr << "SDL2 couldnt initialize video subsystem: "<< SDL_GetError() << std::endl;
        exit(1);
    }
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ DEBUGG ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/


    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 4);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 4);

    AppWindow = SDL_CreateWindow(
        "practice Quad",
        0, 0, 
        ScreenWidth, ScreenHeight,
        SDL_WINDOW_OPENGL 
    );

    OpenGLContext = SDL_GL_CreateContext(AppWindow);
    int loading = gladLoadGLLoader(SDL_GL_GetProcAddress); // this is necessary for some reason warna segfault aa jata hai
    

/*⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄ DEBUGG ⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄*/
    if(AppWindow == nullptr) {
        std::cout << "SDL_Window was not able to be created" << std::endl;
        exit(1);
    }
    
    if(OpenGLContext == nullptr){
        std::cout << "OpenGL context not available\n";
        exit(1);
    }

    if(!loading){
        std::cout << "glad was not initialized" << std::endl;
        exit(1);
    }

    GetOpenGLVersionInfo();

    // Debugger Setup
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(debugMessage, NULL);

    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE);
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ DEBUGG ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/


};

void VertexSpecification(){

    std::vector<GLfloat> vertexData{
        // 0 - Vertex
       -0.5f,-0.5f, 0.0f,       // Left vertex position
        0.0f, 1.0f, 0.0f,       // color-green
        // 1 - Vertex
        0.5f,-0.5f, 0.0f,       // Right vertex position
        0.0f, 0.0f, 1.0f,       // color-blue
        // 2 - Vertex
       -0.5f, 0.5f, 0.0f,       // Top left position
        1.0f, 0.0f, 0.0f,       // color-red
        // 3 - Vertex
        0.5f, 0.5f, 0.0f,       // Top right position
        1.0f, 0.0f, 1.0f,       // color-magenta
    };

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(
        GL_ARRAY_BUFFER,                          // Kind of buffer we are working with 
        vertexData.size() * sizeof(GLfloat),      // Size of data in bytes
        vertexData.data(),                         // pointer to raw data
        GL_STATIC_DRAW
    );


    const std::vector<GLuint> indexBufferData {2, 0, 1,  3, 2, 1};
    // Setup the Index Buffer Object (IBO i.e. EBO)
    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        indexBufferData.size() * sizeof(GLuint),
        indexBufferData.data(),
        GL_STATIC_DRAW
    );

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
        0, 3,
        GL_FLOAT,
        GL_FALSE,
        sizeof(GLfloat)*6, 
        (GLvoid*)0
    );

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(
        1, 3,
        GL_FLOAT,
        GL_FALSE,
        sizeof(GL_FLOAT)*6, // both valid
        (GLvoid*)(sizeof(GLfloat)*3)
    );

    glBindVertexArray(0);
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);


}

std::string LoadShaderSourceString(const std::string& filename){

    std::string result = "";
    std::string line = "";

    std::ifstream myFile(filename.c_str());

    if(myFile.is_open()){
        while(std::getline(myFile, line)){
            result += line + '\n';
        }
        myFile.close();
    }
    return result;
}


GLuint CompileShader(GLenum type, const std::string& source){
    
    GLuint shaderObject = 0;

    if(type == GL_VERTEX_SHADER){
        shaderObject = glCreateShader(GL_VERTEX_SHADER);
    } else if(type == GL_FRAGMENT_SHADER){
        shaderObject = glCreateShader(GL_FRAGMENT_SHADER);
    }

    const GLchar* src = source.c_str();
    glShaderSource(shaderObject, 1, &src, nullptr);
    glCompileShader(shaderObject);


/*⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄ DEBUGG ⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄*/
    int result;
    glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &result);

    if(result == GL_FALSE){
        int length;
        glGetShaderiv(shaderObject, GL_INFO_LOG_LENGTH, &length);
        char* errorMessages = new char[length]; // Could also use alloca here
        glGetShaderInfoLog(shaderObject, length, &length, errorMessages);

        if(type == GL_VERTEX_SHADER){
            std::cout << "ERROR: GL_VERTEX_SHADER compilation failed!\n" << errorMessages << '\n'; 
        } else if (type == GL_FRAGMENT_SHADER){
            std::cout << "ERROR: GL_FRAGMENT_SHADER compilation failed!\n" << errorMessages << '\n'; 
        }
        delete[] errorMessages;

        glDeleteShader(shaderObject);
        return 0;
    }
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ DEBUGG ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/


    return shaderObject;
}


/**
 * vs = Compiled VertexShader Object
 * fs = Compiled FragmentShader Object
 * 
 * @param vss VertexShaderSourceCode
 * @param fss FragmentShaderSourceCode
 * @return programObject
 */
GLuint CreateShaderProgram(const std::string& vss, const std::string& fss){

    GLuint programObject = glCreateProgram();

    GLuint vsobj = CompileShader(GL_VERTEX_SHADER, vss);
    GLuint fsobj = CompileShader(GL_FRAGMENT_SHADER, fss);

    glAttachShader(programObject, vsobj);
    glAttachShader(programObject, fsobj);
    glLinkProgram(programObject);

    glValidateProgram(programObject);

    glDetachShader(programObject, vsobj);
    glDetachShader(programObject, fsobj);

    glDeleteShader(vsobj);
    glDeleteShader(fsobj);

    return programObject;
}

void GenGrapicsPipeline(){
    const std::string& vss = LoadShaderSourceString("../Shaders/vertT.glsl");
    const std::string& fss = LoadShaderSourceString("../Shaders/fragT.glsl");
    shader_pipeline_program = CreateShaderProgram(vss, fss);
}

/*-----------------------------------------------------------------*/
void Input(){

    SDL_Event event;

    while(SDL_PollEvent(&event) != 0){

        if(event.type == SDL_QUIT){
            std::cout << "Goodbye!\n";
            quit = true;
        }
    }

    // Retrieve keybord state
    const Uint8 *state = SDL_GetKeyboardState(NULL);

    if (state[SDL_SCANCODE_UP] and state[SDL_SCANCODE_LSHIFT]){
        g_uOffsetz += 0.01f;
        std::cout << "g_uOffsetz: " << g_uOffsetz << std::endl;
    } 
    else if (state[SDL_SCANCODE_UP] or state[SDL_SCANCODE_W]){
        g_uOffset += 0.01f;
        std::cout << "g_uOffset: " << g_uOffset << std::endl;
    }

    if (state[SDL_SCANCODE_DOWN] and state[SDL_SCANCODE_LSHIFT]){
        g_uOffsetz -= 0.01f;
        std::cout << "g_uOffsetz: " << g_uOffsetz << std::endl;
    }
    else if (state[SDL_SCANCODE_DOWN] or state[SDL_SCANCODE_S]){
        g_uOffset -= 0.01f;
        std::cout << "g_uOffset: " << g_uOffset << std::endl;
    }


    if (state[SDL_SCANCODE_RIGHT] and state[SDL_SCANCODE_LALT]){
        g_uRotate += 2.0f;
        std::cout << "g_uRotate: " << g_uRotate << std::endl;
    }
    else if (state[SDL_SCANCODE_RIGHT] or state[SDL_SCANCODE_D]){
        g_uOffsetti += 0.01f;
        std::cout << "g_uOffsetti: " << g_uOffsetti << std::endl;
    }

    if (state[SDL_SCANCODE_LEFT] and state[SDL_SCANCODE_LALT]){
        g_uRotate -= 2.0f;
        std::cout << "g_uRotate: " << g_uRotate << std::endl;
    }
    else if (state[SDL_SCANCODE_LEFT] or state[SDL_SCANCODE_A]){
        g_uOffsetti -= 0.01f;
        std::cout << "g_uOffsetti: " << g_uOffsetti << std::endl;
    }
}



void PreDraw(){

    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);

    glViewport(0, 0, ScreenWidth, ScreenHeight);
    glClearColor(1.f,1.f,1.f,1.f);

    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    // Use our Shader 
    glUseProgram(shader_pipeline_program);


    
    // Model tranformation by translating our object into world space 
    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(g_uOffsetti, g_uOffset, g_uOffsetz));

    // rotation
              model = glm::rotate(model, glm::radians(g_uRotate), glm::vec3(0.0f, 1.0f, 0.0f));
    // scaling
              model = glm::scale(model, glm::vec3(g_uScale, g_uScale, g_uScale));

    // Retrieve our location of our Model Matrix
    GLint u_ModelMatrixlocation = glGetUniformLocation(shader_pipeline_program, "u_ModelMatrix");

    if(u_ModelMatrixlocation >= 0){
        glUniformMatrix4fv(u_ModelMatrixlocation, 1, GL_FALSE, &model[0][0]); 
    } else {
        std::cout << "Could not find u_ModelMatrix, maybe a mispelling?\n" << std::endl;
        exit(EXIT_FAILURE);
    }



    // Projection matrix (in perspective)
    glm::mat4 perspective = glm::perspective(
        glm::radians(45.0f),
        (float)ScreenWidth/(float)ScreenHeight,
        0.01f,
        100.f
    );

    // Retrieve our location of our Perpective Matrix
    GLint u_Perspectivelocation = glGetUniformLocation(shader_pipeline_program, "u_Perspective");

    if(u_Perspectivelocation >= 0){
        glUniformMatrix4fv(u_Perspectivelocation, 1, GL_FALSE, &perspective[0][0]); 
    } else {
        std::cout << "Could not find u_Perspective, maybe a mispelling?\n" << std::endl;
        exit(EXIT_FAILURE);
    }


}; 

void Draw(){
 
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    //glDrawArrays(GL_TRIANGLES, 0, 6);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    
    glUseProgram(0);

};
/*-------------------------------------------------------------------*/

void MainLoop(){

    while(!quit){
        
        Input();

        PreDraw();

        Draw();

        SDL_GL_SwapWindow(AppWindow);
    }
};

void CleanUp(){

    SDL_Delay(1);

    SDL_DestroyWindow(AppWindow);
    AppWindow = nullptr;

    glDeleteBuffers(1, &VBO);
    glDeleteVertexArrays(1, &VAO);

    glDeleteProgram(shader_pipeline_program);

    SDL_Quit();
};



int main(int argc, char* argv[]){

    Init();

    VertexSpecification();

    GenGrapicsPipeline();

    MainLoop();

    CleanUp();

    return 0;
}