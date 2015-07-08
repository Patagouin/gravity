#include <QApplication>
#include "GlWidget.h"
#include "ObjetClassique.h"
#include "MesObjets.h"
#include "MesLumieres.h"

#include "QVector"
#include "QVector3D"

#include "Cube.h"
#include "Sphere.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);





    MesObjets objets = MesObjets();
    MesLumieres lumieres = MesLumieres();

    Sphere sphere1 = Sphere(QVector3D(0,0,1), 1,3, 1000);


    Sphere sphere1 = Sphere(QVector3D(0,0,1), 1,5, 1000);
    objets.ajouterObjet(sphere1);

    Sphere sphere2 = Sphere(QVector3D(0,0,-1), 1,100, 100, 1000);
    objets.ajouterObjet(sphere2);

    Lumiere lum1 = Lumiere(QVector3D(2,2,2),QColor(125,255,125),QColor(125,255,125),QColor(125,255,125));
    lumieres.ajouterLumiere(lum1);

    GlWidget *w = new GlWidget(objets, lumieres);
    w->show();

    return a.exec();
}
