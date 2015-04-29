/* Cette classe définit les propiétés pour un objet (n'est pas un conteneur, le conteneur est mesObjets)*/


#ifndef OBJETCLASSIQUE_H
#define OBJETCLASSIQUE_H


#include "AbstractObjet.h"

#define NB_MECA_PROPERPTY 5

enum Meca {RESISTANCE, DURETE, RIGIDITE, DUCTIBILITE, TENACITE};

// Cette classe pourra etre utilisé en tant que "patron" un modèle pour toutes les sous-classes qui
// seront créée par la suite

class ObjetClassique : public AbstractObjet
{

public:
    ObjetClassique();
    ObjetClassique(AbstractObjet &abstractObjet, double masse, double mecanique[NB_MECA_PROPERPTY]/*[3]*/);

    ObjetClassique(const ObjetClassique* other );

    // Getteur et Setteur

    double getMasse() const;
    void setMasse(double masse);


    double getMecanique(Meca type) const;
    void setMecanique(const double *deformation);
    void setMecanique(double resistance, double durete, double rigidite, double ductibilite, double tenacite);


protected:

    double masse; //En kg
    double mecanique[NB_MECA_PROPERPTY];  // Resistance = contrainte max avant rupture (
                          // Dureté = résistance à la pénétration (forte verre)
                          // Rigidité = deformation reversible, cohésion atomes (forte elastique)
                          // Ductibilité = deformation irreversible (forte chewing-gum)
                          // Tenacité = propriete du matériaux à emmagsiner de l'energie avant sa rupture. Propagation fissure
                          // A prolonger ...
/*
    double electrique[1]; // A remplir
    double thermique[1];
    double magnetique[1];
    double optique[1];
    double chimique[1];
*/


};

#endif // OBJETCLASSIQUE_H
