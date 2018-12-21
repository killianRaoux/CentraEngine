#pragma once

#include "Rendering/Model/Model.h"
#include "Rendering/Render/IRender.h"

class CT_API IGameObject
{
protected:
	Model*   m_model;
	IRender* m_render;
	Shader*  m_shader;
	glm::mat4 m_matrix;
public:
	IGameObject(Model* model, IRender* render, Shader* shader);
	IGameObject(
		const std::string& model_name,
		const std::string& render_name,
		const std::string& shader_name);
	virtual void draw(ICamera* cam);
	void translate(const glm::vec3& v);
	void rotate(const glm::vec3& v, float angle);
	void scale(const glm::vec3& v);
};