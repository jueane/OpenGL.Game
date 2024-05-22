#version 330 core

in vec3 vertexColor;
in vec2 TexCoord;

//uniform sampler2D ourTexture;

out vec4 FragColor;
void main()
{
       FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
    //    FragColor = vec4(vertexColor, 1);

//    FragColor = texture(ourTexture, TexCoord);

//    FragColor = texture(ourTexture, TexCoord) * vec4(ourColor, 1.0);
}