#include "ObjetClassique.h"
#include <QMatrix4x4>

ObjetClassique::ObjetClassique(QVector3D _centre, float _masse, typeObjet _type) :
    centre(_centre), masse(_masse), type(_type)
{
}



ObjetClassique::ObjetClassique(const ObjetClassique* other)
                  : forme(QVector<QVector3D>(other->forme)),
                    normales(QVector<QVector3D>(other->normales)),
                    textureCoords(QVector<QVector2D>(other->textureCoords)),
                    centre(other->centre), masse(other->masse), type(other->type)

{

}

void ObjetClassique::translation(float x, float y, float z)
{
    for (int i=0; i < forme.size(); i++){
        forme[i] += QVector3D(x,y,z);
    }

    centre += QVector3D(x,y,z);
}

void ObjetClassique::rotation(QVector3D axe, float angle)
{

    QMatrix4x4 mat = QMatrix4x4();
    mat.rotate(angle, axe);

    for (int i=0; i < forme.size(); i++){
        forme[i] = mat*forme[i];
    }

    // rotation du centre
    centre = mat*centre;

}

void ObjetClassique::scale(float facteur)
{
    for (int i=0; i < forme.size(); i++){
        forme[i] += (forme[i] - centre) * facteur;

    }
}

void ObjetClassique::computeCenter()
{
    QVector3D tmp;
    for (int i=0; i < forme.size(); i++){
        tmp += forme[i];
    }
    tmp /= forme.size();

    centre = tmp;
}


QVector3D ObjetClassique::getCentre() const
{
    return centre;
}
void ObjetClassique::setCentre(const QVector3D &value)
{
    centre = value;
}



QVector<QVector3D> ObjetClassique::getForme() const
{
    return forme;
}
void ObjetClassique::setForme(const QVector<QVector3D> &_forme)
{
    forme = _forme;
    computeCenter();
}

QVector<QVector3D> ObjetClassique::getNormales() const
{
    return  normales;
}
void ObjetClassique::setNormales(const QVector<QVector3D> &_normales)
{
    normales = _normales;
}

QVector<QVector2D> ObjetClassique::getTextureCoords() const
{
    return textureCoords;
}
void ObjetClassique::setTextureCoords(const QVector<QVector2D> &_textureCoords)
{
    textureCoords = _textureCoords;
}
float ObjetClassique::getMasse() const
{
    return masse;
}

void ObjetClassique::setMasse(float value)
{
    masse = value;
}


