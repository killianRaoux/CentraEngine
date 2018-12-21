#include "ctpch.h"
#include "GameObject.h"
#include "glm/gtc/matrix_transform.hpp"
#include "../GameEngine.h"


IGameObject::IGameObject(Model* model, IRender* render, Shader* shader):
	m_model(model), m_render(render), m_shader(shader)
{

}

IGameObject::IGameObject(const std::string& model_name, const std::string& render_name, const std::string& shader_name):
	m_model(GameEngine::get_model(model_name)),
	m_render(GameEngine::get_render(render_name)),
	m_shader(GameEngine::get_shader(shader_name))
{

}

void IGameObject::draw(ICamera* cam)
{
	m_matrix = glm::rotate(m_matrix, glm::radians(1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	m_render->draw(cam, m_matrix, m_model, m_shader);
}

void IGameObject::translate(const glm::vec3& v)
{
	m_matrix = glm::translate(m_matrix, v);
}

void IGameObject::rotate(const glm::vec3& v, float angle)
{
	m_matrix = glm::rotate(m_matrix, angle, v);
}

void IGameObject::scale(const glm::vec3& v)
{
	m_matrix = glm::scale(m_matrix, v);
}