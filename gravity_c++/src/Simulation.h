#ifndef SIMULATION_H
#define SIMULATION_H

/*  Cette classe permet de mettre à jour les objets mais ne fait aucun rendu ou envoie */

#include "MesObjets.h"
#include "Monde.h"
#include "Temps.h"


class Simulation
{
public:
    Simulation(MesObjets &_objets, Monde _monde);


protected:
    MesObjets mesObjets; // connait que la ref
    Monde monde;
    Temps *temps;
};

#endif // SIMULATION_H
