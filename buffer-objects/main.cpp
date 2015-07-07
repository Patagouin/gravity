#include <QApplication>
#include "GlWidget.h"
#include "ObjetClassique.h"
#include "MesObjets.h"
#include "QVector"
#include "QVector3D"

#include "Cube.h"
#include "Sphere.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);





    MesObjets objets = MesObjets();


    Sphere sphere1 = Sphere(QVector3D(0,0,1), 1,2, 1000);
    objets.ajouterObjet(sphere1);

    Sphere sphere2 = Sphere(QVector3D(0,0,-1), 1,10, 10, 1000);
    objets.ajouterObjet(sphere2);


    GlWidget *w = new GlWidget(objets);
    w->show();

    return a.exec();
}
