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
    // 2 moyens d'acceder aux elements 1) mesObjetsClassiques 2) mesObjets["objetsClassiques"]
    mesObjets["objetsClassiques"] = mesObjetsClassiques;
    mesObjets["cameras"] = mesCameras;
    mesObjets["lampes"] = mesLampes;
    mesObjets["micros"] = mesMicros;

}



//Destructeur
MesObjets::~MesObjets()
{
    nbObjets -= 1;
}



void MesObjets::ajouterObjet(ObjetClassique *objet){
    nbObjets ++;
    nbTotalObjets ++;

    if (objet->getDeplacable())
        mesObjets["objetsClassiques"].prepend(objet);
    else
        mesObjets["objetsClassiques"].append(objet);

}

void MesObjets::ajouterObjet(Micro *objet){
    nbObjets ++;
    nbTotalObjets ++;

    if (objet->getDeplacable())
        mesObjets["micros"].prepend(objet);
    else
        mesObjets["micros"].append(objet);

}

void MesObjets::ajouterObjet(Camera *objet){
    nbObjets ++;
    nbTotalObjets ++;

    if (objet->getDeplacable())
        mesObjets["cameras"].prepend(objet);
    else
        mesObjets["cameras"].append(objet);

}

void MesObjets::ajouterObjet(Lampe *objet){
    nbObjets ++;
    nbTotalObjets ++;

    if (objet->getDeplacable())
        mesObjets["lampes"].prepend(objet);
    else
        mesObjets["lampes"].append(objet);

}

