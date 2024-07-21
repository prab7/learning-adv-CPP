/*
Compilation on Linux:
> export run=="g++ -std=c++20 codesetup.cpp ./../Thirdparty/GLAD/src/*.c -I./../Thirdparty/GLAD/include/ -I./../Thirdparty/glm-master -o prog -lSDL2 -ldl"
> $runthis 
> ./prog
*/

// Third Party Libraries
#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

// C++ Standard Template Library (STL)
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

// vvvvvvvvvvvvvvvvvvvvvvvvv Globals vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

// Screen Dimensions
int gScreenWidth = 640;
int gScreenHeight = 480;
SDL_Window* gGraphicsApplicationWindow = nullptr;
SDL_GLContext gOpenGLContext = nullptr;

// MainLoop flag
bool gQuit = false; // If this is 'true', the program terminates

// shader
// The following stores the unique id for the graphics pipeline 
// program Object be used for our OpenGL draw calls
GLuint gGraphicsPipelineShaderProgram = 0;

// OpenGL Objects
// Vertex Array Object (VAO)
// Vertex Array Object encapsulate all the of items needed to render an object
// For example, we may have multiple vertex buffer objects (VBO) related to rendering one object.
// The VAO allows us to setup the OpenGL state to render that object using the correct layout 
// and correct buffers with one call after being setup.
GLuint gVertexArrayObject = 0;

// Vertex Buffer Object (VBO)
// Vertex Buffer Objects store information relating to vertices (e.g. positions, normals, textures)
// VBOs are our mechanism for arranging geometry on the GPU
GLuint gVertexBufferObject = 0;

// Index Buffer Object (IBO)
// This is used to store the array of indices that we want to draw from,
// when we do indexed drawing 
GLuint gIndexBufferObject = 0;

// ^^^^^^^^^^^^^^^^^^^^^^^^^ Globals ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^



// Debugging 
void debugMessage(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
                  const GLchar *message, const void *userParam)
{
    // Print, log, whatever based on the enums and message
    std::string message_str(message, length);
    std::cout << message_str << '\n';
}


std::string LoadShaderAsString(const std::string& filename){
    // Resulting Shader program loaded as a single string here.
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
};



/**
 * CompilerShader will compile any valid vertex, fragment, geometry, tesselation, or compute shader.
 * e.g.
 *      Compile a vertex shader   : CompileShader(GL_VERTEX_SHADER, VertexShaderSource);
 *      Compile a fragment shader : CompileShader(GL_FRAGMENT_SHADER, FragmentShaderSource);
 * 
 * @param type We use the 'type' field to determine which shader we are going to compile.
 * @param source : The shader source code.
 * @return id of the shader object
 */
GLuint CompileShader(GLuint type, const std::string& source){

    // Compile our shaders
    GLuint shaderObject;

    // Based on the type passed in, we create a shader object specifically for that type
    if(type == GL_VERTEX_SHADER){
        shaderObject = glCreateShader(GL_VERTEX_SHADER);
    } else if(type == GL_FRAGMENT_SHADER){
        shaderObject = glCreateShader(GL_FRAGMENT_SHADER);
    }

    const char* src = source.c_str();
    // The source of our shader
    glShaderSource(shaderObject, 1, &src, nullptr);

    // Now compile our shader
    glCompileShader(shaderObject);

    // Retrieve the result of our compilation
    int result;

    // Our goal with glGetShaderiv is to retrieve the compilation status
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
        // Reclaim our memory
        delete[] errorMessages;
        
        // Delete our broken shader
        glDeleteShader(shaderObject);

        return 0;
    }
    return shaderObject;
}

/**
 * Creates a graphics program object (i.e. graphics pipeline) with a Vertex Shader and a Fragment Shader,
 * 
 * vs = VertexShaderSource | fs = FragmentShaderSource
 * 
 * @param VertexShaderSource Vertex Shader source code as a string
 * @param FragmentShaderSource Fragment Shader source code as a string
 * @return id of the program Object
 */
GLuint CreateShaderProgram(const std::string& VertexShaderSource, const std::string& FragmentShaderSource){

    // Create a new program object
    GLuint programObject = glCreateProgram();

    // Compile our shaders
    GLuint myVertexShader   = CompileShader(GL_VERTEX_SHADER, VertexShaderSource);
    GLuint myFragmentShader = CompileShader(GL_FRAGMENT_SHADER, FragmentShaderSource);

    // Link our two shader programs together.
    // Consider this the equivalent of taking two .cpp files, and linking them into one executable file.
    glAttachShader(programObject, myVertexShader);
    glAttachShader(programObject, myFragmentShader);
    glLinkProgram(programObject);

    // Validate our program
    glValidateProgram(programObject);
    
    // Once our final program Object has been created, we can
    // Detach and then Delete our individual shaders.
    glDetachShader(programObject, myVertexShader);
    glDetachShader(programObject, myFragmentShader);

    // Delete the individual shaders once we are done 
    glDeleteShader(myVertexShader);
    glDeleteShader(myFragmentShader);

    return programObject;

}

