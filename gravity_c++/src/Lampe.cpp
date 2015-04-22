#include "Lampe.h"

Lampe::Lampe()
{
}

Lampe::Lampe(AbstractObjet _objetClassique, QColor _couleur[NB_LIGHT_PROPERTY], double _force[NB_LIGHT_PROPERTY],
             QList<QVector3D> _surfaceLampe, QColor _couleurVueDirecte /*= QColor(255,255,255)*/, int _tailleHalo /*=3*/ )
               : AbstractObjet(_objetClassique), surfaceLampe(QList<QVector3D>(_surfaceLampe)),
                 couleurVueDirecte(QColor(_couleurVueDirecte)), tailleHalo(_tailleHalo)
{
    for (LIGHT i = 0; i < NB_LIGHT_PROPERTY; i++){
        couleur[i] = _couleur[i];
        force[i] = _force[i];
    }

}
QColor Lampe::getCouleurAmbiante() const
{
    return couleurAmbiante;
}

void Lampe::setCouleurAmbiante(const QColor &value)
{
    couleurAmbiante = value;
}
QColor Lampe::getCouleurDiffuse() const
{
    return couleurDiffuse;
}

void Lampe::setCouleurDiffuse(const QColor &value)
{
    couleurDiffuse = value;
}
QColor Lampe::getCouleurSpecular() const
{
    return couleurSpecular;
}

void Lampe::setCouleurSpecular(const QColor &value)
{
    couleurSpecular = value;
}
double Lampe::getForceAmbiante() const
{
    return forceAmbiante;
}

void Lampe::setForceAmbiante(double value)
{
    forceAmbiante = value;
}
double Lampe::getForceDiffuse() const
{
    return forceDiffuse;
}

void Lampe::setForceDiffuse(double value)
{
    forceDiffuse = value;
}
double Lampe::getForceSpecular() const
{
    return forceSpecular;
}

void Lampe::setForceSpecular(double value)
{
    forceSpecular = value;
}
QColor Lampe::getCouleurVueDirecte() const
{
    return couleurVueDirecte;
}

void Lampe::setCouleurVueDirecte(const QColor &value)
{
    couleurVueDirecte = value;
}
double Lampe::getTailleHalo() const
{
    return tailleHalo;
}

void Lampe::setTailleHalo(double value)
{
    tailleHalo = value;
}
QList<QVector3D> Lampe::getSurfaceLampe() const
{
    return surfaceLampe;
}

void Lampe::setSurfaceLampe(const QList<QVector3D> &value)
{
    surfaceLampe = value;
}









