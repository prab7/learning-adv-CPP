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


int main(int argc, char* argv[]){

    // we usually almost always normalize our vectors
    // unless we need to know that magnitude, for instance, to model some sort of force

    // Dot product tells us, how similar 2 vectors are
    // for normalized vectors, 
    // 1 = parallel (same), 0 = perpendicular, -1 = parrallel (opposite)
    // in this context, since we only have position vectors, parrallel = same

    // Cross product gives you a vector perpendicular to 2 other vectors
    // Non Commutative
    // interesting relationship with Area

    glm::vec3 A{3.0f, 4.0f, 0.0f};
    glm::vec3 B{0.0f, 7.0f, 0.0f};

    std::cout << "length of A     : " <<glm::length(A) << std::endl;
    std::cout << "A               : " <<glm::to_string(A) << std::endl;
    std::cout << "lengto of A-hat : " << glm::length(glm::normalize(A)) << std::endl;
    std::cout << "A-hat           : " << glm::to_string(glm::normalize(A)) << '\n' <<  std::endl;

    float dotproduct = glm::dot(glm::normalize(A), glm::normalize(B));

    std::cout << "dot(A,B)        : " << glm::dot(A,B) << std::endl;
    std::cout << "dot(A,B)^       : " << dotproduct << std::endl;
    std::cout << "dot(A,B)^(angle): " << std::acos(dotproduct) * 180.0f / glm::pi<float>() << std::endl;

    glm::vec3 C = glm::cross(A, B);

    std::cout << "cross product   : " << glm::to_string(C) << std::endl;

    return 0;
}