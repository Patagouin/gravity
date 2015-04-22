


#ifndef MESOBJETS_H
#define MESOBJETS_H

/* classe contenant tout les objets graphiques qui seront dessiné à l'écran */

#include <QVector3D>
#include <QList>
#include <QHash>
#include <QString>

#include "AbstractObjet.h"
#include "ObjetClassique.h"
#include "Micro.h"
#include "Camera.h"
#include "Lampe.h"

class MesObjets
{
public:
    MesObjets();

    ~MesObjets();

    // Constructeur de copie
    MesObjets(const MesObjets* other) :  nbObjets(other->nbObjets), nbTotalObjets(other->nbTotalObjets),
                                       mesObjets(Qhash(other->mesObjets))

    {


    }

    void ajouterObjet(ObjetClassique *objet);
    void ajouterObjet(Micro *objet);
    void ajouterObjet(Camera *objet);
    void ajouterObjet(Lampe *objet);

private:
    QHash <QString, QList<AbstractObjet> > mesObjets;

    QList<AbstractObjet> mesObjetsClassiques;
    QList<AbstractObjet> mesLampes;
    QList<AbstractObjet> mesCameras;
    QList<AbstractObjet> mesMicros;

    int nbObjets;
    int nbTotalObjets;  // Comptabilise les objets détruits

    int nbVertices;
    int nbTriangles;



};




#endif // MESOBJETS_H
