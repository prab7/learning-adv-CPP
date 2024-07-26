#version 410 core

in vec3 v_vertexColors;

out vec4 color;

uniform mat4 u_ModelMatrix; // uniform model matrix

// Entry point of program
void main()
{
    vec4 newVertexColors = u_ModelMatrix * vec4(v_vertexColors, 1.0f);
    color = vec4(newVertexColors.r, newVertexColors.g, newVertexColors.b, 1.f);
}