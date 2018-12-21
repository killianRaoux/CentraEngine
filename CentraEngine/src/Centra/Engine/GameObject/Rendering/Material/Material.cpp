#include "ctpch.h"
#include "Material.h"
#include "../../../GameEngine.h"


Material::Material(const std::string& name):
	m_ambient(0.5)
{
	m_texture = GameEngine::get_texture(name);
}

Material::~Material()
{
}

void Material::bind(Shader* shader)
{
	//shader->setUniform1f("u_ambient", m_ambient);
	m_texture->bind();
}
