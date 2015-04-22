#ifndef VUEUTILISATEUR_H
#define VUEUTILISATEUR_H

#include "QVector3D"

/** Vue qu'a l'utilisateur lors de l'édition de sa scène **/

enum visionMode {solide, maillage}; // pourra etre ajouter bounding box (boite englobante), texture, rendu

class VueUtilisateur
{
public:
    VueUtilisateur();


protected:
    visionMode typeVision = solide;
    double angleDeVue;
    QVector3D position;
};

#endif // VUEUTILISATEUR_H
