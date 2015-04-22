#include "ObjetClassique.h"

ObjetClassique::ObjetClassique()
{
}

ObjetClassique::ObjetClassique(AbstractObjet *abstractObjet, double masse, double mecanique[NB_MECA_PROPERPTY])
                :  AbstractObjet(abstractObjet), masse(masse)
{
    this->setMecanique(mecanique);
}


/*nom(new QString(*other->nom), forme(new QList<QVector3D>(*other->forme)),
                  normales(new QList<QVector3D>(*other->normales)),
                  texturecoords(new QList<QVector3D>(*other->textureCoords)),
                  position(other->position), orientation(other->orientation),
                  taille(other->taille), deplacable(other->deplacable)),
                  masse(other->masse)*/

ObjetClassique::ObjetClassique(const ObjetClassique* other)
                : AbstractObjet(other), masse(other->masse)
{
    this->setmecanique(other->mecanique);
}

double ObjetClassique::getMasse() const{  return masse;   }

void ObjetClassique::setMasse(double masse){    masse = masse;    }



double ObjetClassique::getMecanique(Meca type) const{
    /** La variable membre mecanique contient NB_MECA_PROPERPTY double {RESISTANCE, DURETE, RIGIDITE, DUCTIBILITE, TENACITE}**/
    return mecanique[type];
}

void ObjetClassique::setMecanique(double resistance, double durete, double rigidite, double ductibilite, double tenacite){
    mecanique[RESISTANCE] = resistance;
    mecanique[DURETE] = durete;
    mecanique[RIGIDITE] = rigidite;
    mecanique[DUCTIBILITE] = ductibilite;
    mecanique[TENACITE] = tenacite;
}
void ObjetClassique::setMecanique(const double *_mecanique){
    mecanique[RESISTANCE] = *(_mecanique + RESISTANCE);
    mecanique[DURETE] = *(_mecanique + DURETE);
    mecanique[RIGIDITE] = *(_mecanique + RIGIDITE);
    mecanique[DUCTIBILITE] = *(_mecanique + DUCTIBILITE);
    mecanique[TENACITE] = *(_mecanique + TENACITE);
}

