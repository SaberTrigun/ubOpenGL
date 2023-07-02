#ifndef UB_CAMERA_H
#define UB_CAMERA_H


#include <cmath>
#include "../include/glm/glm/glm.hpp"
#include "../include/glm/glm/gtc/matrix_transform.hpp"
#include "../include/glm/glm/gtc/type_ptr.hpp"

namespace UB
{


enum Camera_Movement {FORWARD, BACKWARD, LEFT, RIGHT};


class Camera
{
private:
    glm::vec3 up;
    glm::vec3 right;
    glm::vec3 worldUp;

    glm::vec3 front;
    glm::vec3 position;


    float yaw;
    float pitch;

    float movementSpeed;
    float mouseSensitivity;


    float zoom;


    void updateCameraVectors();
public:
    Camera(glm::vec3 cameraPosition);

    glm::vec3 GetCamPosition() const;

    glm::vec3 GetCamDirection() const;

    glm::mat4 GetViewMatrix() const;

    void ProcessKeyboard(Camera_Movement direction, float deltaTime);

    void ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch = true);

    void ProcessMouseScroll(float yoffset);

};

}


#endif // UB_CAMERA_H
