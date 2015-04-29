#ifndef ABSTRACTOBJET_H
#define ABSTRACTOBJET_H

#include <QList>
#include <QVector>
#include <QVector2D>
#include <QVector3D>
#include <QString>


// Cette classe pourra etre utilisé en tant que "patron" un modèle pour toutes les sous-classes qui
// seront créée par la suite
class AbstractObjet
{
public:
    AbstractObjet();
    AbstractObjet(const QString nom, const QVector<QVector3D> &forme, const QVector<QVector3D> &normales,
                  const QVector<QVector2D> &textureCoords, const QVector3D &position = QVector3D(0,0,0),
                  const QVector3D &orientation = QVector3D(0,0,0), double taille = 1.0, bool deplacable = true);
    AbstractObjet(const AbstractObjet* other); // Constructeur de copie



    // Setteurs et getteurs

    QString getNom() const;
    void setNom(const QString value);

    QVector<QVector3D> getForme() const;
    void setForme(QVector<QVector3D> value);

    QVector<QVector3D> getNormales() const;
    void setNormales(QVector<QVector3D> value);

    QVector<QVector2D> getTextureCoords() const;
    void setTextureCoords(QVector<QVector3D> value);

    QVector3D getPosition() const;
    void setPosition(const QVector3D &value);

    QVector3D getOrientation() const;
    void setOrientation(const QVector3D &value);

    double getTaille() const;
    void setTaille(double value);

    bool getDeplacable() const;
    void setDeplacable(bool value);



protected:
    QString nom;

    QVector<QVector3D> forme;
    QVector<QVector3D> normales;
    QVector<QVector2D> textureCoords;

    QVector3D position;
    QVector3D orientation; // vecteur normé par rapport à l'origine

    double taille;
    bool deplacable;


};

#endif // ABSTRACTOBJET_H
