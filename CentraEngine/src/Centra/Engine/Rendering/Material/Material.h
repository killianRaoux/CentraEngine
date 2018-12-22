#pragma once
#include "Texture.h"
#include "../Render/Shader.h"
class Material
{
public:
	Material(const std::string& name);
	~Material();
	void bind(Shader* shader);
protected:
	Texture* m_texture;
	glm::vec3 m_ambient;
	glm::vec3 m_specular;
	glm::vec3 m_diffuse;
	float m_shininess;
};

