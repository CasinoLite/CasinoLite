#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;
uniform mat4 u_ViewProj;

void main()
{
    gl_Position = u_ViewProj * vec4(aPos, 1.0);
	TexCoord = aTexCoord;
}  