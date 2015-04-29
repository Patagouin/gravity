#include "MesObjets.h"


/* SURCHARGE DES CONSTRUCTEURS*/

#include "ObjetClassique.h"
#include "Micro.h"
#include "Camera.h"
#include "Lampe.h"

MesObjets::MesObjets()
{
    nbObjets ++;
    nbTotalObjets ++;

    objets = QHash <TYPE_OBJET, QList<AbstractObjet> >();

    mesObjetsClassiques = QList<AbstractObjet>();
    mesCameras = QList<AbstractObjet>();
    mesLampes = QList<AbstractObjet>();
    mesMicros = QList<AbstractObjet>();

    // 2 moyens d'acceder aux elements 1) mesObjetsClassiques 2) mesObjets["objetsClassiques"]

    objets[OBJETCLASSIQUE] = mesObjetsClassiques;
    objets[CAMERA] = mesCameras;
    objets[LAMPE] = mesLampes;
    objets[MICRO] = mesMicros;


    nouveauObjets = QList<AbstractObjet>();
    newCoordObjects = QList<QVector<QVector3D> >();

}
// Constructeur de copie
MesObjets::MesObjets(const MesObjets* other) :  nbObjets(other->nbObjets), nbTotalObjets(other->nbTotalObjets),
                                   objets(QHash<TYPE_OBJET, QList<AbstractObjet> >(other->objets))

{


}


//Destructeur
MesObjets::~MesObjets()
{
    nbObjets -= 1;
}



void MesObjets::ajouterObjet(ObjetClassique &objet){
    nbObjets ++;
    nbTotalObjets ++;

    nouveauObjets.append(objet);
    if (objet.getDeplacable())
        objets[OBJETCLASSIQUE].prepend(objet);
    else
        objets[OBJETCLASSIQUE].append(objet);

}

void MesObjets::ajouterObjet(Micro &objet){
    nbObjets ++;
    nbTotalObjets ++;
    nouveauObjets.append(objet);

    if (objet.getDeplacable())
        objets[MICRO].prepend(objet);
    else
        objets[MICRO].append(objet);

}

void MesObjets::ajouterObjet(Camera &objet){
    nbObjets ++;
    nbTotalObjets ++;
    nouveauObjets.append(objet);

    if (objet.getDeplacable())
        objets[CAMERA].prepend(objet);
    else
        objets[CAMERA].append(objet);

}

void MesObjets::ajouterObjet(Lampe &objet){
    nbObjets ++;
    nbTotalObjets ++;
    nouveauObjets.append(objet);

    if (objet.getDeplacable())
        objets[LAMPE].prepend(objet);
    else
        objets[LAMPE].append(objet);

}

QList<QVector<QVector3D> > &MesObjets::getCoordNewObjets()
{
    newCoordObjects.clear();
    for (int i = 0; i < nouveauObjets.size(); i++){
        newCoordObjects.append(QVector<QVector3D>(nouveauObjets.at(i).getForme()));

    }
    return newCoordObjects;
}

