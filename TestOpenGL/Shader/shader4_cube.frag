#version 330 core

struct Material {
    sampler2D diffuse;
    //    vec3 ambient;
    //    vec3 diffuse;
    //    vec3 specular;
    sampler2D specular;
    float shininess;
};

struct Light {
    vec3 postion;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};


in vec3 Normal;
in vec3 FragPos;
in vec2 texCoords;


uniform vec3 lightPos;
uniform vec3 viewPos;

uniform Material material;

uniform Light light;

out vec4 FragColor;

void main()
{
    // 环境光
    vec3 ambient = light.ambient * vec3(texture(material.diffuse, texCoords));

    // 漫反射
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, texCoords));

    // 镜面光
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * (spec * vec3(texture(material.specular, texCoords)));

    FragColor = vec4(ambient + diffuse + specular, 1.0);
}
