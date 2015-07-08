#ifndef MESLUMIERES_H
#define MESLUMIERES_H

#include <QList>
#include "Lumiere.h"

class MesLumieres
{
public:
    MesLumieres();

    void translaterLumiere(int index, float x, float y, float z);
    void rotationLumiere(int index, QVector3D axe, float angle);

    void clonerLumiere(int index);
    void ajouterLumiere(Lumiere &lum);
    void supprimerLumiere(int index);
    QList<Lumiere> lumieres;

};

#endif // MESLUMIERES_H
