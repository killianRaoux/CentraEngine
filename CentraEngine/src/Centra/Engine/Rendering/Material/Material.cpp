#include "ctpch.h"
#include "Material.h"
#include "../../GameEngine.h"


Material::Material(const std::string& name) :
	m_ambient(0.1),
	m_diffuse(0.75164, 0.60648, 0.22648),
	m_specular(0.628281, 0.555802, 0.366065),
	m_shininess(0.1)
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
	//m_shininess += 0.05f;
	shader->setUniform3f("material.ambient", m_ambient.x, m_ambient.y, m_ambient.z);
	shader->setUniform3f("material.diffuse", m_diffuse.x, m_diffuse.y, m_diffuse.z);
	shader->setUniform3f("material.specular", m_specular.x, m_specular.y, m_specular.z);
	shader->setUniform1f("material.shininess", m_shininess);
}
