#include "FreeFlyVision.h"
#include <QtMath>
FreeFlyVision::FreeFlyVision(QSize _tailleAffichage, float ips) : tailleAffichage(_tailleAffichage), imagesParSeconde(ips)
{
    positionCamera = QVector3D(0, 0, -1);

    vitesseAvancement = 0.01;
    vitesseRotation = 0.1; // angle maximum pour tourner
    avancement = 0.0;
    angleHorizontal = 0;
    angleVertical = 0;

}


void FreeFlyVision::computeViewMatrix()
{

    viewMatrix.setToIdentity();

//    QVector3D cameraUpDirection;
//    QMatrix4x4 mat;
//    mat.rotate(-90, QVector3D(1,0,0));
//    cameraUpDirection = mat*direction;
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

    lastMousePosition = event->pos();
    event->accept();
}

void FreeFlyVision::mouseMoveEvent(QMouseEvent *event)
{
    float deltaMidX =  (tailleAffichage.width()/2) - event->x(); // nb de pixel par rapport au milieu
    float deltaMidY = -(tailleAffichage.height()/2) - event->y();

    float deltaLastPosX = lastMousePosition.x() - event->x();
    float deltaLastPosY = lastMousePosition.y() - event->y() ;
    if (event->buttons() != Qt::MidButton){
        angleHorizontal += (deltaMidX * vitesseRotation)/100;
        angleVertical += (deltaMidY * vitesseRotation)/100;
        //printf("ok1\n");

        if (event->buttons() & Qt::LeftButton) {
            avancement = vitesseAvancement;
            //printf("ok1\n");
        }
        else{
            avancement = -vitesseAvancement;
            //printf("ok1b\n");


        }
    }
    else if (event->buttons() & Qt::MidButton){
        angleHorizontal += deltaLastPosX * vitesseRotation;
        angleVertical += deltaLastPosY * vitesseRotation;

    }
    //printf("avancement = %f, angleHorizontal = %f , angleVertical = %f \n", avancement, angleHorizontal, angleVertical);

    if (angleVertical <= -90)
        angleVertical = -90;
    if (angleVertical >= 90)
        angleVertical = 90;
    while (angleHorizontal > 180)
        angleHorizontal -= 360;
    while (angleHorizontal < -180)
        angleVertical += 360;


    //printf("Apres : avancement = %f, positionCamera = (%f, %f, %f); direction = (%f, %f, %f) \n", avancement, positionCamera.x(), positionCamera.y(), positionCamera.z(),
    //       direction.x(), direction.y(), direction.z());


    lastMousePosition = event->pos();

    event->accept();
}


void FreeFlyVision::wheelEvent(QWheelEvent *event)
{

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



float FreeFlyVision::getVitesseAvancement() const
{
    return vitesseAvancement;
}

void FreeFlyVision::setVitesseAvancement(float value)
{
    vitesseAvancement = value;
}

