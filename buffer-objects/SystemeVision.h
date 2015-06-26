#ifndef SYSTEMEVISION_H
#define SYSTEMEVISION_H

#include "SphereVision.h"
#include "FreeFlyVision.h"
#include <QSize>

enum TYPE_VISION {spherique, freeFly};

class SystemeVision
{
public:
    SystemeVision(TYPE_VISION vision, QSize tailleAffichage, float imagesParSeconde);

    void changerTypeVision(TYPE_VISION vision);
    TYPE_VISION currentVision;

    SphereVision sphere;
    FreeFlyVision fFly;

    void computeViewMatrix();

    QMatrix4x4 getViewMatrix();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);



};

#endif // SYSTEMEVISION_H
