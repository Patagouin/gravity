#include "SimulationAndContext.h"


SimulationAndContext::SimulationAndContext(MesObjets &_objets, void *context, MODE_AFFICHAGE _mode)
{
    //simulation = Simulation(objets, _monde); // Pour l'instant inutile
    mode = _mode;
    if (mode == OPENGL){
        glWidget = (GLWidget *) context;
        preparation = PreparationObjet();
        //preparation.chargerObjets(objets.mesObjetsClassiques); // Pour l'instant charge tout les objets classique
        glWidget->updateGL();
    }

    else{
        glWidget = NULL;
    }




}

SimulationAndContext::~SimulationAndContext()
{
    delete glWidget;
}
