#pragma once
#include "ctpch.h"
#include "Shader.h"
#include "../Model/Model.h"
#include "../../Object/Camera/ICamera.h"

/*
Interface for render one gameObject.
	void draw(...): method to draw the model.
		:param cam         : Camera.
		:param model_matrix: Model matrix.
		:param model       : Model to draw.
		:param shader      : Shader.
*/
class CT_API IRender
{
protected:
	std::string m_name; // Name of render.
public:
	// Constructor.
	/*

	*/
	IRender(std::string name);
	//************************************
	// Method:    draw
	// FullName:  IRender::draw
	// Access:    virtual public 
	// Returns:   void
	// Qualifier:
	// Parameter: ICamera * cam 
	// Parameter: const glm::mat4 & model_matrix
	// Parameter: Model * model
	// Parameter: Shader * shader
	//************************************
	virtual void draw(ICamera* cam,const glm::mat4& model_matrix, Model* model, Shader* shader);
	//************************************
	// Method:    get_name
	// FullName:  IRender::get_name
	// Access:    public 
	// Returns:   std::string
	// Qualifier:
	//************************************
	std::string get_name();
};
