#shader vertex
#version 330 core


// Entrée Shader

layout(location = 0) in vec4 in_Vertex;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in vec3 normalCoord;

out vec2 v_texCoord;
out vec3 v_normal;
out float v_ambient;

uniform mat4 u_projection;
uniform mat4 u_view;
uniform mat4 u_model;
float ambient = 0.5;
float speculat = 0.5;



// Fonction main

void main()
{
	// Position finale du vertex

	gl_Position = u_projection * u_view * u_model * in_Vertex;
	v_texCoord = texCoord;
	v_normal = normalCoord;
}

#shader fragment
#version 330 core


// Sortie Shader

in vec2 v_texCoord;
in vec3 v_normal;
in float v_ambient;
out vec4 out_Color;

uniform sampler2D u_texture;


// Fonction main

void main()
{
	// Couleur finale du pixel
	vec3 ambient = v_ambient * vec3(1.0, 1.0, 0.2);

	vec4 result = vec4(ambient,1.0) * texture(u_texture, v_texCoord);
	out_Color = result;
}
