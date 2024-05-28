#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoords;
layout (location = 3) in vec3 aNormal;
layout (location = 4) in vec3 aOffset;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 fColor;
out vec2 texCoords;

void main() {
    //    gl_Position = vec4(aPos + aOffset, 1.0);
    gl_Position = projection * view * vec4(aPos + aOffset, 1.0);
    fColor = aColor;
    texCoords= aTexCoords;
}