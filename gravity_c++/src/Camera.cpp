#include "Camera.h"

Camera::Camera()
{
    
}
Camera::Camera(ObjetClassique _objetClassique, QVector3D _positionCamera, QVector3D _positionFocus, double _distanceNear,
       double _distanceFar, double _tailleL, double _tailleR, double _tailleT, double _tailleB)
            : ObjetClassique(_objetClassique), positionCamera(_positionCamera), positionFocus(_positionFocus),
              distanceNear(_distanceNear), distanceFar(_distanceFar), tailleL(_tailleL), tailleR(_tailleR),
              tailleT(_tailleT), tailleB(_tailleB)
{


}

QVector3D Camera::getPositionFocus() const
{
    return positionFocus;
}

void Camera::setPositionFocus(const QVector3D &value)
{
    positionFocus = value;
}



