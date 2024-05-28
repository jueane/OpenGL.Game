#version 330 core

in vec3 fColor;
in vec2 texCoords;

uniform sampler2D tex1;

out vec4 fragColor;

void main() {
    vec4 color = texture(tex1, texCoords);
    //    fragColor = vec4(color, 1.0);
    fragColor = color;
}