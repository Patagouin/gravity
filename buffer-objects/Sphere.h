#ifndef SPHERE_H
#define SPHERE_H

#include "ObjetClassique.h"

enum TypeSphere { UV, Icosphere};
class Sphere : public ObjetClassique
{
public:
    // tester deux constructeurs != ex UV vs ICO avec tous leurs parametres optionnel
    // pour voir lequel est appelé
    Sphere(QVector3D centre, float rayon, int nbParallele, int nbMeridian, float masse);
    Sphere(QVector3D centre = QVector3D(0,0,0), float rayon = 1, int nbSubdivision = 2, float masse = 1);

    TypeSphere type;

private:

    float rayon;


};

#endif // SPHERE_H
