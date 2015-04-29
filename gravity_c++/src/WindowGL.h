#ifndef WINDOWGL_H
#define WINDOWGL_H

#include "WindowGen.h"
#include <QGridLayout>

#include <QGLWidget>

#define DEFAULT "Default"

class WindowGL : public WindowGen
{
public:
    WindowGL(QWidget *parent = 0);
public slots:
    void changerGLBuffer();

    //QGLWidget getGLWidget(QString nom); // retourne la référence
protected:
    QHash<QString, QGLWidget>  glWidgets;

    QGridLayout *glLayout;



};

#endif // WINDOWGL_H
