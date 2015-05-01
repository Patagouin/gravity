#ifndef WINDOWGEN_H
#define WINDOWGEN_H

//Anciennement #include <QtWidgets> inclué toutes ces librairies
//#include <QtWidgets>
#include <QApplication>
#include <QGridLayout>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDockWidget>
#include <QTabBar>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>

#include <QGLWidget>

#include <QMainWindow>
#include <QHash>
#include <QString>

class WindowGen : public QMainWindow
{
    Q_OBJECT

    //enum Mode {VUE, EDITION, CREATION};
    //typedef enum Mode Mode;

public:
    WindowGen(QWidget *parent = 0);
    QGLWidget *glWidget;

public slots:
    //void actualiserPosition(QMouseEvent *event);
protected:
    // Peut etre que certains attributs devront être supprimé


    // pour gérer plusieurs simulation à la fois, du coup mettre un composant pour pouvoir ajouter glwidget

    QWidget* widgetCentral; // Widget dans lequel sera intégré la fenetre de rendu ou autre
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

#endif // WINDOWGEN_H
