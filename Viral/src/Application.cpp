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
#include "Texture.h"

int main()
{
    InitializeOpenGL();
    Window* window = new Window(800, 600, "Viral 3D Renderer");
    InitializeGLEW();
    // get rid of these
    float vertices[] =
    {
         // position        // color
         0.5f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
         0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f  // top left
    };

    unsigned int indices[] =
    {
        0, 1, 3,
        1, 2, 3
    };

    VertexArray va;
    VertexBuffer vb(vertices, sizeof(vertices));

    VertexBufferLayout layout;
    layout.Push<float>(3);
    layout.Push<float>(3);
    layout.Push<float>(2);
    va.AddBuffer(vb, layout);
    IndexBuffer ib(indices, sizeof(indices));
    Texture container("res/textures/container.jpg");

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);




    Shader shaders("res/shaders/Vertex.shader", "res/shaders/Fragment.shader");
    shaders.Use();
    int modelLoc = glGetUniformLocation(shaders.ID(), "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    int viewLoc = glGetUniformLocation(shaders.ID(), "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    int projectionLoc = glGetUniformLocation(shaders.ID(), "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));



    Renderer renderer;

    while (!window->ShouldClose()) // function checks if glfw has been instructed to close
    {
    
        window->CheckInput();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        renderer.Draw(va, ib, shaders);

        glBindVertexArray(0);

        window->Refresh();
    }
	
}