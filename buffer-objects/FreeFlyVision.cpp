#include "FreeFlyVision.h"
#include <QtMath>

#define SECTOMS 1000.0
FreeFlyVision::FreeFlyVision(QSize _tailleAffichage, float ips) : tailleAffichage(_tailleAffichage), imagesParSeconde(ips)
{
    positionCamera = QVector3D(0, 0, -1);

    timer = QElapsedTimer();
    typeSouris = 0;
    tempsAppuie = 0;

    vitesseAvancement = 1.0;
    vitesseRotation = 90; // angle de rotation par seconde sur les bord
    avancement = 0.0;
    angleHorizontal = 0;
    angleVertical = 0;

}


void FreeFlyVision::computeViewMatrix()
{
    if (timer.isValid()){
        tempsAppuie = timer.restart();
        angleHorizontal -= (deltaMidX * (vitesseRotation*tempsAppuie/SECTOMS));
        angleVertical += (deltaMidY * (vitesseRotation*tempsAppuie/SECTOMS));
        setAnglesTorightValue();

        if (typeSouris == 1)
            avancement = (vitesseAvancement * (tempsAppuie/SECTOMS));
        if (typeSouris == 2)
            avancement = (-vitesseAvancement * (tempsAppuie/SECTOMS));

    }
    viewMatrix.setToIdentity();

    QVector3D direction = QVector3D(0,0,1);
    QMatrix4x4 mat;
    mat.rotate(angleHorizontal, QVector3D(0,1,0));
    mat.rotate(angleVertical, QVector3D(1,0,0));
    direction = mat*direction;
    direction.normalize();

    positionCamera += avancement * direction;
    avancement = 0.0;

    direction.normalize();


    viewMatrix.lookAt(positionCamera, direction + positionCamera, QVector3D(0,1,0));
}

void FreeFlyVision::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() != Qt::MidButton){
        timer.start();
        if (event->button() == Qt::LeftButton || event->button() == Qt::LeftButton)
            calculatePosDelta(event->x(), event->y());
        if (event->button() == Qt::LeftButton)
            typeSouris = 1;
        else if (event->button() == Qt::RightButton)
            typeSouris = 2;
        else
            typeSouris = 0;
    }

    lastMousePosition = event->pos();
    event->accept();
}

void FreeFlyVision::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton || event->buttons() == Qt::RightButton)
        calculatePosDelta(event->x(), event->y());


    if (event->buttons() == Qt::MidButton){
        float deltaLastPosX = (float) (lastMousePosition.x() - event->x()) / tailleAffichage.width();
        float deltaLastPosY = (float) (lastMousePosition.y() - event->y()) / tailleAffichage.height();
        angleHorizontal -= deltaLastPosX * vitesseRotation;
        angleVertical += deltaLastPosY * vitesseRotation;
    }

    setAnglesTorightValue();


    lastMousePosition = event->pos();
     event->accept();
}



void FreeFlyVision::mouseReleaseEvent(QMouseEvent *event)
{


    if (event->button() == Qt::LeftButton || event->button() == Qt::RightButton){
        tempsAppuie = 0;

        timer.invalidate();

    }
}


QMatrix4x4 FreeFlyVision::getViewMatrix() const
{

    return viewMatrix;
}
float FreeFlyVision::getVitesseRotation() const
{
    return vitesseRotation;
}

void FreeFlyVision::setVitesseRotation(float value)
{
    vitesseRotation = value;
}
float FreeFlyVision::getAvancement() const
{
    return avancement;
}

void FreeFlyVision::setAvancement(float value)
{
    avancement = value;
}

void FreeFlyVision::setTailleAffichage(QSize nouvelleTaille)
{
    tailleAffichage = nouvelleTaille;
}

void FreeFlyVision::setAnglesTorightValue()
{
    if (angleVertical <= -90)
        angleVertical = -89.999; // Pas 90 car on perd la notion de haut de la caméra
    if (angleVertical >= 90)
        angleVertical = 89.999;
    while (angleHorizontal > 180)
        angleHorizontal -= 360;
    while (angleHorizontal < -180)
        angleHorizontal += 360;

}

void FreeFlyVision::calculatePosDelta(int x, int y)
{
    deltaMidX =  x - (tailleAffichage.width()/2); // nb de pixel par rapport au milieu
    deltaMidY =  y - (tailleAffichage.height()/2);

    if (deltaMidX > tailleAffichage.width()/2)
        deltaMidX = tailleAffichage.width()/2;
    else if (deltaMidX < -tailleAffichage.width()/2)
        deltaMidX = -tailleAffichage.width()/2;
    else if (deltaMidY > tailleAffichage.height()/2)
        deltaMidY = tailleAffichage.height()/2;
    else if (deltaMidY < -tailleAffichage.height()/2)
        deltaMidY = -tailleAffichage.height()/2;

    deltaMidX /= tailleAffichage.width()/2;
    deltaMidY /= tailleAffichage.height()/2;
}



float FreeFlyVision::getVitesseAvancement() const
{
    return vitesseAvancement;
}

void FreeFlyVision::setVitesseAvancement(float value)
{
    vitesseAvancement = value;
}

