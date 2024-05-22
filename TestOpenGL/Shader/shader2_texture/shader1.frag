#version 330 core

in vec3 vertexColor;
in vec2 TexCoord;

uniform sampler2D ourTexture1;

out vec4 FragColor;
void main()
{
//       FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
    //    FragColor = vec4(vertexColor, 1);

    FragColor = texture(ourTexture1, TexCoord);

//    FragColor = texture(ourTexture1, TexCoord) * vec4(vertexColor, 1.0);
}