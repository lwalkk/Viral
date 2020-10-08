// OpenGL
#include <GL/glew.h>
#include <GLFW/glfw3.h>
// STL 
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
// Maths
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
// Project headers
#include "Window.h"
#include "Resources.h"
#include "VertexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "IndexBuffer.h"
#include "Renderer.h"

int main()
{
    InitializeOpenGL();
    Window* window = new Window(800, 600, "Viral 3D Renderer");
    InitializeGLEW();
    // get rid of these

    float vertices[] =
    {
         // position        // texture coords
         0.5f,  0.5f, 0.0f, 1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f, 0.0f, 1.0f  // top left
    };

    unsigned int indices[] =
    {
        0, 1, 3,
        1, 2, 3
    };

    VertexArray va;
    VertexBuffer vb(vertices, sizeof(vertices));

    VertexBufferLayout layout;
    layout.Push<float>(5);
    va.AddBuffer(vb, layout);

    IndexBuffer ib(indices, sizeof(indices));


    Shader shaders("res/shaders/Vertex.shader", "res/shaders/Fragment.shader");
    shaders.Use();

    Renderer renderer;

    while (!window->ShouldClose()) // function checks if glfw has been instructed to close
    {
    
        window->CheckInput();

        std::cout << "hello world" << std::endl;

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        renderer.Draw(va, ib, shaders);

        glBindVertexArray(0);

        window->Refresh();
    }
	
}