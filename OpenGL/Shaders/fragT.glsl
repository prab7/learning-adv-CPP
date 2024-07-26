#version 410 core

in vec3 v_vertexColors;

out vec4 color;

uniform mat4 u_ModelMatrix; // uniform model matrix
uniform mat4 u_Perspective; // uniform perpective matrix

// Entry point of program
void main()
{
    vec4 newVertexColors = vec4(v_vertexColors, 1.0f);
    color = newVertexColors;
}