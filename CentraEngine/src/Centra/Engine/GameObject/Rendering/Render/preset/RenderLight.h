#pragma once
#include "../IRender.h"
class RenderLight :
	public IRender
{
public:
	RenderLight();
	~RenderLight();

	virtual void draw(ICamera* cam, const glm::mat4& model_matrix, Model* model, Shader* shader) override;

};

