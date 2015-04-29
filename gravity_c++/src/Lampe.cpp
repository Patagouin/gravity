#include "Lampe.h"

Lampe::Lampe()
{
}

Lampe::Lampe(ObjetClassique _objetClassique, QColor _couleur[NB_LIGHT_PROPERTY], double _force[NB_LIGHT_PROPERTY],
             QColor _couleurVueDirecte /*= QColor(255,255,255)*/, int _tailleHalo /*=3*/ )
               : ObjetClassique(_objetClassique), couleurVueDirecte(QColor(_couleurVueDirecte)), tailleHalo(_tailleHalo)
{
    for (int i = 0; i < NB_LIGHT_PROPERTY; i++){
        couleur[i] = _couleur[i];
        force[i] = _force[i];
    }

}
QColor Lampe::getCouleurAmbiante() const
{
    return couleur[AMBIANTE];
}

void Lampe::setCouleurAmbiante(const QColor &value)
{
    couleur[AMBIANTE] = value;
}
QColor Lampe::getCouleurDiffuse() const
{
    return couleur[DIFFUSE];
}

void Lampe::setCouleurDiffuse(const QColor &value)
{
    couleur[DIFFUSE] = value;
}
QColor Lampe::getCouleurSpecular() const
{
    return couleur[SPECULAR];
}

void Lampe::setCouleurSpecular(const QColor &value)
{
    couleur[SPECULAR] = value;
}
double Lampe::getForceAmbiante() const
{
    return force[AMBIANTE];
}

void Lampe::setForceAmbiante(double value)
{
    force[AMBIANTE] = value;
}
double Lampe::getForceDiffuse() const
{
    return force[DIFFUSE];
}

void Lampe::setForceDiffuse(double value)
{
    force[DIFFUSE] = value;
}
double Lampe::getForceSpecular() const
{
    return force[SPECULAR];
}

void Lampe::setForceSpecular(double value)
{
    force[SPECULAR] = value;
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