/**
 * Create graphics pipeline
 * 
 * @return void
 */
void CreateGraphicsPipeline(){

    const std::string& vs = LoadShaderAsString("../Shaders/vert3.glsl");
    const std::string& fs = LoadShaderAsString("../Shaders/frag3.glsl");
    gGraphicsPipelineShaderProgram = CreateShaderProgram(vs, fs);
}

/*------------------------------Main------------------------------*/

/**
 * Helper function to get OpenGL Version Information
 * 
 * @return void
 */
void GetOpenGLVersionInfo(){
    std::cout << "Vendor           : " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Rendered         : " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "Version          : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "Shading Language : " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

/**
 * Setup your geometry during the vertex specification step
 * 
 * @return void 
 */
void VertexSpecification(){

    // Geometry Data
    // Here we are going to store x, y, and z position attributes
    // along with color attributes within vertexData for the data
    // For now, this information is just stored in the CPU, and we are going to store this data on the GPU shortly,
    // in a call to gBuggerData which will store this information into a vertex buffer object VBO
    // Note: That I have segregated the data from the OpenGL calls which follow in this function.
    //      It is not strictly necessary, but I find the code is cleaner if OpenGL (GPU) related 
    //      functions are packed closer together versus CPU operations.  
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

    // Vertex Arrays Object (VAO) Setup
    // Note: We can think of the VAO as a 'wrapper around' all of the Vertex Buffer Objects,
    //      in the sense that it encapsulates all the VBO state that we are setting up.
    //      Thus, it is also important that we glBindVertexArray (i.e. select the VAO we want to use)
    //      before our vertex buffer object operations.
    glGenVertexArrays(1, &gVertexArrayObject);

    // We bind (i.e. select) to the Vertex Arrays Object (VAO) that we want to work within.
    glBindVertexArray(gVertexArrayObject);


    // Vertex Buffer Object (VBO) Creation
    // Create a new vertex buffer object
    // Note: We'll see this pattern of code often in OpenGL of creating and binding to a buffer
    glGenBuffers(1, &gVertexBufferObject);  

    // Next we will do glBindBuffer.
    // Bind is equivalent to 'selecting the active buffer object' that we want to woth with in OpenGL.
    glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject);

    // Now, in our currently binded buffer, we populate the data from our 'vertexData' (which is in CPU)
    // onto a buffer that will live on the GPU.
    glBufferData(
        GL_ARRAY_BUFFER,                                // Kind of buffer we are working with (e.g GL_ARRAY_BUFFER or GL_ELEMENT_ARRAY_BUFFER)
        vertexData.size() * sizeof(GLfloat),        // Size of data in bytes
        vertexData.data(),                          // Raw array of data (pointer to data)
        GL_STATIC_DRAW                                  // How we intend to use the data 
    );

    const std::vector<GLuint> indexBufferData {2, 0, 1,  3, 2, 1};
    // Setup the Index Buffer Object (IBO i.e. EBO)
    glGenBuffers(1, &gIndexBufferObject);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gIndexBufferObject);

    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        indexBufferData.size() * sizeof(GLuint),
        indexBufferData.data(),
        GL_STATIC_DRAW
    );

    // For our Given Vertex Array Object, we need to tell OpenGL 
    // 'how' the information in our buffer will be used.
    glEnableVertexAttribArray(0);

    // For the specific attribute in our vertex specification, we use 
    // 'glVertexAttribPointer' to figure out how we are going to move through the data.
    glVertexAttribPointer(
        0,                                              /* Attribute 0 corrosponds to the enabled glEnableVertexAttribArray  
                                                         In the future, you'll see in our vertex shader this also corrospond 
                                                         to (layout=0) which selects these attributes. */    
        3,                                              // The number of components (e.g. x, y, z = 3 components)
        GL_FLOAT,                                       // Type 
        GL_FALSE,                                       // Is the data normalized 
        sizeof(GL_FLOAT)*6,                                              // Stride 
        (GLvoid*)0                                        // Offset
    );

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(
        1,                                              /* Attribute 0 corrosponds to the enabled glEnableVertexAttribArray  
                                                         In the future, you'll see in our vertex shader this also corrospond 
                                                         to (layout=0) which selects these attributes. */    
        3,                                              // The number of components (e.g. x, y, z = 3 components)
        GL_FLOAT,                                       // Type 
        GL_FALSE,                                       // Is the data normalized 
        sizeof(GL_FLOAT)*6,                                              // Stride 
        (GLvoid*)(sizeof(GL_FLOAT)*3)                              // Offset
    );



    // Unbind our currently bound Vertex Arrays Object
    glBindVertexArray(0);

    // Disable any Attributes we opened in our Vertex Attribute Array,
    // as we do not want to leave them open.
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    
}

/**
 * Initialization of the graphics application. Typically this will involve setting up a window
 * and the OpenGL Context (with the appropriate version)
 * 
 * @return void
 */
