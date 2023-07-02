#include <iostream>
#include "include/glad/glad.h"
#include "include/GLFW/glfw3.h"
#include "class/shader.h"
#include "class/camera.h"

int gHeight_scr = 1400;
int gWidth_scr  = 800;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{ glViewport(0, 0, width, height); }

int main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    GLFWwindow* window = glfwCreateWindow(gHeight_scr, gWidth_scr, "OpenGL Window", NULL, NULL);
    if(window == NULL){
        std::cout << "Failed to create GLFW Window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    //glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed initialize GLAD" << std::endl;
        return -1;
    }



    UB::Shader shader("vshade", UB::VERTEX);



    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        


        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwTerminate();


    return 0;
}
