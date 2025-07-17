#version 410 core

in vec3 vcolor;

out vec4 color;

void main()
{
    color = vec4(vcolor.r, vcolor.g, vcolor.b, 1.0f);
}