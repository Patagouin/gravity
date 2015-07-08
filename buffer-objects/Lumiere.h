#ifndef LUMIERE_H
#define LUMIERE_H

#define NB_TYPE_LIGHT 3 // Speculaire, diffuse, ambiente

#include <QVector3D>
#include <QColor>

enum TypeLight { Speculaire, Diffuse, Ambiant };

class Lumiere
{
public:
    Lumiere(QVector3D centre = QVector3D(0,0,0), QColor speculaire = QColor(255,255,255),
            QColor diffuse = QColor(255,255,255), QColor ambiant = QColor(255,255,255), float intensite = 1);

    Lumiere(const Lumiere* other);

    void translation(float x, float y, float z);
    void rotation(QVector3D axe, float angle);

protected:
    QVector3D centre;
    QColor couleur[NB_TYPE_LIGHT]; // [ Speculaire, Diffuse, Ambiente ]

    float intensite; // Perte de l'energie lumineuse avec la distance


};

#endif // LUMIERE_H