void InitializeProgram(void){
    // Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cerr << "SDL2 couldnt initialize video subsystem: "<< SDL_GetError() << std::endl;
        exit(1);
    }
    
    // Setup the OpenGL Context
    // Use OpenGL 4.1 core or greater
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    // We want to request a double buffer for smooth updating.
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 4);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 4);

    // Create an application window using OpenGL that supports SDL
    gGraphicsApplicationWindow =  SDL_CreateWindow(
                            "OpenGL Triangle",
                            0, 0,
                            gScreenWidth, gScreenHeight,
                            SDL_WINDOW_OPENGL
                        );

    // Check if Window did not create.
    if(gGraphicsApplicationWindow == nullptr) {
        std::cout << "SDL_Window was not able to be created" << std::endl;
        exit(1);
    }

    // Create an OpenGL Graphics Context
    gOpenGLContext = SDL_GL_CreateContext(gGraphicsApplicationWindow);
    if(gOpenGLContext == nullptr){
        std::cout << "OpenGL context not available\n";
    }

    // Initialize the GLAD library (or GLEW)
    if(!gladLoadGLLoader(SDL_GL_GetProcAddress)){
        std::cout << "glad was not initialized" << std::endl;
        exit(1);
    }
    GetOpenGLVersionInfo();

    // Debugger Setup
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(debugMessage, NULL);

    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, NULL, GL_TRUE);
}


/*---------------Main Loop---------------*/

/**
 * Function called in the main loop application loop to handle user input
 * 
 * @return void
 */
void Input(){

    // Event Handler that handles various events in SDL
    // that are related to input and output
    SDL_Event e;

    // Handles events on Queue
    while(SDL_PollEvent(&e) != 0){

        // If users posts an event to quit
        // An example is hitting the "x" in the corner of the window.
        if(e.type == SDL_QUIT){
            std::cout << "Goodbye! (Leaving MainApplicationLoop())" << std::endl;
            gQuit = true;
        }
    }
}

/**
 * PreDraw
 * Typically we will use this for setting some sort of 'state'
 * Note: some of the calls may take place at different stages (post-processing) of the pipeline
 * 
 * @return void
 */
void PreDraw(){

    // Disable depth test and face culling 
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);    

    // Initialize clear color
    // This is the background of the screen
    glViewport(0,0,gScreenWidth, gScreenHeight);
    glClearColor(1.f, 1.f, 1.f, 1.f);

    // Clear color buffer and Depth Buffer
    glClear(GL_DEPTH_BUFFER_BIT |  GL_COLOR_BUFFER_BIT);

    // Use our shader 
    glUseProgram(gGraphicsPipelineShaderProgram);
}

/**
 * Draw
 * The render function gets called once per loop.
 * Typically this includes 'glDraw' related calls, and the relevant setup of buffers for those calls 
 * 
 * @return void 
 */
void Draw(){

    // Enable our attributes
    glBindVertexArray(gVertexArrayObject);

    // Select the vertex buffer object we want to enable 
    glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferObject);

    // Render data
    // glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0 );

    // Stop using our current graphics pipeline 
    // Note: This is not necessary if we only have one graphics pipeline.
    glUseProgram(0);
}
/*---------------Main Loop---------------*/

/**
 * Main Application Loop
 * This is an infinite loop
 * 
 * @return void
 */
void MainLoop(void){
    
    // While application is running
    while(!gQuit){

        // Handle input
        Input();

        // Setup anything (i.e. OpenGL State) that need to take place
        // before the draw calls.
        PreDraw();

        // Draws Calls in OpenGL
        Draw();

        // Update the screen of our specified window
        SDL_GL_SwapWindow(gGraphicsApplicationWindow);
    }
}

/**
 * The last function called in the Program
 * This functions  responsibility is to destroy any global objects in which we have created memory
 * 
 * @return void
 */
void CleanUp(void){

    // Destroy our SDL2 Window
    SDL_DestroyWindow(gGraphicsApplicationWindow);
    gGraphicsApplicationWindow = nullptr;

    // Delete our OpenGL Objects
    glDeleteBuffers(1, &gVertexBufferObject);
    glDeleteVertexArrays(1, &gVertexArrayObject);

    // Delete our Graphics pipeline
    glDeleteProgram(gGraphicsPipelineShaderProgram);
    
    // Quit SDL subsystems
    SDL_Delay(1);
    SDL_Quit();
}

/*------------------------------Main------------------------------*/

/**
 * The main entry point for our C++ programs.
 * 
 * @return program status
 */
int main(int agrc, char* argv[]){

    // 1. Setup the graphics program
    InitializeProgram();

    // 2. Setup our geometry
    VertexSpecification();

    // 3. Create our graphics pipeline    
    // - At a minimum this means the vertex and fragment shader
    CreateGraphicsPipeline();

    // 4. Call the main application loop
    MainLoop();

    // 5. Call the cleanup function when our program terminates
    CleanUp();

    return 0;
}