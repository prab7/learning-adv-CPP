/**
 * Vertex Specification -> Vertex Shader -> Rasterization -> Fragment Shader
 * 
 * Compilation on Linux 
 * g++ -std=c++20 -g *filename*.cpp -I./include/ ./src/glad.c -lSDL2 -ldl -o prog
 */
#include <SDL2/SDL.h>
#include "./include/glad/glad.h" // #include <glad/glad.h>, but doesnt give me intellisense on vscode

#include <iostream>
#include <vector>
#include <string>
#include <fstream>


int ScreenWidth  = 640;
int ScreenHeight = 480;

SDL_Window* AppWindow = nullptr;
SDL_GLContext OpenGLContext = nullptr;

GLuint shader_pipeline_program = 0;

GLuint VAO = 0;
GLuint VBO = 0;

bool quit = false;



/*⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄ DEBUGG ⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄⌄*/
void debugMessage(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
                  const GLchar *message, const void *userParam)
{
    std::string message_str(message, length);
    std::cout << message_str << '\n';
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
        "practice triangle",
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
       -0.8f,-0.8f, 0.0f,       // Left vertex position
        1.0f, 0.0f, 0.0f,       // color
        0.8f,-0.8f, 0.0f,       // Rightvertex position
        0.0f, 1.0f, 0.0f,       // color
        0.0f, 0.8f, 0.0f,       // Top vertex position
        0.0f, 0.0f, 1.0f,       // color
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
    const std::string& vss = LoadShaderSourceString("./Shaders/vert3.glsl");
    const std::string& fss = LoadShaderSourceString("./Shaders/frag3.glsl");
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
}
void PreDraw(){

    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);

    glViewport(0, 0, ScreenWidth, ScreenHeight);
    glClearColor(1.f,1.f,1.f,1.f);

    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    glUseProgram(shader_pipeline_program);
};

void Draw(){

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    
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