#include "SystemeVision.h"

SystemeVision::SystemeVision(TYPE_VISION vision, QSize tailleAffichage, float imagesParSeconde) : sphere(SphereVision()), fFly(FreeFlyVision(tailleAffichage, imagesParSeconde))
{
    currentVision = vision;
    //sphere = SphereVision();
    //fFly = FreeFlyVision(tailleAffichage);
}



void SystemeVision::changerTypeVision(TYPE_VISION vision){
    currentVision = vision;
}

void SystemeVision::computeViewMatrix()
{

    switch (currentVision) {
    case freeFly:
        fFly.computeViewMatrix();
        break;
    default:
        sphere.computeViewMatrix();
        break;
    }
}

QMatrix4x4 SystemeVision::getViewMatrix()
{
    switch (currentVision) {
    case freeFly:
        return fFly.getViewMatrix();
    default:
        return sphere.getViewMatrix();
    }
}

void SystemeVision::mousePressEvent(QMouseEvent *event)
{
    switch (currentVision) {
    case freeFly:
        fFly.mousePressEvent(event);
        break;
    default:
        sphere.mousePressEvent(event);
        break;
    }

}

void SystemeVision::mouseMoveEvent(QMouseEvent *event)
{
    switch (currentVision) {
    case freeFly:
        fFly.mouseMoveEvent(event);
        break;
    default:
        sphere.mouseMoveEvent(event);
        break;
    }
}


void SystemeVision::wheelEvent(QWheelEvent *event)
{
    switch (currentVision) {
    case freeFly:
        break;
    default:
        sphere.wheelEvent(event);
        break;
    }
}

void SystemeVision::mouseReleaseEvent(QMouseEvent *event)
{
    switch (currentVision) {
    case freeFly:
        fFly.mouseReleaseEvent(event);
        break;
    default:
        break;
    }
}

