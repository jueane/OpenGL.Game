#version 330 core

in vec3 fColor;
in vec2 texCoords;

uniform sampler2D tex1;
uniform sampler2D normalTex;

out vec4 fragColor;

void main() {
    vec4 color = texture(tex1, texCoords);
    fragColor = color;
}