#pragma once
#include "ctpch.h"

class CT_API Texture
{
private:
	unsigned int m_id;
	std::string m_filepath;
	unsigned char* m_localBuffer;
	int m_width, m_height, m_BPP;
public:
	Texture(const std::string& filepath);
	~Texture();

	void bind(unsigned int slot = 0) const;
	void unbind() const;

	inline int get_width() const { return m_width; };
	inline int get_height() const { return m_height; };
	inline int get_BPP() const { return m_BPP; };
};

