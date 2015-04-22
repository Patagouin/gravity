#include "Micro.h"

Micro::Micro()
{
}
Micro::Micro(ObjetClassique objetClassique, QList<QVector3D> surfaceMicro)
        : ObjetClassique(objetClassique), surfaceMicro(QList<QVector3D>(surfaceMicro))
{
}
QList<QVector3D> Micro::getSurfaceMicro() const
{
    return surfaceMicro;
}

void Micro::setSurfaceMicro(const QList<QVector3D> &value)
{
    surfaceMicro = value;
}

