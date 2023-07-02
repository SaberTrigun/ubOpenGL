#include <iostream>
#include "include/glad/glad.h"
#include "include/GLFW/glfw3.h"
#include <GL/gl.h>

class Opengl
{
protected:
    int     scrWidth;
    int     scrHeight;
    int     majorVersion;
    int     minorVersion;

    GLFWwindow*     window;

    void openGLInit(int MajorVersion, int MinorVersion){
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, MajorVersion);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, MinorVersion);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

    static void framebuffer_size_callback(GLFWwindow* window, int scrWidth, int scrHeight){
        glViewport(0, 0, scrWidth, scrHeight);
    }
public:
    Opengl() : scrWidth(800), scrHeight(600), majorVersion(3), minorVersion(3), window(nullptr)
    {
        openGLInit(majorVersion, minorVersion);
    }

    Opengl(int ScrWidth, int ScrHeight, int MajorVersion, int MinorVersion) :
        scrWidth(ScrWidth),
        scrHeight(ScrHeight),
        majorVersion(MajorVersion),
        minorVersion(MinorVersion),
        window(nullptr)
    {
        openGLInit(majorVersion, minorVersion);
    }


    bool createWindow(){
        bool result = true;
        window = glfwCreateWindow(scrWidth, scrHeight, "OpenGL Window", NULL, NULL);
        if(window == NULL){
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            result = false;
        }
        return result;
    }


    bool settinWindow(){
        bool result = true;
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
            std::cout << "Failed initialize GLAD" << std::endl;
            result = false;
        }
        return result;
    }


    bool oglGlfwWindowShouldClose(){
        return glfwWindowShouldClose(window);
    }


    void oglGlClearColor(float r, float g, float b, float a){
        glClearColor(r, g, b, a);
    }


    void oglGlClear(){
        glClear(GL_COLOR_BUFFER_BIT);
    }


    void oglGlfwSwapBuffers(){
        glfwSwapBuffers(window);
    }


    void oglGlfwPollEvents(){
        glfwPollEvents();
    }
};
