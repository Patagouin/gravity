#include "MesLumieres.h"

MesLumieres::MesLumieres()
{
}

void MesLumieres::translaterLumiere(int index, float x, float y, float z)
{
    lumieres[index].translation(x, y, z);

}

void MesLumieres::rotationLumiere(int index, QVector3D axe, float angle)
{
    lumieres[index].rotation(axe, angle);
}

void MesLumieres::clonerLumiere(int index)
{
    Lumiere newLum = Lumiere(lumieres[index]);
    ajouterLumiere(newLum);
}

void MesLumieres::ajouterLumiere(Lumiere &lum)
{
    lumieres.append(lum);
}

void MesLumieres::supprimerLumiere(int index)
{
    lumieres.removeAt(index);

}
