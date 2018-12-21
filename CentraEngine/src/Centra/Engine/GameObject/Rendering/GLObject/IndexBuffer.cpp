#include "ctpch.h"
#include "IndexBuffer.h"

#include <GL/glew.h>
#include <GL/glut.h>
IndexBuffer::IndexBuffer(unsigned int * index, unsigned int count):
	m_count(count)
{
	glGenBuffers(1, &m_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), index, GL_STATIC_DRAW);
	unbind();
}

IndexBuffer::~IndexBuffer()
{
}

unsigned int IndexBuffer::get_id()
{
	return 0;
}

unsigned int IndexBuffer::get_count() const
{
	return m_count;
}

void IndexBuffer::bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_id);
}

void IndexBuffer::unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
