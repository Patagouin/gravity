#include "Temps.h"

Temps::Temps() : QTimer()
{

    //connect(this, SIGNAL(timeout()), simu, SLOT(simu->context->updateGL()););
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

/*
void Temps::timeout()
{
    updateGL();
}
*/

