#version 410 core

in vec3 tcolor;
out vec4 color;

void main()
{
    color = vec4(tcolor, 0.5f);
}