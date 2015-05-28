#include "ObjetClassique.h"
#include <QMatrix4x4>

ObjetClassique::ObjetClassique()
{
}



ObjetClassique::ObjetClassique(const ObjetClassique* other)
                  : forme(QVector<QVector3D>(other->forme)),
                    normales(QVector<QVector3D>(other->normales)),
                    textureCoords(QVector<QVector2D>(other->textureCoords))

{

}

void ObjetClassique::translation(float x, float y, float z)
{
    for (int i=0; i < forme.size(); i++){
        forme[i] += QVector3D(x,y,z);
    }
}

void ObjetClassique::rotation(QVector3D axe, float angle)
{

    QMatrix4x4 mat = QMatrix4x4();
    mat.rotate(angle, axe);

    for (int i=0; i < forme.size(); i++){
        forme[i] = mat*forme[i];
    }

}


QVector<QVector3D> ObjetClassique::getForme() const
{
    return QVector<QVector3D>(forme);
}
void ObjetClassique::setForme(QVector<QVector3D> _forme)
{
    forme = QVector<QVector3D>(_forme);
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
