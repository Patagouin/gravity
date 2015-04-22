#include "Camera.h"

Camera::Camera()
{
    
}
/*
Camera(ObjetClassique objetClassique, QVector3D pointFocus, QList<QVector3D> surfaceCamera)
            : ObjetClassique(objetClassique), pointFocus(pointFocus), surfaceCamera(QList<QVector3D>(surfaceCamera))
{


}*/
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



