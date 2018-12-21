#include "ctpch.h"
#include "ICamera.h"
#include "glm/gtc/matrix_transform.hpp"


ICamera::ICamera(glm::vec3 position, glm::vec3 direction, glm::vec3 up):
	m_position(position)
{
	matrix_projection = glm::perspective(glm::radians(100.0f),
		1.0f, 0.1f, 10.0f);
	matrix_view = glm::lookAt(
		position,  // eyes
		direction,  // center
		up);
}

ICamera::ICamera()
{
	matrix_projection = glm::perspective(glm::radians(100.0f),
		1.0f, 0.1f, 10.0f);
	matrix_view = glm::lookAt(
		glm::vec3(0.0f, 0.0f, 0.0f),  // eyes
		glm::vec3(0.0f, 0.0f, 0.0f),  // center
		glm::vec3(0.0f, 0.0f, 0.0f));
}

ICamera::~ICamera()
{
}

glm::mat4 ICamera::get_VP()
{
	return matrix_projection * matrix_view;
}

glm::mat4 ICamera::get_projection_matrix()
{
	return matrix_projection;
}

void ICamera::set_projection_ortho()
{

}

void ICamera::set_projection_perceptive()
{

}

glm::mat4 ICamera::get_view_matrix()
{
	return matrix_view;
}

glm::vec3 ICamera::get_position()
{
	return m_position;
}

void ICamera::rotate(float angle, glm::vec3 orient)
{
	matrix_view = glm::rotate(matrix_view, glm::radians(angle), orient);
}

void ICamera::translate(glm::vec3 tr)
{
	matrix_view = glm::translate(matrix_view, tr);
}
