#pragma once
#include "Texture.h"
#include "../Render/Shader/Shader.h"
class Material
{
public:
	Material(const std::string& name);
	~Material();
	void bind(Shader* shader);
protected:
	Texture* m_texture;
	float m_ambient;
	float m_specular;
	float m_diffuse;
};

