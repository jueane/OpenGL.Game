#version 330 core

in vec3 vertexColor;
in vec2 TexCoord;

uniform sampler2D ourTexture1;
uniform sampler2D texture2;

out vec4 FragColor;
void main()
{
    //    FragColor = texture(ourTexture1, TexCoord);
    //    FragColor = texture(texture2, TexCoord);
    FragColor = mix(texture(ourTexture1, TexCoord), texture(texture2, TexCoord), 0.5);
    //    FragColor = texture(ourTexture1, TexCoord) * vec4(vertexColor, 1.0);
}