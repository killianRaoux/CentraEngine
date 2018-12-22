#pragma once
#include "ctpch.h"

#include "openGL.h"

struct VertexBufferElement
{
	unsigned int type;
	unsigned int count;
	bool normalized;

	static unsigned int getSizeOfType(unsigned int type)
	{
		switch (type)
		{
		case GL_FLOAT: return 4;
		case GL_UNSIGNED_INT: return 4;
		case GL_UNSIGNED_BYTE: return 1;
		}
		
	return 0;
	}
};

class BufferLayout
{
private:
	std::vector<VertexBufferElement> m_elements;
	unsigned int m_stride;
public:
	BufferLayout() :
		m_stride(0) {}
	~BufferLayout() {};

	template<typename T>
	void push(unsigned int count)
	{
		static_assert(false);
	}
	template<>
	void push<float>(unsigned int count)
	{
		m_elements.push_back({ GL_FLOAT, count, false});
		m_stride += count * VertexBufferElement::getSizeOfType(GL_FLOAT);
	}
	template<>
	void push<unsigned int>(unsigned int count)
	{
		m_elements.push_back({ GL_UNSIGNED_INT, count, false });
		m_stride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_INT);
	}
	template<>
	void push<unsigned char>(unsigned int count)
	{
		m_elements.push_back({ GL_UNSIGNED_BYTE, count, false });
		m_stride += count * VertexBufferElement::getSizeOfType(GL_UNSIGNED_BYTE);
	}
	
	inline const std::vector<VertexBufferElement> getElements() const
	{
		return m_elements;
	}
	inline unsigned int getStride() const 
	{
		return m_stride;
	}
};
