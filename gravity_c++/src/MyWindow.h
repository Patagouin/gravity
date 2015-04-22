#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QtWidgets>
#include <QMainWindow>
#include "GLWidget.h"
#include <QHash>
#include <QString>

class MyWindow : public QMainWindow
{
    Q_OBJECT

    //enum Mode {VUE, EDITION, CREATION};
    //typedef enum Mode Mode;

public:
    MyWindow(QWidget *parent = 0);

public slots:
    void actualiserPosition(QMouseEvent *event);
    void changerGLBuffer();
protected:
    // Peut etre que certains attributs devront être supprimé


    // pour gérer plusieurs simulation à la fois, du coup mettre un composant pour pouvoir ajouter glwidget
    QHash<QString, GLWidget*>  glWidgets;

    QWidget* widgetCentral;
    QGridLayout *glLayout;
    QMenu *menuFichier;
    QAction *actionQuitter;
    QMenu *menuEdition;
    QMenu *menuOutils;
    QMenu *menuAide;
    QDockWidget *dock;
    QTabBar *barreOnglets;
    QToolBar barreOutils;
    QStatusBar *barreStatus;
    QLabel *positionSouris;
    QLabel *modeLabel;

    QString nomBufferActuel;
    //Mode mode; // vueUtilisateur s'occupe de ca



};

#endif // MYWINDOW_H
