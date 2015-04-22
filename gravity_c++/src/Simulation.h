#ifndef SIMULATION_H
#define SIMULATION_H

#include "MesObjets.h"
#include "Monde.h"
#include "Temps.h"

#include "PreparationObjet.h"

class Simulation
{
public:
    Simulation();
    Simulation(MesObjets objets, Monde monde);


protected:
    MesObjets mesObjets;
    Monde monde;
    Temps temps;
};

#endif // SIMULATION_H
