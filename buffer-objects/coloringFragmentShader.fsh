#version 430


shared float weight;

in vec4 varyingColor;

out vec4 fragColor;

void main(void)
{
    fragColor = varyingColor;
}
