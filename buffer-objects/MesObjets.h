


#ifndef MESOBJETS_H
#define MESOBJETS_H

/* classe contenant tout les objets graphiques qui seront dessiné à l'écran */
#include <QVector>
#include <QVector3D>
#include <QList>
#include <QHash>
#include <QString>

#include "ObjetClassique.h"

enum TYPE_OBJET {OBJETCLASSIQUE, LAMPE, CAMERA, MICRO};

class MesObjets
{
public:
    MesObjets();
    MesObjets(const MesObjets* other); // Constructeur de copie

    ~MesObjets();

    void clonerObjet(int index);

    void translaterObjet(int index, float x, float y, float z);
    void rotationObjet(int index, QVector3D axe, float angle);
    void scaleObjet(int index, float facteur);

    void ajouterObjet(ObjetClassique &objet);

    void supprimerObjet(int index);



    QList<ObjetClassique> objets;





private:


};




#endif // MESOBJETS_H
