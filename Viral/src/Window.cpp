#include "Window.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

Window::Window(const int width, const int height, const char* name) :
	m_width(width), m_height(height), m_title(name)
{
    m_window = glfwCreateWindow(800, 600, "Viral Renderer", NULL, NULL);

    if (m_window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    glViewport(0, 0, 800, 600);
    glfwMakeContextCurrent(m_window);
    glfwSetFramebufferSizeCallback(m_window, framebuffer_size_callback);
}

Window::~Window()
{
    delete[] m_title;
    glfwDestroyWindow(m_window);
}

bool Window::ShouldClose() const
{
    return glfwWindowShouldClose(m_window);
}

 void Window::CheckInput()
 {
     if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
         glfwSetWindowShouldClose(m_window, true);
 }

 void Window::Refresh()
 {
     glfwSwapBuffers(m_window);
     glfwPollEvents();
 }

