#ifndef MONDE_H
#define MONDE_H

#include "QPair"
#include "QVector3D"
#include "QColor"
#include "QImage"


class Monde
{
public:
    Monde();
    void fondGL();
protected:
    QColor couleurFond;
    QImage imageFond;
    QPair <double, QVector3D> gravite; //Force direction
    double brouillard; //0<brouillard<100


};

#endif // MONDE_H
