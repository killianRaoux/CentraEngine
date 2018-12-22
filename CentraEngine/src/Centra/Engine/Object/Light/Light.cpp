#include "ctpch.h"
#include "Light.h"


Light::Light():
	m_position(glm::vec3(0.0f)), m_color(glm::vec3(0.0f))
{
}


Light::Light(glm::vec3 position, glm::vec3 color):
	m_position(position), m_color(color)
{

}

Light::~Light()
{
}

void Light::bind(Shader* shader)
{
	shader->setUniform3f("light.color", m_color.x, m_color.y, m_color.z);
	shader->setUniform3f("light.position", m_position.x, m_position.y, m_position.z);
}

void Light::rotate(float angle, float x, float y, float z)
{
}

void Light::translate(float x, float y, float z)
{
	m_position += glm::vec3(x, y, z);
}

void Light::scale(float x, float y, float z)
{
}

void Light::set_rotation(float x, float y, float z)
{
}

void Light::set_position(float x, float y, float z)
{
	m_position = glm::vec3(x, y, z);
}

void Light::set_scale(float x, float y, float z)
{
}
