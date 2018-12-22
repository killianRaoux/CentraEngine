
#include "ctpch.h"

#include "Shader.h"

#include "hgl.h"
#include "glm/gtc/type_ptr.hpp"

std::string tostring(glm::mat4 mat)
{
	std::string res;
	for (int i = 0; i<4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			res = res + std::to_string(mat[i][j]);
			res = res + " ,";
		}
		res = res + '\n';
	}
	return res;
}
 Shader::Shader(const std::string & filepath) :
	m_filepath(filepath), m_id(0)
 {
	createShader(filepath);
	bind();
	checkUniform();
}

// Destructeur.
 Shader::~Shader()
{
}

// Lie le shader a openGL.
void  Shader::bind() const
{
	
	glUseProgram(m_id);
}

// Delie.
void  Shader::unbind() const
{
	glUseProgram(0);
}



/*
Creer un shader depuis plusieur fichiers sources.
*/
bool  Shader::createShader(const std::string & vs_src, const std::string & fs_src)
{
	m_id = glCreateProgram();
	
	unsigned int vs = compileShader(GL_VERTEX_SHADER, vs_src);
	unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fs_src);

	glAttachShader(m_id, vs);
	glAttachShader(m_id, fs);
	glLinkProgram(m_id);
	glValidateProgram(m_id);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return true;
}

bool  Shader::createShader(const std::string & filepath)
{
	enum class ShaderType
	{
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};
	std::ifstream stream(filepath);
	if (!stream)
	{
		CT_CORE_CRITICAL("Impossible de charger le ficher {}", filepath);
		return false;
	}

	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;
	while (getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
			{
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				type = ShaderType::FRAGMENT;
			}
		}
		else
		{
			ss[(int)type] << line << '\n';
		}

	}
	return createShader(ss[0].str(), ss[1].str());
}

unsigned int  Shader::compileShader(unsigned int type, const std::string & source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();

	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);

	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);

		CT_CORE_CRITICAL("Failed to compile {}", (type == GL_VERTEX_SHADER ? "vertex" : "fragment"));
		CT_CORE_CRITICAL(message);
		glCompileShader(id);
		return 0;
	}

	return id;
}

/*
TODO
*/
void  Shader::setUniform4f(const std::string & name, float v0, float v1, float v2, float v3)
{
	glUniform4f(getUniformLocation(name), v0, v1, v2, v3);
}

void  Shader::setUniform1f(const std::string& name, float v0)
{
	glUniform1f(getUniformLocation(name), v0);
}

void Shader::setUniform2f(const std::string& name, float v0, float v1)
{
	glUniform2f(getUniformLocation(name), v0, v1);
}

void Shader::setUniform3f(const std::string& name, float v0, float v1, float v2)
{
	glUniform3f(getUniformLocation(name), v0, v1, v2);
}

void  Shader::setUniform1i(const std::string& name, int v0)
{
	glUniform1i(getUniformLocation(name), v0);
}

void Shader::setUniform2i(const std::string& name, int v0, int v1)
{
	glUniform2i(getUniformLocation(name), v0, v1);
}

void Shader::setUniform3i(const std::string& name, int v0, int v1, int v2)
{
	glUniform3i(getUniformLocation(name), v0, v1, v2);
}

void Shader::setUniform4i(const std::string& name, int v0, int v1, int v2, int v3)
{
	glUniform4i(getUniformLocation(name), v0, v1, v2, v3);
}

void Shader::setUniformMatrix4f(const std::string& name, const glm::mat4& mat)
{
	glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &mat[0][0]);
}

void Shader::checkUniform()
{
	GLint i;
	GLint count;

	GLint size; // size of the variable
	GLenum type; // type of the variable (float, vec3 or mat4, etc)

	const GLsizei bufSize = 16; // maximum name length
	GLchar name[bufSize]; // variable name in GLSL
	GLsizei length;
	glGetProgramiv(m_id, GL_ACTIVE_UNIFORMS, &count);
	CT_CORE_INFO("Active Uniforms: %d\n", count);

	for (i = 0; i < count; i++)
	{
		glGetActiveUniform(m_id, (GLuint)i, bufSize, &length, &size, &type, name);
		CT_CORE_TRACE("Uniform #{} Type: {} Name: {}", i, type, name);
	}
}
std::string Shader::get_path()
{
	return m_filepath;
}

unsigned int  Shader::getUniformLocation(const std::string & name)
{
	if (m_uniformLocationCache.find(name) != m_uniformLocationCache.end())
		return  m_uniformLocationCache[name];
	int location = glGetUniformLocation(m_id, name.c_str());
	if (location == -1)
	{
		CT_CORE_WARN("Uniform '{}' not found in shader '{}'", name, m_filepath);
		m_uniformLocationCache[name] = location;
	}
	return location;

}
