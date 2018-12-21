#include "ctpch.h"
#include "VertexBuffer.h"

#include <GL/glew.h>
#include <GL/glut.h>
VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
	glGenBuffers(1, &m_id);
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_id);
}

void VertexBuffer::bind()const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_id);
}

void VertexBuffer::unbind()const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
