#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D texture_id 

void main()
{
    FragColor = mix(texture(texture_id,TexCoord), 0.2);
}
