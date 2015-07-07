#ifndef UTILSGL_H
#define UTILSGL_H

#include <QVector>
#include <QVector3D>

// Calcule les normales  pour chaques vertices de chaques faces, les données de dstNormales seront supprimées
void calculateNormales(QVector<QVector3D> vertices, QVector<QVector3D> &dstNormales);

#endif // UTILSGL_H
