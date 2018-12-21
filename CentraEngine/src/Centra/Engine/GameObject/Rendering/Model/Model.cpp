#include "ctpch.h"
#include "Model.h"
#include "../../../GameEngine.h"
std::vector<std::string> split(const std::string& str, const char sep)
{
	std::string temp("");
	std::vector<std::string> res;

	for (const char& c : str)
	{
		if (c == sep)
		{
			res.push_back(temp);
			temp = "";
		}
		else
		{
			temp += c;
		}
	}
	res.push_back(temp);
	return res;

}

Model::Model(float* verticies, unsigned int verticies_size,
	unsigned int* indicies, unsigned int indicies_count,
	std::string material_name)
{
	va = new VertexArray();
	vb = new VertexBuffer(verticies, verticies_size);
	bl = new BufferLayout();
	ib = new IndexBuffer(indicies, indicies_count);
	mat    = GameEngine::get_material(material_name);
	bl->push<float>(3);
	bl->push<float>(2);
	bl->push<float>(3);
	va->addBuffer(*vb, *bl);
}

Model::Model(const std::string& str)
{
	load_obj(str);
}

Model::~Model()
{
}

void Model::bind(Shader* shader)
{
	va->bind();
	ib->bind();
	mat->bind(shader);
}


unsigned int Model::get_indicies_count()
{
	return ib->get_count();
}

void Model::load_obj(const std::string& obj_path)
{
	std::vector<float> v;
	std::vector<float> vt;
	std::vector<float> vn;
	std::vector<float> vertex;
	std::vector<unsigned int> indicies;
	unsigned int indextemp = 0;
	std::ifstream file(obj_path.c_str());
	std::string line;

	if (!file.is_open())
	{
		CT_CORE_CRITICAL("Impossible de charger le fichier {}", obj_path);
	}
	unsigned int ui_vcount = 0;
	while (std::getline(file, line))
	{
		std::vector<std::string> vstrings = split(line, ' ');

		if (vstrings.size() == 0)
			continue;
		if (vstrings[0] == "v")
		{
			unsigned int offset = 0;
			if (vstrings[1] == "")
				offset += 1;
			v.push_back(std::stof(vstrings[1+offset]));
			v.push_back(std::stof(vstrings[2+offset]));
			v.push_back(std::stof(vstrings[3+offset]));
		}
		else if (vstrings[0] == "vt")
		{
			unsigned int offset = 0;
			if (vstrings[1] == "")
				offset += 1;
			vt.push_back(std::stof(vstrings[1 + offset]));
			vt.push_back(std::stof(vstrings[2 + offset]));
		}
		else if (vstrings[0] == "vn")
		{
			unsigned int offset = 0;
			if (vstrings[1] == "")
				offset += 1;
			vn.push_back(std::stof(vstrings[1 + offset]));
			vn.push_back(std::stof(vstrings[2 + offset]));
			vn.push_back(std::stof(vstrings[3 + offset]));
		}
		else if (vstrings[0] == "f")
		{
			unsigned int vi, vti, vni;
			for (int i = 1; i < 4; i++)
			{
				ui_vcount += 1;
				std::vector<std::string> temp = split(vstrings[i], '/');
				vi  = std::atoi(temp[0].c_str())-1;
				vti = std::atoi(temp[1].c_str())-1;
				vni = std::atoi(temp[2].c_str())-1;
				vertex.push_back(v[vi * 3]);
				vertex.push_back(v[vi * 3 + 1]);
				vertex.push_back(v[vi * 3 + 2]);
				vertex.push_back(vt[vti * 2]);
				vertex.push_back(vt[vti * 2 + 1]);
				vertex.push_back(vn[vni * 3]);
				vertex.push_back(vn[vni * 3 + 1]);
				vertex.push_back(vn[vni * 3 + 2]);
				indicies.push_back(indextemp);
				indextemp += 1;
			}

		}
		else if(vstrings[0] == std::string("usemtl"))
		{
			mat = GameEngine::get_material(vstrings[1]);
		}
	}
	CT_CORE_INFO("{} {}", vertex.size(), indicies.size());
	va = new VertexArray();
	vb = new VertexBuffer(vertex.data(), vertex.size()*sizeof(float));
	bl = new BufferLayout();
	bl->push<float>(3);
	bl->push<float>(2);
	bl->push<float>(3);
	va->addBuffer(*vb, *bl);
	ib = new IndexBuffer(indicies.data(), indicies.size());
	
}

/*
void Model::before_draw(glm::mat4 mvp)
{
	// TODO
}

void Model::draw(glm::mat4 mvp)
{
	
	shader->bind();
	shader->setMVP(mvp);
	GLCall(glDrawElements(GL_TRIANGLES, ib->get_count(), GL_UNSIGNED_INT, nullptr));
}
*/