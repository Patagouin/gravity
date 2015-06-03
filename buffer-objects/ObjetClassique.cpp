#include "ObjetClassique.h"
#include <QMatrix4x4>

ObjetClassique::ObjetClassique()
{
}



ObjetClassique::ObjetClassique(const ObjetClassique* other)
                  : forme(QVector<QVector3D>(other->forme)),
                    normales(QVector<QVector3D>(other->normales)),
                    textureCoords(QVector<QVector2D>(other->textureCoords)),
                    centre(other->centre)

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


QVector<QVector3D> ObjetClassique::getForme() const
{
    return QVector<QVector3D>(forme);
}
void ObjetClassique::setForme(QVector<QVector3D> _forme)
{
    forme = QVector<QVector3D>(_forme);
    computeCenter();
}

QVector<QVector3D> ObjetClassique::getNormales() const
{
    return  QVector<QVector3D>(normales);
}
void ObjetClassique::setNormales(QVector<QVector3D> _normales)
{
    normales = QVector<QVector3D>(_normales);
}

QVector<QVector2D> ObjetClassique::getTextureCoords() const
{
    return QVector<QVector2D>(textureCoords);
}
void ObjetClassique::setTextureCoords(QVector<QVector2D> _textureCoords)
{
    textureCoords = QVector<QVector2D>(_textureCoords);
}


QVector3D ObjetClassique::getCentre() const
{
    return centre;
}
void ObjetClassique::setCentre(const QVector3D &value)
{
    centre = value;
}

