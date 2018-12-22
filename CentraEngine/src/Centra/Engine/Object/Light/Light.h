#pragma once
#include "ctpch.h"
#include "core.h"
#include "../../Rendering/Render/Shader.h"
#include "../Drive/IDrive.h"

class CT_API Light:
	public IDrivable
{
public:
	Light();
	Light(glm::vec3 position, glm::vec3 color);
	~Light();
	void bind(Shader* shader);

	virtual void rotate(float angle, float x, float y, float z) override;
	virtual void translate(float x, float y, float z) override;
	virtual void scale(float x, float y, float z) override;
	virtual void set_rotation(float x, float y, float z) override;
	virtual void set_position(float x, float y, float z) override;
	virtual void set_scale(float x, float y, float z) override;
protected:
	glm::vec3 m_position;
	glm::vec3 m_color;
private:

};

