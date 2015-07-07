#ifndef CUBE_H
#define CUBE_H

#include "ObjetClassique.h"

class Cube : public ObjetClassique
{
public:

    Cube(QVector3D _centre = QVector3D(0,0,0), float _tailleCote = 1, float masse = 1);

protected:

    float tailleCote;




};

#endif // CUBE_H
