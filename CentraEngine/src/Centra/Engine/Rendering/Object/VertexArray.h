#pragma once

#include "VertexBuffer.h"
#include "BufferLayout.h"
#include "hgl.h"

class VertexArray
{
private:
	unsigned int m_id;
public:
	VertexArray();
	~VertexArray();

	void addBuffer(const VertexBuffer& vbo, const BufferLayout& layout);
	
	void bind() const;
	void unbind() const;
};