#include "WindowGL.h"

WindowGL::WindowGL(QWidget *parent) : WindowGen(parent)
{
    //glWidgets.insert(DEFAULT, QGLWidget(parent));

//    glLayout = new QGridLayout(); // a tester: Voir si en mettant le parent le "widget central" cela fonctionne sans passer par setLayout
//    glLayout->addWidget(glWidgets[DEFAULT]);

//    widgetCentral->setLayout(&glLayout); // Installation de la fenetre OpenGL

}


//QGLWidget WindowGL::getGLWidget(QString nom)
//{
//    return glWidgets[nom];
//}
