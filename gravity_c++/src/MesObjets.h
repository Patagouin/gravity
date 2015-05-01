


#ifndef MESOBJETS_H
#define MESOBJETS_H

/* classe contenant tout les objets graphiques qui seront dessiné à l'écran */
#include <QVector>
#include <QVector3D>
#include <QList>
#include <QHash>
#include <QString>

#include "AbstractObjet.h"
#include "ObjetClassique.h"
#include "Micro.h"
#include "Camera.h"
#include "Lampe.h"

enum TYPE_OBJET {OBJETCLASSIQUE, LAMPE, CAMERA, MICRO};

class MesObjets
{
public:
    MesObjets();
    MesObjets(const MesObjets* other); // Constructeur de copie

    ~MesObjets();



    void ajouterObjet(ObjetClassique &objet);
    void ajouterObjet(Micro &objet);
    void ajouterObjet(Camera &objet);
    void ajouterObjet(Lampe &objet);

    QList<QVector<QVector3D> > &getCoordNewObjets();

    int nbObjets;
    int nbTotalObjets;  // Comptabilise les objets détruits

    QHash <TYPE_OBJET, QList<AbstractObjet> > objets;




    QList<AbstractObjet> nouveauObjets;

    QList<QVector<QVector3D> > newCoordObjects; // Chaque éléments de la liste représente un objet

    int nbVertices;
    int nbTriangles;



private:


};




#endif // MESOBJETS_H
