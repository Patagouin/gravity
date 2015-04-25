#include "Camera.h"

Camera::Camera()
{
    
}
Camera(ObjetClassique _objetClassique, QVector3D _positionCamera, QVector3D _positionFocus, double _distanceNear,
       double _distanceFar, double _tailleL, double _tailleR, double _tailleT, double _tailleB)
            : ObjetClassique(_objetClassique), positionCamera(_positionCamera), pointFocus(_pointFocus),
              distanceNear(_distanceNear), distanceFar(_distanceFar), tailleL(_tailleL), tailleR(_tailleR),
              tailleT(_tailleT), tailleB(_tailleB)
{


}

QVector3D Camera::getPointFocus() const
{
    return pointFocus;
}

void Camera::setPointFocus(const QVector3D &value)
{
    pointFocus = value;
}
QList<QVector3D> Camera::getSurfaceCamera() const
{
    return surfaceCamera;
}

void Camera::setSurfaceCamera(const QList<QVector3D> &value)
{
    surfaceCamera = value;
}



