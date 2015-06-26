#include "FreeFlyVision.h"
#include <QtMath>
FreeFlyVision::FreeFlyVision(QSize _tailleAffichage, float ips) : tailleAffichage(_tailleAffichage), imagesParSeconde(ips)
{
    positionCamera = QVector3D(0, 0, -1);

    timer = QElapsedTimer();

    tempsAppuie = 0;

    vitesseAvancement = 0.01;
    vitesseRotation = 0.1; // angle maximum pour tourner
    avancement = 0.0;
    angleHorizontal = 0;
    angleVertical = 0;

}


void FreeFlyVision::computeViewMatrix()
{
    if (timer.isValid()){

        tempsAppuie = timer.restart();
        angleHorizontal += (deltaMidX * (vitesseRotation*tempsAppuie/1000.0));
        angleVertical += (deltaMidY * (vitesseRotation*tempsAppuie/1000.0));

        setAnglesTorightValue();
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
//    printf("direction = (%f, %f, %f) ;\n mat = \n (%f, %f, %f, %f)\n(%f, %f, %f, %f)\n (%f, %f, %f, %f)\n(%f, %f, %f, %f)\n\n",
//           direction.x(), direction.y(), direction.z(), *mat.data(), *(mat.data()+1), *(mat.data()+2), *(mat.data()+3),
//           *(mat.data()+4), *(mat.data()+5), *(mat.data()+6), *(mat.data()+7), *(mat.data()+8), *(mat.data()+9), *(mat.data()+10),
//           *(mat.data()+11), *(mat.data()+12), *(mat.data()+13), *(mat.data()+14), *(mat.data()+15));

    direction.normalize();
    //printf("angleHorizontal = %f ; angleVertical = %f\n", angleHorizontal, angleVertical);
//    printf("positionCamera = (%f, %f, %f) ; direction = (%f, %f, %f)  \n", positionCamera.x(),
//           positionCamera.y(), positionCamera.z(), direction.x(), direction.y(), direction.z());

    viewMatrix.lookAt(positionCamera, direction + positionCamera, QVector3D(0,1,0));
}

void FreeFlyVision::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() != Qt::MidButton){
        timer.start();
        qDebug() << "je suis dans press avec button!=mid" << (event->buttons() == Qt::RightButton) << event->button();
    }
    lastMousePosition = event->pos();
    event->accept();
}

void FreeFlyVision::mouseMoveEvent(QMouseEvent *event)
{
    deltaMidX =  event->x() - (tailleAffichage.width()/2); // nb de pixel par rapport au milieu
    deltaMidY =  event->y() - (tailleAffichage.height()/2);

    if (qAbs(deltaMidX) > tailleAffichage.width()/2)
        deltaMidX = tailleAffichage.width()/2;
    else if (qAbs(deltaMidX) < -tailleAffichage.width()/2)
        deltaMidX = -tailleAffichage.width()/2;
    else if (qAbs(deltaMidY) > tailleAffichage.height()/2)
        deltaMidY = tailleAffichage.height()/2;
    else if (qAbs(deltaMidY) < -tailleAffichage.height()/2)
        deltaMidY = -tailleAffichage.height()/2;

    if (event->buttons() != Qt::MidButton){
        tempsAppuie = timer.restart();
        qDebug() << "appuie" << tempsAppuie << deltaMidX << deltaMidY;
        angleHorizontal += (deltaMidX * (vitesseRotation*tempsAppuie/1000.0));
        angleVertical += (-deltaMidY * (vitesseRotation*tempsAppuie/1000.0));



        if (event->buttons() & Qt::LeftButton)
            avancement = (vitesseAvancement * (tempsAppuie/1000.0));

        else
            avancement = (-vitesseAvancement * (tempsAppuie/1000.0));

    }

    if (event->buttons() & Qt::MidButton){
        float deltaLastPosX = lastMousePosition.x() - event->x();
        float deltaLastPosY = lastMousePosition.y() - event->y() ;

        angleHorizontal -= deltaLastPosX * vitesseRotation;
        angleVertical += deltaLastPosY * vitesseRotation;
    }

    setAnglesTorightValue();

    //printf("Apres : avancement = %f, positionCamera = (%f, %f, %f); direction = (%f, %f, %f) \n", avancement, positionCamera.x(), positionCamera.y(), positionCamera.z(),
    //       direction.x(), direction.y(), direction.z());


    lastMousePosition = event->pos();

    event->accept();
}



void FreeFlyVision::mouseReleaseEvent(QMouseEvent *event)
{


    if (event->button() == Qt::LeftButton){
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



float FreeFlyVision::getVitesseAvancement() const
{
    return vitesseAvancement;
}

void FreeFlyVision::setVitesseAvancement(float value)
{
    vitesseAvancement = value;
}

