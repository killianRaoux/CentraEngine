#pragma once
#include <GL/glew.h>
#include <GL/glut.h>

static void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

static void GLCheckError()
{
	while (GLenum error = glGetError())
	{
		CT_CORE_CRITICAL("Erreur GL: {}", error);
	}
}

#define GLCall(x) GLClearError();x;GLCheckError();