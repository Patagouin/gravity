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

void PreparationObjet::chargerObjets(QList<AbstractObjet> *newObjetsAbstraits)
{

    for (int i=0; i<newObjetsAbstraits["objetsClassiques"].size();i++){

        objetsAbstraitsBuffer["objetsClassiques"].append() = QGLBuffer();
        objetsAbstraitsBuffer["ObjetsClassiques"].last().create();
        objetsAbstraitsBuffer["ObjetsClassiques"].last().bind();
        objetsAbstraitsBuffer["ObjetsClassiques"].last().allocate(3 * newObjetsAbstraits->at(i).getData().constData() * sizeof(GLdouble));
        objetsAbstraitsBuffer["ObjetsClassiques"].last().write(0, newObjetsAbstraits->at(i).getData().constData(), newObjetsAbstraits->at(i).getData().size() * 3 * sizeof(GLdouble));
        objetsAbstraitsBuffer["ObjetsClassiques"].last().release();
        // Rajouter si on veut des textures
    }


}

