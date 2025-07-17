#version 410 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 aColor;

out vec3 tcolor;

void main()
{
    gl_Position = vec4(position.x, position.y, position.z, 1.0f);
    tcolor = vec3(aColor.r, aColor.g, aColor.b);
}