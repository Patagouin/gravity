#include "Lumiere.h"
#include "QMatrix4x4"


Lumiere::Lumiere(QVector3D _centre, QColor _speculaire, QColor _diffuse, QColor _ambiant, float _intensite)
                : centre(_centre)
{
    couleur[Speculaire] = _speculaire;
    couleur[Diffuse] = _diffuse;
    couleur[Ambiant] = _ambiant;

    intensite = _intensite;
}


Lumiere::Lumiere(const Lumiere *other) : centre(other->centre),
    intensite(other->intensite)
{
    couleur[Speculaire] = other->couleur[Speculaire];
    couleur[Diffuse] = other->couleur[Diffuse];
    couleur[Ambiant] = other->couleur[Ambiant];
}

void Lumiere::translation(float x, float y, float z)
{
    centre += QVector3D(x,y,z);
}

void Lumiere::rotation(QVector3D axe, float angle)
{
    QMatrix4x4 mat = QMatrix4x4();
    mat.rotate(angle, axe);

    // rotation du centre
    centre = mat*centre;
}
