#include "AbstractObjet.h"
#include "MesObjets.h"

AbstractObjet::AbstractObjet()
{
}

AbstractObjet::AbstractObjet(const QString nom, const QList<QVector3D> &forme, const QList<QVector3D> &normales, const QList<QVector3D> &textureCoords, const QVector3D &position /*= QVector3D(1, 1, 1)*/, const QVector3D &orientation /*= QVector3D(1, 1, 1)*/, double taille /*= 1.0*/, bool deplacable /*= true*/)

                : nom(new QString(nom)), forme(new QList<QVector3D>(forme)), normales(new QList<QVector3D>(normales)),
                  textureCoords(new QList<QVector3D>(textureCoords)), position(position),
                  orientation(orientation), taille(taille), deplacable(deplacable)
{

}

AbstractObjet::AbstractObjet(const AbstractObjet* other)
                  : nom(new QString(*other->nom)), forme(new QList<QVector3D>(*other->forme)),
                    normales(new QList<QVector3D>(*other->normales)),
                    textureCoords(new QList<QVector3D>(*other->textureCoords)),
                    position(other->position), orientation(other->orientation),
                    taille(other->taille), deplacable(other->deplacable)
{

}

    // Setteurs and getteurs

    QString AbstractObjet::getNom() const
    {
        return QString(*nom);
    }
    void AbstractObjet::setNom(const QString value)
    {
        nom = new QString(value);
    }

    QList<QVector3D> *AbstractObjet::getForme() const
    {
        return new QList<QVector3D>(*forme);
    }
    void AbstractObjet::setForme(QList<QVector3D> *forme)
    {
        forme = new QList<QVector3D>(*forme);
    }

    QList<QVector3D> *AbstractObjet::getNormales() const
    {
        return  new QList<QVector3D>(*normales);
    }
    void AbstractObjet::setNormales(QList<QVector3D> *normales)
    {
        normales = new QList<QVector3D>(*normales);
    }

    QList<QVector3D> *AbstractObjet::getTextureCoords() const
    {
        return  new QList<QVector3D>(*textureCoords);
    }
    void AbstractObjet::setTextureCoords(QList<QVector3D> *textureCoords)
    {
        textureCoords = new QList<QVector3D>(*textureCoords);
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




