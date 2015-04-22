#ifndef LAMPE_H
#define LAMPE_H

/* Cette classe définit les propiétés pour un objet (n'est pas un conteneur, le conteneur est mesObjets)*/

#include "AbstractObjet.h"
#include <QColor>

#define NB_LIGHT_PROPERTY 3

enum LIGHT {AMBIANTE, DIFFUSE, SPECULAR};

class Lampe : public AbstractObjet
{
public:
    Lampe();
    Lampe(AbstractObjet objetClassique, QColor couleur[NB_LIGHT_PROPERTY], double force[NB_LIGHT_PROPERTY],
          QList<QVector3D> surfaceLampe, QColor couleurVueDirecte = QColor(255,255,255), int tailleHalo = 3);

    QColor getCouleurAmbiante() const;
    void setCouleurAmbiante(const QColor &value);

    QColor getCouleurDiffuse() const;
    void setCouleurDiffuse(const QColor &value);

    QColor getCouleurSpecular() const;
    void setCouleurSpecular(const QColor &value);

    double getForceAmbiante() const;
    void setForceAmbiante(double value);

    double getForceDiffuse() const;
    void setForceDiffuse(double value);

    double getForceSpecular() const;
    void setForceSpecular(double value);

    QColor getCouleurVueDirecte() const;
    void setCouleurVueDirecte(const QColor &value);

    double getTailleHalo() const;
    void setTailleHalo(double value);

    QList<QVector3D> getSurfaceLampe() const;
    void setSurfaceLampe(const QList<QVector3D> &value);

private:

    QColor couleur[NB_LIGHT_PROPERTY];
    double force[NB_LIGHT_PROPERTY];

    QList<QVector3D> surfaceLampe;

    // Variables membres qui ont une valeur par défaut dans le constructeur
    QColor couleurVueDirecte;
    double tailleHalo; // Proportionnelle à la taille de la surface lumineuse
};

#endif // LAMPE_H
