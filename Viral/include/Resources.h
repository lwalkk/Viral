#ifndef RESOURCES_H
#define RESOURCES_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

void InitializeOpenGL()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void InitializeGLEW()
{
    if (glewInit() != GLEW_OK)
    {
        std::cout << "ERROR:GLEW INIT" << std::endl;
    }
}
#endif