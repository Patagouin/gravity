#include "SphereVision.h"

SphereVision::SphereVision()
{

    alpha = 25;
    beta = -25;
    distance = 2.5;

}

void SphereVision::computeViewMatrix()
{
    viewMatrix.setToIdentity();

    QMatrix4x4 cameraTransformation;
    cameraTransformation.rotate(alpha, 0, 1, 0);
    cameraTransformation.rotate(beta, 1, 0, 0);

    QVector3D cameraPosition = cameraTransformation * QVector3D(0, 0, distance);
    QVector3D cameraUpDirection = cameraTransformation * QVector3D(0, 1, 0);

    viewMatrix.lookAt(cameraPosition, QVector3D(0, 0, 0), cameraUpDirection);

}
QMatrix4x4 SphereVision::getViewMatrix() const
{
    return viewMatrix;
}

void SphereVision::setViewMatrix(const QMatrix4x4 &value)
{
    viewMatrix = value;
}


void SphereVision::mousePressEvent(QMouseEvent *event)
{
    lastMousePosition = event->pos();

    event->accept();
}

void SphereVision::mouseMoveEvent(QMouseEvent *event)
{
    int deltaX = event->x() - lastMousePosition.x();
    int deltaY = event->y() - lastMousePosition.y();

    if (event->buttons() & Qt::LeftButton) {
        alpha -= deltaX;
        while (alpha < 0) {
            alpha += 360;
        }
        while (alpha >= 360) {
            alpha -= 360;
        }

        beta -= deltaY;
        if (beta < -90) {
            beta = -90;
        }
        if (beta > 90) {
            beta = 90;
        }
    }

    lastMousePosition = event->pos();

    event->accept();
}

void SphereVision::wheelEvent(QWheelEvent *event)
{

    int delta = event->delta();

    if (event->orientation() == Qt::Vertical) {
        if (delta < 0) {
            distance *= 1.1;
        } else if (delta > 0) {
            distance *= 0.9;
        }
    }

    event->accept();
}
