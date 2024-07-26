#include "Camera.hpp"
#include <iostream>

Camera::Camera(){

    // Assume we are placed at the origin
    _eye = glm::vec3(0.f, 0.f, 0.f);

    // Assume we are looking out into the world
    // Note: This is along '-z' because otherwise we would be looking
    //      behind us
    _viewDirection = glm::vec3(0.f, 0.f, -1.f);

    // Assume we start on a perfect plane
    _up = glm::vec3(0.f, 1.f, 0.f);

}

glm::mat4 Camera::GetViewMatrix() const { 
return glm::lookAt(Camera::_eye, Camera::_viewDirection, Camera::_up);
}

void Camera::MoveForward(float& speed){
    
    // Simple but not yet correct
    // fixed in next tutorial

    _eye.z += speed;
    std::cout << "eye.z: " << _eye.z << std::endl;
}
void Camera::MoveBackward(float& speed){
    _eye.z -= speed;
    std::cout << "eye.z: " << _eye.z << std::endl;
};
void Camera::MoveLeft(float& speed){
    _eye.x -= speed;
    std::cout << "eye.x: " << _eye.x << std::endl;
};
void Camera::MoveRight(float& speed){
    _eye.x += speed;
    std::cout << "eye.x: " << _eye.x << std::endl;
};