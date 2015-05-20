#include "PreparationObjet.h"
#include "GLWidget.h"
#include "MesObjets.h"
#include <iostream>

PreparationObjet::PreparationObjet() : programsCourant(new QGLShaderProgram())
{
    objetsAbstraitsBuffer[OBJETCLASSIQUE] = objetsClassiquesBuffer;
    objetsAbstraitsBuffer[CAMERA] = camerasBuffer;
    objetsAbstraitsBuffer[LAMPE] = lampesBuffer;
    objetsAbstraitsBuffer[MICRO] = microsBuffer;
//    bool test = true;
//    test = programsCourant->addShaderFromSourceCode(QGLShader::Vertex, ":/vertex.fsh");
//    programsCourant->addShaderFromSourceFile(QGLShader::Fragment, ":/fragment.fsh");
//    qDebug() << programsCourant->log();

//    programsCourant->link();
    
    
}

void PreparationObjet::chargerObjets(QList<AbstractObjet> &newObjetsClassiques)
{

    for (int i=0; i<newObjetsClassiques.size();i++){

        objetsAbstraitsBuffer[OBJETCLASSIQUE].append(QGLBuffer());
        objetsAbstraitsBuffer[OBJETCLASSIQUE].last().create();
        objetsAbstraitsBuffer[OBJETCLASSIQUE].last().bind();
        objetsAbstraitsBuffer[OBJETCLASSIQUE].last().allocate(3 * newObjetsClassiques.at(i).getForme().size() * sizeof(GLfloat));
        objetsAbstraitsBuffer[OBJETCLASSIQUE].last().write(0, newObjetsClassiques.at(i).getForme().constData(), newObjetsClassiques.at(i).getForme().size() * 3 * sizeof(GLfloat));
        objetsAbstraitsBuffer[OBJETCLASSIQUE].last().release();


        // Rajouter si on veut des textures
    }


}

