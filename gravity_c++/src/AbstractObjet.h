#ifndef ABSTRACTOBJET_H
#define ABSTRACTOBJET_H

#include <QList>
#include <QVector3D>
#include <QString>


// Cette classe pourra etre utilisé en tant que "patron" un modèle pour toutes les sous-classes qui
// seront créée par la suite
class AbstractObjet
{
public:
    AbstractObjet();
    AbstractObjet(const QString nom, const QList<QVector3D> &forme, const QList<QVector3D> &normales, const QList<QVector3D> &textureCoords, const QVector3D &position = QVector3D(0,0,0),
                  const QVector3D &orientation = QVector3D(0,0,0), double taille = 1.0, bool deplacable = true);
    AbstractObjet(const AbstractObjet* other); // Constructeur de copie



    // Setteurs et getteurs

    QString getNom() const;
    void setNom(const QString value);

    QList<QVector3D> *getForme() const;
    void setForme(QList<QVector3D> *value);

    QList<QVector3D> *getNormales() const;
    void setNormales(QList<QVector3D> *value);

    QList<QVector3D> *getTextureCoords() const;
    void setTextureCoords(QList<QVector3D> *value);

    QVector3D getPosition() const;
    void setPosition(const QVector3D &value);

    QVector3D getOrientation() const;
    void setOrientation(const QVector3D &value);

    double getTaille() const;
    void setTaille(double value);

    bool getDeplacable() const;
    void setDeplacable(bool value);

    QVector<QVector3D> getData() const;
    void setData(const QVector<QVector3D> &value);

    void makeData();

protected:
    QString* nom;

    QVector<QVector3D> data;

    QVector3D position;
    QVector3D orientation; // vecteur normé par rapport à l'origine

    double taille;
    bool deplacable;


};

#endif // ABSTRACTOBJET_H
