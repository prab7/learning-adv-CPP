#define GLM_FORCE_SWIZZLE // A.xyz();
#define GLM_ENABLE_EXPERIMENTAL 
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4

#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale 
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi


int main(){
    
    // 'local coordinates'
    // w=1 => position (point)
    glm::vec4 vertex(1.0f, 5.0f, 1.0f, 1.0f);

    // position + position = w=2 => nonsensical
    // position - position = w=0 => direction (vector)
    // point1 - point2 = direction of pt1 to pt2 global vector
    // vector - vector = w=0 => vector (positional)

    // OpenGL is Column Major

    // model matrix for our geometry
    glm::mat4 model{1.0f}; // Identity

    // Perform some transformations (i.e. moving us in the world)
    // We are now in 'world space'

    // +-       -+   +- -+   +- -+
    // | 1 0 0 0 |   | 1 |   | 1 |  new location
    // | 0 1 0 0 | * | 5 | = | 5 |  (world space)
    // | 0 0 1 0 |   | 1 |   | 1 |
    // | 0 0 0 1 |   | 1 |   | 1 |
    // +-       -+   +- -+   +- -+

    // Scaling Matrix
    glm::mat4 s = glm::scale(glm::mat4(1.0f),glm::vec3(3.0f,2.0f,2.0f));

    // Rotation Matrix
    glm::mat4 r = glm::rotate(glm::mat4(1.0f), glm::radians(180.0f), glm::vec3(0,1,0));

    // Translation Matrix
    glm::mat4 t = glm::translate(glm::mat4(1.0f), glm::vec3(0.f, 0.f, -2.f));

    // translate, rotate then scale. (Non Commutative)
    model = s*r*t;  

    // print it out
    for(int i = 0; i < 4; i++){
        std::cout << glm::to_string(model[i]) << std::endl;
    }

    // now apply our 'model' matrix to the vertex
    glm::vec4 worldspace_vertex = (model * vertex);

    std::cout << '\n' << "our vertex in world space\n"; 
    std::cout << glm::to_string(worldspace_vertex) << std::endl;

    // learnopengl.com for scaling matrix, translation matrix and rotation matrices

    return 0;
}