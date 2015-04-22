#ifndef TEMPS_H
#define TEMPS_H

#include <QTimer>

class Temps : public QTimer
{
    Q_OBJECT
public:
    Temps(QObject *parent = 0);

    void start();

    double getFrameRate() const;
    void setFrameRate(double value);

    double getVitesse() const;
    void setVitesse(double value);

private:
    double vitesse; // vitesse de la simulation
    double frameRate; // Par seconde

private Q_SLOTS:
    void timeout();
};


#endif // TEMPS_H
