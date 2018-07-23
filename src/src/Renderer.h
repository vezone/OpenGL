#pragma once

#include <GL\glew.h>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

#define ASSERT(x) if(!(x)) __debugbreak()

#define DEBUG 1
#if DEBUG == 1
#define GLCall(x)	GLClearError();\
					x;\
					ASSERT(GLLogError(#x, __FILE__, __LINE__))	
#else
#define GLCall(x) x
#endif

void GLClearError();
bool GLLogError(const char* function, const char* file, int line);

class Renderer
{
public:
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
	void Clear() const;
};