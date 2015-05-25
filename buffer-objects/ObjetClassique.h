/* Cette classe définit les propiétés pour un objet (n'est pas un conteneur, le conteneur est mesObjets)*/


#ifndef OBJETCLASSIQUE_H
#define OBJETCLASSIQUE_H


#include <QList>
#include <QVector>
#include <QVector2D>
#include <QVector3D>
#include <QString>



// Cette classe pourra etre utilisé en tant que "patron" un modèle pour toutes les sous-classes qui
// seront créée par la suite

class ObjetClassique
{

public:
    ObjetClassique();


    ObjetClassique(const ObjetClassique* other );

    void translation(float x, float y, float z);

    QVector<QVector3D> getForme() const;
    void setForme(QVector<QVector3D> value);

    QVector<QVector3D> getNormales() const;
    void setNormales(QVector<QVector3D> value);

    QVector<QVector2D> getTextureCoords() const;
    void setTextureCoords(QVector<QVector2D> value);

protected:

    QVector<QVector3D> forme;
    QVector<QVector3D> normales;
    QVector<QVector2D> textureCoords;

};

#endif // OBJETCLASSIQUE_H
