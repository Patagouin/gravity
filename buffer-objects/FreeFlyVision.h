#ifndef FREEFLYVISION_H
#define FREEFLYVISION_H
#include "QVector3D"
#include <QMouseEvent>
#include <QWheelEvent>
#include <QMatrix4x4>
#include <QSize>

class FreeFlyVision
{
public:
    FreeFlyVision(QSize tailleAffichage);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    void computeViewMatrix();

    QMatrix4x4 getViewMatrix() const;
    void setViewMatrix(const QMatrix4x4 &value);

    float getVitesseAvancement() const;
    void setVitesseAvancement(float value);

    float getVitesseRotation() const;
    void setVitesseRotation(float value);

    float getAvancement() const;
    void setAvancement(float value);

protected:
    QMatrix4x4 viewMatrix;

    QSize tailleAffichage;

    float vitesseAvancement;
    float vitesseRotation;

    QVector3D positionCamera;
    //QVector3D direction;


    QPoint lastMousePosition;

    float angleHorizontal;
    float angleVertical;

    float avancement;
};

#endif // FREEFLYVISION_H
