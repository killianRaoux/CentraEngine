#pragma once
#include "ctpch.h"
#include "glm/matrix.hpp"
#include "../Drive/IDrive.h"
class CT_API ICamera:
	public IDrivable
{
public:
	ICamera();
	ICamera(glm::vec3 position, glm::vec3 direction, glm::vec3 up);
	~ICamera();
	glm::mat4 get_VP();
	glm::mat4 get_projection_matrix();
	void set_projection_ortho();
	void set_projection_perceptive();
	glm::mat4 get_view_matrix();
	glm::vec3 get_position();

	void rotate(float angle, glm::vec3 orient);
	void translate(glm::vec3 tr);


	virtual void rotate(float angle, float x, float y, float z) override;
	virtual void translate(float x, float y, float z) override;
	virtual void scale(float x, float y, float z) override;
	virtual void set_rotation(float x, float y, float z) override;
	virtual void set_position(float x, float y, float z) override;
	virtual void set_scale(float x, float y, float z) override;

protected:
	glm::mat4 matrix_projection;
	glm::mat4 matrix_view;
	glm::vec3 m_position;
	float m_FOV;


};

