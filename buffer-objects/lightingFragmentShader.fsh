#version 130

#define NB_LUMIERE 32

uniform vec4 ambientColor[NB_LUMIERE];
uniform vec4 diffuseColor[NB_LUMIERE];
uniform vec4 specularColor[NB_LUMIERE];

uniform float shininess;
uniform sampler2D texture;

in vec3 varyingNormal;
in vec3 varyingLightDirection[NB_LUMIERE];
in vec3 varyingViewerDirection;
in vec2 varyingTextureCoordinate;
in float distance[NB_LUMIERE];

out vec4 fragColor;

void main(void)
{
    vec3 normal = normalize(varyingNormal);
    vec3 lightDirection = normalize(varyingLightDirection);
    vec3 viewerDirection = normalize(varyingViewerDirection);
    vec4 ambientIllumination = ambientColor;
    vec4 diffuseIllumination =  max(0.0, dot(lightDirection, normal)) * diffuseColor * (1/distance);
    vec4 specularIllumination =  pow(max(0.0, dot(-reflect(lightDirection, normal), viewerDirection)), shininess) * specularColor;
    fragColor = texture2D(texture, varyingTextureCoordinate) * (ambientIllumination + diffuseIllumination) + specularIllumination;
}
