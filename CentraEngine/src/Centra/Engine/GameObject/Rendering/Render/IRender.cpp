#include "ctpch.h"
#include "IRender.h"
#include "../../../GameEngine.h"


IRender::IRender(std::string name):
	m_name(name)
{

}

void IRender::draw(ICamera* cam, const glm::mat4& model_matrix, Model* model, Shader* shader)
{
	shader->bind();
	model->bind(shader);
	shader->setUniformMatrix4f("u_view", cam->get_view_matrix());
	shader->setUniformMatrix4f("u_projection", cam->get_projection_matrix());
	shader->setUniformMatrix4f("u_model", model_matrix);
	GLCall(glDrawElements(GL_TRIANGLES, model->get_indicies_count(), GL_UNSIGNED_INT, nullptr));
}

std::string IRender::get_name()
{
	return m_name;
}
