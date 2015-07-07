#include "Sphere.h"

#define PI 3.14159265359
#define ICOSAHEDRON_NB_LVL 4
#define ICOSAHEDRON_NB_VERTICES_ON_LVL 5
#define ICOSAHEDRON_ANGLE_BETWEEN_LVL 60

#include <qmath.h>


Sphere::Sphere(QVector3D _centre, float _rayon, int nbParallele, int nbMeridian, float _masse) :
    ObjetClassique(_centre, _masse, sphere), rayon(_rayon)
{
    QVector <QVector3D> sphereFaces;
    QVector <QVector3D> vertices;
    double angleXY;
    double angleXZ;

    float hauteur;
    float rayonCercle;
    for (int i = 0; i < nbParallele; i++){
        angleXY = (PI/2) - (PI/(nbParallele-1)*i);
        hauteur = qSin(angleXY) * rayon; // hauteur de l'anneau
        rayonCercle = qCos(angleXY); // rayon de l'anneau

        for (int j = 0; j < nbMeridian; j++){
            angleXZ = j * ((2*PI)/nbMeridian);
            vertices <<  QVector3D((qSin(angleXZ) * rayonCercle) + centre.x(), centre.y()+ hauteur, (qCos(angleXZ) * rayonCercle) + centre.z());
        }

    }
    // Creation des faces
    for (int i = 0; i< nbParallele - 1; i++){
        for (int y = 0; y < nbMeridian - 1; y++){
            sphereFaces << vertices.at(i*nbMeridian + y) << vertices.at(((i+1)*nbMeridian) + y) << vertices.at(((i+1)*nbMeridian) + y+1);
            sphereFaces << vertices.at(i*nbMeridian + y) << vertices.at(((i+1)*nbMeridian) + y+1) << vertices.at((i*nbMeridian) + y+1);

        }
                sphereFaces << vertices.at((i+1)*nbMeridian - 1) << vertices.at((i+2)*nbMeridian - 1) << vertices.at((i+1)*nbMeridian);
                sphereFaces << vertices.at((i+1)*nbMeridian - 1) << vertices.at((i+1)*nbMeridian) << vertices.at(i*nbMeridian);
    }
    setForme(sphereFaces);

//    QVector <QVector3D> sphereNormales;
//    for (int i = 0; i < sphereFaces.length(); i++){
//        sphereNormales <<
//    }
}

Sphere::Sphere(QVector3D _centre, float _rayon, int nbSubdivision, float _masse):
    ObjetClassique(_centre, _masse, sphere), rayon(_rayon)
{
    if (rayon==0)
        rayon = 1;

    QVector <QVector3D> sphereFaces[2]; // 2 dimensions afin de jongler entre les deux pour chaque niveau de recursion
    QVector <QVector3D> vertices;
    double angleXY;
    double angleXZ;

    float hauteur;
    float rayonCercle;
    float decalage = (2*PI/ICOSAHEDRON_NB_VERTICES_ON_LVL)/2;
    // Icosahedron
    for (int i = 0; i < ICOSAHEDRON_NB_LVL; i++){

        angleXY = (PI/2) - (PI/(ICOSAHEDRON_NB_LVL-1)*i);
        hauteur = qSin(angleXY) * rayon; // hauteur de l'anneau
        rayonCercle = qCos(angleXY) * rayon; // rayon de l'anneau

        for (int j = 0; j < ICOSAHEDRON_NB_VERTICES_ON_LVL; j++){
            angleXZ = j * ((2*PI)/ICOSAHEDRON_NB_VERTICES_ON_LVL) - ((i-1) * decalage);
            vertices <<  QVector3D((qSin(angleXZ) * rayonCercle) + centre.x(), centre.y()+ hauteur, (qCos(angleXZ) * rayonCercle) + centre.z());
        }

    }


    // Creation des faces initiales
    int currentSubdivision = 0;

    for (int i = 0; i< ICOSAHEDRON_NB_LVL - 1; i++){
        for (int y = 0; y < ICOSAHEDRON_NB_VERTICES_ON_LVL - 1; y++){
            sphereFaces[currentSubdivision%2] << vertices.at(i*ICOSAHEDRON_NB_VERTICES_ON_LVL + y)
                        << vertices.at(((i+1)*ICOSAHEDRON_NB_VERTICES_ON_LVL) + y)
                        << vertices.at(((i+1)*ICOSAHEDRON_NB_VERTICES_ON_LVL) + y+1);

            sphereFaces[currentSubdivision%2] << vertices.at(i*ICOSAHEDRON_NB_VERTICES_ON_LVL + y)
                        << vertices.at(((i+1)*ICOSAHEDRON_NB_VERTICES_ON_LVL) + y+1)
                        << vertices.at((i*ICOSAHEDRON_NB_VERTICES_ON_LVL) + y+1);

        }
        sphereFaces[currentSubdivision%2] << vertices.at((i+1)*ICOSAHEDRON_NB_VERTICES_ON_LVL - 1)
                    << vertices.at((i+2)*ICOSAHEDRON_NB_VERTICES_ON_LVL - 1)
                    << vertices.at((i+1)*ICOSAHEDRON_NB_VERTICES_ON_LVL);

        sphereFaces[currentSubdivision%2] << vertices.at((i+1)*ICOSAHEDRON_NB_VERTICES_ON_LVL - 1)
                    << vertices.at((i+1)*ICOSAHEDRON_NB_VERTICES_ON_LVL)
                    << vertices.at(i*ICOSAHEDRON_NB_VERTICES_ON_LVL);
    }
    currentSubdivision += 1;
    // Division de sa surface
    QVector3D p1; // Points utiliser lors du découpage du triangle
    QVector3D p2;
    QVector3D p3;
    float distance;
    while (currentSubdivision < nbSubdivision){
        sphereFaces[currentSubdivision%2].clear();

        for (int i = 0; i < sphereFaces[(currentSubdivision+1)%2].size(); i+=3){
            p1 = QVector3D(((sphereFaces[(currentSubdivision+1)%2].at(i+1) - sphereFaces[(currentSubdivision+1)%2].at(i)) / 2 ) + sphereFaces[(currentSubdivision+1)%2].at(i));
            p2 = QVector3D(((sphereFaces[(currentSubdivision+1)%2].at(i+2) - sphereFaces[(currentSubdivision+1)%2].at(i+1)) / 2 ) + sphereFaces[(currentSubdivision+1)%2].at(i+1));
            p3 = QVector3D(((sphereFaces[(currentSubdivision+1)%2].at(i) - sphereFaces[(currentSubdivision+1)%2].at(i+2)) / 2 ) + sphereFaces[(currentSubdivision+1)%2].at(i+2));
            // Reajustement de ces points sur la sphere de rayon = rayon
            distance = p1.distanceToPoint(centre);
            p1 += (p1 - centre) * ((rayon / distance) - 1); // ne peut etre egal a 0 que ce soit rayon ou distance
            distance = p2.distanceToPoint(centre);
            p2 += (p2 - centre) * ((rayon / distance) - 1);
            distance = p3.distanceToPoint(centre);
            p3 += (p3 - centre) * ((rayon / distance) - 1);
            // Creation des nouvelles faces
            sphereFaces[currentSubdivision%2] << sphereFaces[(currentSubdivision+1)%2][i] << p1 << p3
                                              << p1 << sphereFaces[(currentSubdivision+1)%2][i+1] << p2
                                              << p3 << p2 << sphereFaces[(currentSubdivision+1)%2][i+2]
                                              << p1 << p2 << p3;
        }
        currentSubdivision++;
    }
    setForme(sphereFaces[(nbSubdivision+1)%2]);

}
