#version 410 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 aColor;

out vec3 vcolor;

void main()
{ 
    gl_Position = vec4(position.x-0.2f, position.y, position.z, 1.0f);
    vcolor = vec3(aColor);
}