#include "ctpch.h"
#include "VertexArray.h"

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_id);
}

VertexArray::~VertexArray()
{
	glDeleteVertexArrays(1, &m_id);
}

void VertexArray::addBuffer(const VertexBuffer & vb, const BufferLayout & layout)
{
	bind();
	vb.bind();
	const auto& elements = layout.getElements();
	unsigned int offset = 0;
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i,
			element.count,
			element.type,
			element.normalized,
			layout.getStride(),
			(const void*)offset);
		offset += element.count * VertexBufferElement::getSizeOfType(element.type);
	}
	vb.unbind();
	unbind();
}

void VertexArray::bind() const
{
	glBindVertexArray(m_id);
}

void VertexArray::unbind() const
{
	glBindVertexArray(0);
}
