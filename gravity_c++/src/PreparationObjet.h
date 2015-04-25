#ifndef PREPARATIONOBJET_H
#define PREPARATIONOBJET_H

#include "MesObjets.h"
/* Cette classe fait le lien entre les vertices stocké dans ma classe MesObjets et GLWIDGETS
 qui utilise les buffer qui sont envoyés à la carte graphique*/

#include <QGLBuffer>
#include <QGLShaderProgram>
#include <QList>
#include <QPair>

//typedef QPair<bool, QGLBuffer> GLBuffer; // Ajout d'un élément pour savoir si l'objet est deja bufferisé
class PreparationObjet
{
public:
    PreparationObjet();
    void chargerObjets(QList<AbstractObjet> objetClassique); // Ajoute shaders


    QMatrix4x4 getMatriceProjection();

private:
    QMatrix4x4 pMatrix;
    //QGLShaderProgram lightingShaderProgram;
    //! [2]
    QHash <QString, QList<GLBuffer > objetsAbstraitsBuffer; // typedef QPair<bool, QGLBuffer> GLBuffer;
    QList <QGLBuffer> objetsClassiquesBuffer;
    QList <QGLBuffer> lampesBuffer;
    QList <QGLBuffer> camerasBuffer;
    QList <QGLBuffer> microsBuffer;
    //! [2]
    GLuint cubeTexture;
    //QGLShaderProgram coloringShaderProgram;
    //! [3]

};

#endif // PREPARATIONOBJET_H
