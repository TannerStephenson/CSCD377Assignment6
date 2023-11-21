#version 430 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 normal;

uniform mat4 model_matrix;
uniform mat4 view_matrix;
uniform mat4 projection_matrix;

uniform vec3 Ambient;
uniform vec3 LightColor;
uniform vec3 LightPosition;

uniform float Shininess;
uniform vec3 MaterialColor;

out vec4 color;
vec4 eyeSpacePosition;
vec3 eyeSpaceNormal;


void main(void)
{

	eyeSpacePosition = view_matrix*model_matrix*position;
	eyeSpaceNormal = normalize(vec3(view_matrix*model_matrix*normal));

	vec3 N = normalize(eyeSpaceNormal); 
	vec3 L = normalize(LightPosition.xyz-eyeSpacePosition.xyz);
	vec3 diffuse = LightColor* (max(dot(L,N), 0.0));
 

	vec4 scatteredLight = vec4((Ambient+diffuse)*vec3(color), 1.0);
	
	color = min(vec4(MaterialColor*Ambient, 1.0), vec4(1.0));

	gl_Position = projection_matrix*view_matrix*model_matrix*position;

}

