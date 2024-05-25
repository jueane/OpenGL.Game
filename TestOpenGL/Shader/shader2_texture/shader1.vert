#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform mat4 transform;

out vec3 vertexColor;
out vec2 TexCoord;
void main()
{
    //    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    //    vertexColor = aColor;

    gl_Position = vec4(aPos, 1.0);

    gl_Position = projection * view * model * transform * gl_Position;

    vertexColor = aColor;
    TexCoord = aTexCoord;
}