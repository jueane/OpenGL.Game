#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;
layout (location = 3) in vec3 aNormal;


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec3 vertexColor;
out vec2 TexCoord;
out vec3 normal;

out vec3 FragPos;

void main()
{
    //    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    //    vertexColor = aColor;

    gl_Position = vec4(aPos, 1.0);
    gl_Position = projection * view * model * gl_Position;

    vertexColor = aColor;
    TexCoord = aTexCoord;
    normal = aNormal;


    FragPos = vec3(model * gl_Position);
}