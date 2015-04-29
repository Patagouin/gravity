#ifndef PHYSIQUE_H
#define PHYSIQUE_H

#include "AbstractObjet.h"
#include "MesObjets.h"

class Physique
{
public:

    Physique();

    void appliquerGravitationGeneral(MesObjets *objets);
    void appliquerGraviter(AbstractObjet *objet);

    void controleCollision(MesObjets *objets); // A faire surement a la fin des calculs physiques
    void appliquerCollision(AbstractObjet objet);
};

#endif // PHYSIQUE_H
