#ifndef FREEFLYVISION_H
#define FREEFLYVISION_H
#include "QVector3D"
#include <QMouseEvent>
#include <QWheelEvent>
#include <QMatrix4x4>
#include <QSize>
#include <QElapsedTimer>

class FreeFlyVision
{
public:
    FreeFlyVision(QSize tailleAffichage, float imagesParSeconde);

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
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

    void setTailleAffichage(QSize nouvelleTaille);

protected:
    void setAnglesTorightValue();
    void calculatePosDelta(int x, int y); // Calcule le rapport entre la position de la souris et le milieu de l'ecran

    QMatrix4x4 viewMatrix;

    QSize tailleAffichage;
    float imagesParSeconde;

    float vitesseAvancement;
    float vitesseRotation;

    QVector3D positionCamera;
    //QVector3D direction;

    QElapsedTimer timer;
    qint64 tempsAppuie;

    float deltaMidX; // Pour stocker les coord de la souris lorsque celle ci est en position onClick et qu'un update doit se faire
    float deltaMidY;
    int typeSouris; // Pour savoir quel click de souris est enfoncé (gauche, droite)

    QPoint lastMousePosition;

    float angleHorizontal;
    float angleVertical;

    float avancement;


};

#endif // FREEFLYVISION_H
