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

enum typeObjet { sphere, quelconque};

class ObjetClassique
{

public:
    ObjetClassique(QVector3D centre, float masse, typeObjet type);


    ObjetClassique(const ObjetClassique* other );

    void translation(float x, float y, float z);
    void rotation(QVector3D axe, float angle);
    void scale(float facteur);

    void computeCenter();

    QVector3D getCentre() const;
    void setCentre(const QVector3D &value);


    QVector<QVector3D> getForme() const;
    void setForme(const QVector<QVector3D> &value);

    QVector<QVector3D> getNormales() const;
    void setNormales(const QVector<QVector3D> &value);

    QVector<QVector2D> getTextureCoords() const;
    void setTextureCoords(const QVector<QVector2D> &value);


    float getMasse() const;
    void setMasse(float value);

protected:
    QVector3D centre;
    float masse; // en kg

    QVector<QVector3D> forme;

    QVector<QVector3D> formeVertices;
    QVector<QVector3D> formeIndices;

    QVector<QVector3D> normales;
    QVector<QVector2D> textureCoords;


    typeObjet type;

};

#endif // OBJETCLASSIQUE_H
