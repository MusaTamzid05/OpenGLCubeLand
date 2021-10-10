#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D texture_id;
uniform sampler2D tex2 ;

void main()
{
    FragColor = texture(tex2,TexCoord);
}
