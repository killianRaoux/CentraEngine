#pragma once
#include "../Object/GLObject.h"
#include "../Material/Material.h"

#include "glm/matrix.hpp"

class Model
{
public:
	Model(
		float* verticies, unsigned int verticies_count,
		unsigned int* indicies, unsigned int indicies_count,
		std::string material);
	Model(const std::string& str);
	~Model();
	void bind(Shader* shader);
	unsigned int get_indicies_count();
	void load_obj(const std::string& obj_path);
private:
	VertexArray*  va;
	VertexBuffer* vb;
	BufferLayout* bl;
	IndexBuffer*  ib;
	Material*     mat;
};

