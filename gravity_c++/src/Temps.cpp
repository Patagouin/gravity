#include "Temps.h"

Temps::Temps(QObject *parent /* = 0*/, Simulation *simu) : QTimer(parent)
{

    connect(this, SIGNAL(timeout()), simu, SLOT(simu->context->updateGL()););
}

double Temps::getFrameRate() const
{
    return frameRate;
}
void Temps::setFrameRate(double value)
{
    frameRate = value;
}

double Temps::getVitesse() const
{
    return vitesse;
}
void Temps::setVitesse(double value)
{
    vitesse = value;
}

void start(){
    timer->start(1000/frameRate);
}
/*
void Temps::timeout()
{
    updateGL();
}

*/

