#shader vertex
#version 330 core


// Entrée Shader

layout(location = 0) in vec4 in_Vertex;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in vec3 normalCoord;

out vec2 v_texCoord;

uniform mat4 u_projection;
uniform mat4 u_view;
uniform mat4 u_model;

// Fonction main

void main()
{
	// Position finale du vertex

	gl_Position = u_projection * u_view * u_model * in_Vertex;
	v_texCoord = texCoord;
}

#shader fragment


#version 330 core


// Sortie Shader

out vec4 out_Color;
in vec2 v_texCoord;

uniform sampler2D u_texture;


// Fonction main

void main()
{
	// Couleur finale du pixel

	out_Color = texture(u_texture, v_texCoord);//texture(u_texture, v_texCoord);
}
