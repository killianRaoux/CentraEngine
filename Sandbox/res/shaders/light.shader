#shader vertex
#version 330 core

struct MVP
{
	mat4 view;
	mat4 model;
	mat4 projection;
};
layout(location = 0) in vec4 in_Vertex;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in vec3 normalCoord;

out vec2 v_texCoord;
out vec3 v_normal;
out vec3 fragpos;

uniform MVP mvp;

float ambient = 0.5;
float speculat = 0.5;



// Fonction main

void main()
{
	// Position finale du vertex
	vec4 res = mvp.projection * mvp.view * mvp.model * in_Vertex;
	gl_Position = res;
	fragpos = vec3(mvp.model * in_Vertex);
	v_texCoord = texCoord;
	v_normal = normalCoord;
}

#shader fragment
#version 330 core

struct Material {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};

struct Light
{
	vec3 color;
	vec3 position;
};

in vec2 v_texCoord;
in vec3 v_normal;
in vec3 fragpos;

out vec4 out_Color;

uniform sampler2D u_texture;
uniform vec3 viewpos;
uniform Material material;
uniform Light light;

// Fonction main

void main()
{
	// ambient
	vec3 ambient = light.color * material.ambient;

	// diffuse
	vec3 norm = normalize(v_normal);
	vec3 lightdirection = normalize(light.position - fragpos);
	float diff = max(dot(norm, lightdirection), 0.0);
	vec3 diffuse = light.color * (diff * material.diffuse);

	// specular
	vec3 viewDir = normalize(viewpos - fragpos);
	vec3 reflectDir = reflect(-lightdirection, norm);
	float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
	vec3 specular = light.color * (spec * material.specular);

	out_Color = vec4(ambient + diffuse + specular, 1.0) * texture(u_texture, v_texCoord);
}
