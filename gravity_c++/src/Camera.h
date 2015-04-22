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
    Camera(ObjetClassique objetClassique, QVector3D pointFocus, QList<QVector3D> surfaceCamera);
    ~Camera();



    QVector3D getPointFocus() const;
    void setPointFocus(const QVector3D &value);

    QList<QVector3D> getSurfaceCamera() const;
    void setSurfaceCamera(const QList<QVector3D> &value);

protected:

    QVector3D pointFocus;
    QList<QVector3D> surfaceCamera;

    // L'orientation de la caméra est donné par la classe mere AbstractObjet

    /* Pourra etre rajouté un buffer pour les pixels qui seront affiché à l'écran
        qui sera directement donné au buffer PENCIL_BUFFER */



};


#endif // CAMERA_H
