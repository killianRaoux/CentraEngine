#include "ctpch.h"
#include "RenderLight.h"


RenderLight::RenderLight():
	IRender("light")
{
}


RenderLight::~RenderLight()
{

}

void RenderLight::draw(ICamera* cam, const glm::mat4& model_matrix, Model* model, Shader* shader)
{
	shader->bind();
	model->bind(shader);
	shader->setUniformMatrix4f("u_view", cam->get_view_matrix());
	shader->setUniformMatrix4f("u_projection", cam->get_projection_matrix());
	shader->setUniformMatrix4f("u_model", model_matrix);
	GLCall(glDrawElements(GL_TRIANGLES, model->get_indicies_count(), GL_UNSIGNED_INT, nullptr));;
}
