#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {

    public:

        Camera();

        // The ultimate view matrix we will produce
        // and return
        glm::mat4 GetViewMatrix() const;

        void MoveForward(float& speed);
        void MoveBackward(float& speed);
        void MoveLeft(float& speed);
        void MoveRight(float& speed);

    private:

        glm::vec3 _eye;
        glm::vec3 _viewDirection;
        glm::vec3 _up;

};


#endif