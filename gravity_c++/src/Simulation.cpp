#include "Simulation.h"

Simulation::Simulation()
{
    Monde monde = Monde();
    MesObjets mesObjets = MesObjets();
    Temps temps = Temps();
}

Simulation::Simulation(MesObjets _objets, Monde _monde)
{
    mesObjets = _objets;
    monde = _monde;
    PreparationObjet prep = PreparationObjet();
    prep.chargerObjets(mesObjets);


    GLWidget gl = GLWidget();
    gl.updateGL();

}


