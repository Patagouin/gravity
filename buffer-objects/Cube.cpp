#include "Cube.h"


Cube::Cube(QVector3D _centre, float _tailleCote, float _masse) :
    ObjetClassique(_centre, _masse, quelconque), tailleCote(_tailleCote){

    float pos_Z = centre.z() - _tailleCote/2;
    float posZ = centre.z() + _tailleCote/2;
    float pos_Y = centre.y() - _tailleCote/2;
    float posY = centre.y() + _tailleCote/2;
    float pos_X = centre.x() - _tailleCote/2;
    float posX = centre.x() + _tailleCote/2;

//    cubeVertices << QVector3D( pos_X, pos_Y, pos_Z) << QVector3D( pos_X, pos_Y, posZ) << QVector3D( pos_X, posY, pos_Z)
//                 << QVector3D( pos_X, posY, posZ)   << QVector3D( posX, pos_Y, pos_Z) << QVector3D( posX, pos_Y, posZ)
//                 << QVector3D( posX, posY, pos_Z)   << QVector3D( posX, posY, posZ);

//    QVector<> cubeIndices;


    QVector<QVector3D> cubeVertices;


    cubeVertices << QVector3D( pos_X, pos_Y, posZ) << QVector3D( posX, pos_Y, posZ) << QVector3D( posX, posY, posZ) // Front
                 << QVector3D( posX, posY, posZ) << QVector3D( pos_X, posY, posZ) << QVector3D( pos_X, pos_Y, posZ)
                 << QVector3D( posX, pos_Y, pos_Z) << QVector3D( pos_X, pos_Y, pos_Z) << QVector3D( pos_X, posY, pos_Z) // Back
                 << QVector3D( pos_X, posY, pos_Z) << QVector3D( posX, posY, pos_Z) << QVector3D( posX, pos_Y, pos_Z)
                 << QVector3D( pos_X, pos_Y, pos_Z) << QVector3D( pos_X, pos_Y, posZ) << QVector3D( pos_X, posY, posZ) // Left
                 << QVector3D( pos_X, posY, posZ) << QVector3D( pos_X, posY, pos_Z) << QVector3D( pos_X, pos_Y, pos_Z)
                 << QVector3D( posX, pos_Y, posZ) << QVector3D( posX, pos_Y, pos_Z) << QVector3D( posX, posY, pos_Z) // Right
                 << QVector3D( posX, posY, pos_Z) << QVector3D( posX, posY, posZ) << QVector3D( posX, pos_Y, posZ)
                 << QVector3D( pos_X, posY, posZ) << QVector3D( posX, posY, posZ) << QVector3D( posX, posY, pos_Z) // Top
                 << QVector3D( posX, posY, pos_Z) << QVector3D( pos_X, posY, pos_Z) << QVector3D( pos_X, posY, posZ)
                 << QVector3D( pos_X, pos_Y, pos_Z) << QVector3D( posX, pos_Y, pos_Z) << QVector3D( posX, pos_Y, posZ) // Bottom
                 << QVector3D( posX, pos_Y, posZ) << QVector3D( pos_X, pos_Y, posZ) << QVector3D( pos_X, pos_Y, pos_Z);

//    QVector<QVector2D> cubeTextureCoordinates;
//    cubeTextureCoordinates << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Front
//                           << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
//                           << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Back
//                           << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
//                           << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Left
//                           << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
//                           << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Right
//                           << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
//                           << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Top
//                           << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
//                           << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Bottom
//                           << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0);

    setForme(cubeVertices);
//    setTextureCoords(cubeTextureCoordinates);
}
