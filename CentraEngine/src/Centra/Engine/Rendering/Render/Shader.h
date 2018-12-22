#pragma once
#include "ctpch.h"

extern class CT_API Shader
{
public:
	Shader(const std::string&  filepath);
	~Shader();

	void bind() const;
	void unbind() const;

	void setUniform1f(const std::string& name, float v0);
	void setUniform2f(const std::string& name, float v0, float v1);
	void setUniform3f(const std::string& name, float v0, float v1, float v2);
	void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);

	void setUniform1i(const std::string& name, int v0);
	void setUniform2i(const std::string& name, int v0, int v1);
	void setUniform3i(const std::string& name, int v0, int v1, int v2);
	void setUniform4i(const std::string& name, int v0, int v1, int v2, int v3);

	void setUniformMatrix4f(const std::string& name, const glm::mat4& mat);

	void checkUniform();
	std::string get_path();

protected:
	unsigned int m_id;
	std::string m_filepath;
	std::unordered_map<std::string,int> m_uniformLocationCache;
	bool createShader(const std::string & vs_src, const std::string & fs_src);
	bool createShader(const std::string & filepath);
	unsigned int compileShader(unsigned int type, const std::string& source);
	unsigned int getUniformLocation(const std::string& name);
};

