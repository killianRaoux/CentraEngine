#shader vertex
#version 330 core


// Entrée Shader

layout(location = 0) in vec4 in_Vertex;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in vec2 in_normal;

out vec2 out_texCoord;
out vec3 out_normal;
out vec3 out_fragpos;

uniform mat4 uMVP;
uniform mat4 uModel;
uniform vec3 ligth_pos;

// Fonction main

void main()
{
	// Position finale du vertex

	gl_Position = uMVP * in_Vertex;
	out_fragpos = vec3(lightpos - vec3(uModel * in_Vertex));
	out_normal = normalize(in_normal);
}

#shader fragment


#version 330 core


// Sortie Shader

out vec4 out_Color;
in vec2 out_texCoord;
in vec3 out_normal;
in vec3 out_fragpos;

uniform sampler2D u_texture;


// Fonction main

void main()
{
	// Couleur finale du pixel
	vec3 norm = normalize(out_normal);
	vec3 lightDir = normilize(light
	out_Color = texture(u_texture, v_texCoord);
}
