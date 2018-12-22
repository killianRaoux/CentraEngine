#pragma once
#include "IGameObject.h"
#include "../Drive/IDrive.h"

class CT_API DynamicObject:
	public IGameObject, public IDrivable
{
protected:
	Model*   m_model;
	IRender* m_render;
	Shader*  m_shader;
	glm::mat4 m_matrix;
	glm::vec3 m_position, m_rotation, m_scale;
public:
	DynamicObject(
		const std::string& model_name,
		const std::string& render_name,
		const std::string& shader_name);
	~DynamicObject();

	virtual void draw(ICamera* cam) override;


	virtual void rotate(float angle, float x, float y, float z) override;


	virtual void translate(float x, float y, float z) override;


	virtual void scale(float x, float y, float z) override;


	virtual void set_rotation(float x, float y, float z) override;


	virtual void set_position(float x, float y, float z) override;


	virtual void set_scale(float x, float y, float z) override;

};

