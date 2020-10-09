#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class VertexBuffer
{
public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void BufferData(const void* data);
	void Bind() const;
	void Unbind() const;
	unsigned int getID() const;
private:
	unsigned int m_ID;
};

#endif
