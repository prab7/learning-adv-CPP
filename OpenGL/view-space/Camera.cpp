#include "Camera.hpp"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>
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

    return glm::lookAt(_eye, _eye + _viewDirection, _up);

}

void Camera::MouseLook(int mouseX, int mouseY){

    std::cout << "mouse: "<< mouseX << "," << mouseY << std::endl;

    glm::vec2 currentMouse = glm::vec2(mouseX, mouseY);
    
    static bool firstLook = true;
    if(firstLook){
        _OldMousePosition = currentMouse;
        firstLook = false;
    }

    glm::vec2 mouseDelta = _OldMousePosition - currentMouse;

    _viewDirection = glm::rotate(_viewDirection, glm::radians(mouseDelta.x), _up);

    _OldMousePosition = currentMouse;

}



void Camera::MoveForward(float& speed){
    
    // Simple but not yet correct
    // fixed in next tutorial
    
    _eye += (_viewDirection*speed);
    std::cout << "eye movin forward" << std::endl;
}
void Camera::MoveBackward(float& speed){
    _eye -= (_viewDirection*speed);
    std::cout << "eye movin back" << std::endl;
}
void Camera::MoveLeft(float& speed){
}
void Camera::MoveRight(float& speed){
}