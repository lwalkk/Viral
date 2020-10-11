#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
	inline unsigned int ID() const { return m_ID; }

	Shader(const char* vertexPath, const char* fragmentPath);
	// use/ activate the shader
	void Use() const;
	// utility uniform functions
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
private:
	unsigned int m_ID;
};
#endif

