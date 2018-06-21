#version 330 core

out vec4 fragColor;

in vec2 texCoord;
in vec3 color;

uniform sampler2D mainTexture;

void main()
{
   fragColor =texture2D(mainTexture , texCoord) * vec4(1,1,1 , 1);// vec4(1.0f, 0.5f, 0.2f, 1.0f);
   //fragColor = vec4(color , 1);
};