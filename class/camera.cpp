#include "camera.h"

namespace UB
{


    const float YAW         = -90.0f;
    const float PITCH	    = 0.0f;
    const float SPEED	    = 2.5f;
    const float SENSITIVITY	= 0.1f;
    const float ZOOM	    = 45.0f;


    void Camera::updateCameraVectors()
    {
        glm::vec3 Front;
        Front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        Front.y = sin(glm::radians(pitch));
        Front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        front   = glm::normalize(Front);

        right   = glm::normalize(glm::cross(front, worldUp));
        up      = glm::normalize(glm::cross(right, front));
    }


    Camera::Camera(glm::vec3 cameraPosition) :
        position(cameraPosition),
        front(glm::vec3(0.0f, 0.0f, -1.0f)),
        worldUp(glm::vec3(0.0f, 1.0f, 0.0f)),
        yaw(YAW),
        pitch(PITCH),
        movementSpeed(SPEED),
        mouseSensitivity(SENSITIVITY),
        zoom(ZOOM)
    {
        updateCameraVectors();
    }


    glm::vec3 Camera::GetCamPosition() const
    {
        return position;
    }


    glm::vec3 Camera::GetCamDirection() const
    {
        return position - front;
    }


    glm::mat4 Camera::GetViewMatrix() const
    {
        return glm::lookAt(position, position + front, up);
    }


    void Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime)
    {
        float velocity = movementSpeed * deltaTime;
        if (direction == FORWARD)
            position += front * velocity;
        if (direction == BACKWARD)
            position -= front * velocity;
        if (direction == LEFT)
            position -= right * velocity;
        if (direction == RIGHT)
            position += right * velocity;
    }


    void Camera::ProcessMouseMovement(float xoffset, float yoffset, bool constrainPitch)
    {
        xoffset *= mouseSensitivity;
        yoffset *= mouseSensitivity;

        yaw     += xoffset;
        pitch   += yoffset;
        //pitch   = 0.0f; // Для 2D камеры, выключает ось Y

        if (constrainPitch)
        {
            if (pitch > 89.0f)
                pitch = 89.0f;
            if (pitch < -89.0f)
                pitch = -89.0f;
        }
        updateCameraVectors();
    }


    void Camera::ProcessMouseScroll(float yoffset)
    {
        if (zoom >= 1.0f && zoom <= 45.0f)
            zoom -= yoffset;
        if (zoom <= 1.0f)
            zoom = 1.0f;
        if (zoom >= 45.0f)
            zoom = 45.0f;
    }















}
