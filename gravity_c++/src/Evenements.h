#ifndef EVENEMENTS_H
#define EVENEMENTS_H

#include <QPoint>
#include "Simulation.h"

/** Cette classe gère les évènements utilisateur. **/
class Evenements
{
    Q_OBJECT

public:
    Evenements(Simulation *simu);

protected:
    Simulation *simu; // Contexte

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

private:
    // Retient la position du clic pour le déplacement dans la scène (rotation ou translation)
    QPoint lastMousePosition;

Q_SIGNALS:
     void deplacement(QMouseEvent *event);
};

#endif // EVENEMENTS_H
