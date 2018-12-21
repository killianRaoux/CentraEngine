#pragma once

#include "ctpch.h"
class IndexBuffer
{
public:
	IndexBuffer(unsigned int* index, unsigned int size);
	~IndexBuffer();
	unsigned int get_id();
	unsigned int get_count() const;
	void bind();
	void unbind();
private:
	unsigned int m_id,m_count;
};

