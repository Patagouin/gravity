#include "MyWindow.h"
#include "GLWidget.h"

#include <QStringBuilder> // Pour utiliser l'opérateur % de concatenation de chaine


MyWindow::MyWindow(QWidget *parent) : QMainWindow(parent), glWidgets(new QHash)

{

    this->showMaximized();

    mode = VUE;

    glWidgets.insert("Default", new QGLWidget(parent));


    glWidget->setMouseTracking(true); // On active le suivi de la souris pour afficher les coordonnée dans la barre de status

    // Le widget central de la QMainWindow est un GLWidget

    QWidget* widgetCentral (new QWidget);
    QGridLayout *glLayout = new QGridLayout;
    glLayout->addWidget(glWidget);
    glLayout->setContentsMargins(QMargins(2,2,2,2));
    widgetCentral->setLayout(glLayout);


    this->setCentralWidget(widgetCentral);



    // Barre de menu

    QMenu *menuFichier = menuBar()->addMenu(tr("&Fichier"));
    QAction *actionQuitter = new QAction(tr("&Quitter"), this);
    actionQuitter->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q));

    connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));

    QMenu *menuEdition = menuBar()->addMenu(tr("&Edition"));
    QMenu *menuOutils = menuBar()->addMenu("&Outils");
    QMenu *menuAide = menuBar()->addMenu("&Aide");


    menuFichier->addAction(actionQuitter);

    // Dock
    QDockWidget *dock(new QDockWidget(tr("Physique"), this));
    QTabBar *barreOnglets(new QTabBar(dock)); // On ne précise pas le pere car il connait pas la taille du dock au risque de dépacer de la fenetre lors d'ajout ultérieur

    barreOnglets->addTab("&Monde");
    barreOnglets->addTab("&Edition");
    barreOnglets->addTab("&Gravité");
    dock->setWidget(barreOnglets);


    QToolBar barreOutils(this->addToolBar("Gomme"));
    barreOutils.addAction(actionQuitter);



    this->addDockWidget(Qt::RightDockWidgetArea, dock);

    // Status Bar
    QStatusBar *barreStatus = this->statusBar();

    positionSouris = new QLabel(barreStatus);

    positionSouris->setText(QString ("Position souris : x: 0 ; y; 0"));
    barreStatus->addWidget(positionSouris);

    connect(glWidget, SIGNAL(deplacement(QMouseEvent*)), this, SLOT(actualiserPosition(QMouseEvent*)));

    modeLabel = new QLabel(barreStatus);
    /*
    switch (mode) {
    case VUE:
        modeLabel->setText(QString ("Mode d'affichage: Vue"));
        break;
    case EDITION:
        modeLabel->setText(QString ("Mode d'affichage: Edition"));
        break;
    default:
        modeLabel->setText(QString ("Mode d'affichage: Simulation"));
        break;

    }
    */
    barreStatus->addWidget(modeLabel);
}

void MyWindow::actualiserPosition(QMouseEvent *event){
    QString ch1 ("Position souris : "), ch2 ("x: "), ch3(QString::number(event->x())), ch4(" ; y: "), ch5(QString::number(event->y()));
    positionSouris->setText(ch1 % ch2 % ch3 % ch4 % ch5);
}


void MyWindow::changerGLBuffer(QString nomBuffer){
    nomBufferActuel = nomBuffer;
    //GLContext

}
