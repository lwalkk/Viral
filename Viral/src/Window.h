#ifndef WINDOW_H
#define WINDOW_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window
{
public:
	Window(const int width, const int height, const char* name);
	//Window(const Window& window);
	~Window();
	bool ShouldClose() const;
	void CheckInput();
	void Refresh();
private:

	const char* m_title;
	int m_width, m_height;
	GLFWwindow* m_window;
};

#endif