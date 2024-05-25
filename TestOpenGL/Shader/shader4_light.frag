#version 330 core

in vec3 vertexColor;
in vec2 TexCoord;
in vec3 normal;
in vec3 FragPos;

uniform sampler2D ourTexture1;
uniform sampler2D texture2;

uniform vec3 lightPos;

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

//    vec3 result = ambient * objectColor;
//    FragColor = vec4(result, 1.0);

    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;
    vec3 result = (ambient + diffuse) * objectColor;
    FragColor = vec4(result, 1.0);
}