#ifndef TEMPS_H
#define TEMPS_H

#include <QTimer>

class Temps : public QTimer
{
    Q_OBJECT
public:
    Temps();

    double getFrameRate() const;
    void setFrameRate(double value);

    double getVitesse() const;
    void setVitesse(double value);

private:
    double vitesse; // vitesse de la simulation
    double frameRate; // Par seconde

private slots:
    //void timeout();
};


#endif // TEMPS_H
