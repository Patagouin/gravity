#include "MesObjets.h"
#include "QMatrix4x4"

/* SURCHARGE DES CONSTRUCTEURS*/

#include "ObjetClassique.h"

#include <iostream>

MesObjets::MesObjets()
{
    objets = QList<ObjetClassique> ();


}
// Constructeur de copie
MesObjets::MesObjets(const MesObjets* other) : objets(QList<ObjetClassique> (other->objets))

{


}

void MesObjets::ajouterObjet(ObjetClassique &objet){


    objets.append(objet);

}

void MesObjets::supprimerObjet(int index)
{
    objets.removeAt(index);
}


MesObjets::~MesObjets()
{

}

void MesObjets::clonerObjet(int index)
{
    ObjetClassique newObjet = ObjetClassique(objets[index]);


    ajouterObjet(newObjet);
}

void MesObjets::translaterObjet(int index, float x, float y, float z)
{
    objets[index].translation(x, y, z);
}

void MesObjets::rotationObjet(int index, QVector3D axe, float angle)
{
     objets[index].rotation(axe, angle);
}


