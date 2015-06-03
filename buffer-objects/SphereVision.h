#ifndef SPHEREVISION_H
#define SPHEREVISION_H

#include "QMatrix4x4"
#include <QMouseEvent>
#include <QWheelEvent>



class SphereVision
{
public:
    SphereVision();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

    void computeViewMatrix();

    QMatrix4x4 getViewMatrix() const;
    void setViewMatrix(const QMatrix4x4 &value);

protected:
    QMatrix4x4 viewMatrix;

    float alpha;
    float beta;
    float distance;


    QPoint lastMousePosition;

};

#endif // SPHEREVISION_H
