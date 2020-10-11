#pragma once

#include <glm/glm.hpp>
#include <string>

#include "VertexArray.h"
#include "Shader.h"
#include "Renderer.h"
#include "Texture.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"

// Class for a cube
// Supports textures, shaders, and geometric operations

class Cube // : public object?
{
public:
	Cube();
	~Cube();

	void AttachShader(std::string vertex, std::string frag);
	void AttachTexture(std::string filepath);
	void Draw();
	void Translation(float x, float y, float z);
	void Rotation(float theta, float phi);
	void Scale(float sx, float sy, float sz);
	void Scale(float factor);


	

private:
	glm::vec3 m_position;
	glm::vec3 m_rotation;
	VertexBuffer m_vb;
	IndexBuffer m_ib;
	Texture m_texture;
	Shader m_shader;
	VertexArray m_va;
};