#include "MesObjets.h"


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


