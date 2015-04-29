#ifndef CAMERA_H
#define CAMERA_H

/* Cette classe définit les propiétés pour un objet (n'est pas un conteneur, le conteneur est mesObjets)*/

#include "AbstractObjet.h"
#include "ObjetClassique.h"
#include <QVector3D>


class Camera : public ObjetClassique
{

public:
    Camera();
    Camera(ObjetClassique objetClassique, QVector3D positionCamera, QVector3D positionFocus, double distanceNear,
           double distanceFar, double tailleL, double tailleR, double tailleT, double tailleB);
    ~Camera();



    QVector3D getPositionFocus() const;
    void setPositionFocus(const QVector3D &value);


protected:

    QVector3D positionCamera;
    QVector3D positionFocus;
    double distanceNear; // Distance de positionCamera où FOV commence
    double distanceFar; // Distance de positionCamera où FOV fini
    double tailleL;
    double tailleR;
    double tailleT;
    double tailleB;


    // L'orientation de la caméra est donné par la classe mere AbstractObjet

    /* Pourra etre rajouté un buffer pour les pixels qui seront affiché à l'écran
        qui sera directement donné au buffer PENCIL_BUFFER */



};


#endif // CAMERA_H
