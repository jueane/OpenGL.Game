#version 330 core

in vec3 vertexColor;
in vec2 TexCoord;

uniform sampler2D ourTexture1;
uniform sampler2D texture2;

uniform vec3 objectColor;
uniform vec3 lightColor;

out vec4 FragColor;
void main()
{
    //        FragColor = mix(texture(ourTexture1, TexCoord), texture(texture2, TexCoord), 0.5);
    //    FragColor = objectColor * lightColor;
    //    FragColor.w=1.0f;

    float ambientStrength = 0.1;
    vec3 ambient = ambientStrength * lightColor;

    vec3 result = ambient * objectColor;
    FragColor = vec4(result, 1.0);
}