#ifndef RENDERER_H
#define RENDERER_H
#include <GL/glew.h>
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "Shader.h"
class Renderer
{
public:
	void Draw(const VertexArray&va, const IndexBuffer& ib, const Shader& shader) const; // need vertex array, need index buffer, need shader

private: 

};
#endif