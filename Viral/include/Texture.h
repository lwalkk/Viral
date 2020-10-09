#ifndef TEXTURE_H
#define TEXTURE_X

#include<GL/glew.h>

#include "stb_image.h"

class Texture
{
public:

	Texture(const char* filepath);
	~Texture();

	void Bind() const;
	void Unbind() const;

private:
	unsigned int m_TextureID;
	unsigned char* m_Data;

};

#endif