#include "ctpch.h"
#include "DynamicObject.h"
#include "../../GameEngine.h"


DynamicObject::DynamicObject(
	const std::string& model_name,
	const std::string& render_name,
	const std::string& shader_name) :
	IDrivable(),IGameObject(),
	m_model(GameEngine::get_model(model_name)),
	m_render(GameEngine::get_render(render_name)),
	m_shader(GameEngine::get_shader(shader_name)),
	m_position(glm::vec3(0.0f)),
	m_rotation(glm::vec3(0.0f)),
	m_scale(glm::vec3(1.0f))
{
}

DynamicObject::~DynamicObject()
{
}

void DynamicObject::draw(ICamera* cam)
{
	//m_matrix = glm::rotate(m_matrix, glm::radians(1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	m_render->draw(cam, m_matrix, m_model, m_shader);

}

void DynamicObject::rotate(float angle, float x, float y, float z)
{
	m_matrix = glm::rotate(m_matrix, glm::radians(angle), glm::vec3(x, y, z));
}

void DynamicObject::translate(float x, float y, float z)
{
	m_matrix = glm::translate(m_matrix, glm::vec3(x, y, z));
}

void DynamicObject::scale(float x, float y, float z)
{
	m_matrix = glm::scale(m_matrix, glm::vec3(x, y, z));
}

void DynamicObject::set_rotation(float x, float y, float z)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void DynamicObject::set_position(float x, float y, float z)
{
	throw std::logic_error("The method or operation is not implemented.");
}

void DynamicObject::set_scale(float x, float y, float z)
{
	throw std::logic_error("The method or operation is not implemented.");
}
