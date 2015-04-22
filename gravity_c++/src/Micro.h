#ifndef MICRO_H
#define MICRO_H

/* Cette classe définit les propiétés pour un objet (n'est pas un conteneur, le conteneur est mesObjets)*/

#include "AbstractObjet.h"
#include "ObjetClassique.h"

class Micro : public ObjetClassique
{
public:
    Micro();
    Micro(ObjetClassique objetClassique, QList<QVector3D> surfaceMicro);

    QList<QVector3D> getSurfaceMicro() const;
    void setSurfaceMicro(const QList<QVector3D> &value);

protected:

    QList<QVector3D> surfaceMicro;
};

#endif // MICRO_H
