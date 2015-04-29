#include "Simulation.h"



Simulation::Simulation(MesObjets &_objets, Monde _monde) :  mesObjets(MesObjets()), monde(Monde()), temps(new Temps())
{
    mesObjets = _objets;
    monde = _monde;



}


