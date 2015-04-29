#include "AbstractObjet.h"
#include "MesObjets.h"

AbstractObjet::AbstractObjet()
{
}

AbstractObjet::AbstractObjet(const QString _nom, const QVector<QVector3D> &_forme, const QVector<QVector3D> &_normales,
                             const QVector<QVector2D> &_textureCoords, const QVector3D &_position /*= QVector3D(1, 1, 1)*/,
                             const QVector3D &_orientation /*= QVector3D(1, 1, 1)*/, double _taille /*= 1.0*/,
                             bool _deplacable /*= true*/)

                : nom(QString(_nom)), forme(QVector<QVector3D>(_forme)), normales(QVector<QVector3D>(_normales)),
                  textureCoords(QVector<QVector2D>(_textureCoords)), position(_position),
                  orientation(_orientation), taille(_taille), deplacable(_deplacable)
{

}

AbstractObjet::AbstractObjet(const AbstractObjet* other)
                  : nom(QString(other->nom)), forme(QVector<QVector3D>(other->forme)),
                    normales(QVector<QVector3D>(other->normales)),
                    textureCoords(QVector<QVector2D>(other->textureCoords)),
                    position(other->position), orientation(other->orientation),
                    taille(other->taille), deplacable(other->deplacable)
{

}

// Setteurs and getteurs

QString AbstractObjet::getNom() const
{
    return QString(nom);
}
void AbstractObjet::setNom(const QString value)
{
    nom = QString(value);
}

QVector<QVector3D> AbstractObjet::getForme() const
{
    return QVector<QVector3D>(forme);
}
void AbstractObjet::setForme(QVector<QVector3D> forme)
{
    forme = QVector<QVector3D>(forme);
}

QVector<QVector3D> AbstractObjet::getNormales() const
{
    return  QVector<QVector3D>(normales);
}
void AbstractObjet::setNormales(QVector<QVector3D> normales)
{
    normales = QVector<QVector3D>(normales);
}

QVector<QVector2D> AbstractObjet::getTextureCoords() const
{
    return QVector<QVector2D>(textureCoords);
}
void AbstractObjet::setTextureCoords(QVector<QVector3D> textureCoords)
{
    textureCoords = QVector<QVector3D>(textureCoords);
}

QVector3D AbstractObjet::getPosition() const
{
    return position;
}
void AbstractObjet::setPosition(const QVector3D &pos)
{
    position = pos;
}

QVector3D AbstractObjet::getOrientation() const
{
    return orientation;
}
void AbstractObjet::setOrientation(const QVector3D &value)
{
    orientation = value;
}

double AbstractObjet::getTaille() const
{
    return taille;
}
void AbstractObjet::setTaille(double value)
{
    taille = value;
}
bool AbstractObjet::getDeplacable() const
{
    return deplacable;
}

void AbstractObjet::setDeplacable(bool value)
{
    deplacable = value;
}


    
    
    
    
    
