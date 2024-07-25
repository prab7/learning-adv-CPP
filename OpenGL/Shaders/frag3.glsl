#version 410 core

in vec3 v_vertexColors;

out vec4 color;

uniform float u_Offset; // uniform variable

// Entry point of program
void main()
{
    color = vec4(v_vertexColors.r + u_Offset, v_vertexColors.g, v_vertexColors.b, 1.f);
}