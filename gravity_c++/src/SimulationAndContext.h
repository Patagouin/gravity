#ifndef SIMULATIONANDCONTEXT_H
#define SIMULATIONANDCONTEXT_H

/* Cette classe permet de faire le lien entre une simulation et un contexte d'affichage */

#include "MesObjets.h"
#include "PreparationObjet.h"
//#include "Simulation.h"
#include "GLWidget.h"
//#include "Shader.h"

enum MODE_AFFICHAGE {OPENGL};
class SimulationAndContext
{
public:
    SimulationAndContext(MesObjets &objets, void *context, MODE_AFFICHAGE mode);
    ~SimulationAndContext();


private:

    //Simulation simulation;
    MesObjets objets;
    //PreparationObjet preparation;
    //Shader shader;
    MODE_AFFICHAGE mode;
    GLWidget *glWidget; // Sera initialisé à NULL si ce n'est pas le mode d'affichage choisi


};

#endif // SIMULATIONANDCONTEXT_H
