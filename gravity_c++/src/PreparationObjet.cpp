#include "PreparationObjet.h"
#include "GLWidget.h"
#include "MesObjets.h"


PreparationObjet::PreparationObjet()
{
    objetsAbstraitsBuffer["objetsClassiques"] = objetsClassiquesBuffer;
    objetsAbstraitsBuffer["cameras"] = camerasBuffer;
    objetsAbstraitsBuffer["lampes"] = lampesBuffer;
    objetsAbstraitsBuffer["micros"] = microsBuffer;
}

void PreparationObjet::chargerObjets(QList<AbstractObjet> *objetsAbstraits)
{

    for (int i=0; i<objetsAbstraits["objetsClassiques"].count();i++){

        objetsAbstraitsBuffer["objetsClassiques"].append() = new QGLBuffer(QGLBuffer::);
    }
    int numSpotlightVertices = 18; // A changer

     spotlightBuffer.create();
     spotlightBuffer.bind();
     spotlightBuffer.allocate(numSpotlightVertices * (3 + 3) * sizeof(GLfloat));

     int offset = 0;
     cubeBuffer.write(offset, spotlightVertices.constData(), numSpotlightVertices * 3 * sizeof(GLfloat));
     offset += numSpotlightVertices * 3 * sizeof(GLfloat);
     cubeBuffer.write(offset, spotlightColors.constData(), numSpotlightVertices * 3 * sizeof(GLfloat));

     spotlightBuffer.release();
    numCubeVertices = 36; // A changer

    cubeBuffer.create();
    cubeBuffer.bind();
    cubeBuffer.allocate(numCubeVertices * (3 + 3 + 2) * sizeof(GLfloat)); // A changer

    int offset = 0;
    cubeBuffer.write(offset, cubeVertices.constData(), numCubeVertices * 3 * sizeof(GLfloat));
    offset += numCubeVertices * 3 * sizeof(GLfloat);
    cubeBuffer.write(offset, cubeNormals.constData(), numCubeVertices * 3 * sizeof(GLfloat));
    offset += numCubeVertices * 3 * sizeof(GLfloat);
    cubeBuffer.write(offset, cubeTextureCoordinates.constData(), numCubeVertices * 2 * sizeof(GLfloat));

    cubeBuffer.release();

}

