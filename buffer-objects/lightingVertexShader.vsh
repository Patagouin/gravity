#version 130

#define NB_LUMIERE 32

uniform mat4 mvpMatrix;
uniform mat4 mvMatrix;
uniform mat3 normalMatrix;
uniform vec3 lightPosition[NB_LUMIERE];
uniform vec3 absoluteLightPosition[NB_LUMIERE];

in vec4 vertex;
in vec3 normal;
in vec2 textureCoordinate;

//in vec4 centre;
//in float masse;

out vec3 varyingNormal;
out vec3 varyingLightDirection[NB_LUMIERE];
out vec3 varyingViewerDirection;
out vec2 varyingTextureCoordinate;
out float distance[NB_LUMIERE];

void main(void)
{
    vec4 eyeVertex = mvMatrix * vertex;
    eyeVertex /= eyeVertex.w;
    varyingNormal = normalMatrix * normal;
    distance = pow( pow((absoluteLightPosition.x - vertex.x), 2) + pow((absoluteLightPosition.y - vertex.y), 2) + pow((absoluteLightPosition.z - vertex.z), 2), 0.5 );
    varyingLightDirection = lightPosition - eyeVertex.xyz;
    varyingViewerDirection = -eyeVertex.xyz;
    varyingTextureCoordinate = textureCoordinate;
    gl_Position = mvpMatrix * vertex;
}
