#pragma once
#include "ctpch.h"
#include "Shader/Shader.h"
#include "../Model/Model.h"
#include "../../../Scene/ICamera.h"

class CT_API IRender
{
protected:
	std::string m_name;
public:
	IRender(std::string name);
	//virtual void on_draw() = 0;
	virtual void draw(ICamera* cam,const glm::mat4& model_matrix, Model* model, Shader* shader);
	std::string get_name();
};
