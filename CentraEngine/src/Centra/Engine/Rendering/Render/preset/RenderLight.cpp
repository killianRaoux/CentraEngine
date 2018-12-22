#include "ctpch.h"
#include "RenderLight.h"
#include "Centra/Engine/GameEngine.h"

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
	GameEngine::get_current_scene()->bind_light(shader);
	model->bind(shader);
	shader->setUniformMatrix4f("mvp.view", cam->get_view_matrix());
	shader->setUniformMatrix4f("mvp.projection", cam->get_projection_matrix());
	shader->setUniformMatrix4f("mvp.model", model_matrix);
	glm::vec3 viewpos = cam->get_position();
	shader->setUniform3f("viewpos", viewpos.x, viewpos.y, viewpos.z);
	GLCall(glDrawElements(GL_TRIANGLES, model->get_indicies_count(), GL_UNSIGNED_INT, nullptr));;
}
