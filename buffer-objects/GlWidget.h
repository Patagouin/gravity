#ifndef GlWidget_H
#define GlWidget_H

#include <QGLWidget>
#include <QGLShaderProgram>
#include <QGLBuffer>
#include "MesObjets.h"
#include "MesLumieres.h"
#include "SystemeVision.h"
#include "TempsGL.h"


// Le système d'affichage et de navigation est dynamique
//! [0]
class GlWidget : public QGLWidget
{
    //! [0]
    Q_OBJECT

public:
    GlWidget(MesObjets objets, MesLumieres lumieres, QWidget *parent = 0);
    ~GlWidget();
    QSize sizeHint() const;

    void updateView();

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent * event);

    //! [1]
private:
    MesObjets mesObjets;
    MesLumieres mesLumieres;

    SystemeVision sv;
    TempsGL *temps;

    //! [1]
    QMatrix4x4 pMatrix;
    QGLShaderProgram lightingShaderProgram;
    //! [2]
    int nbVertices;
    QGLBuffer objetsBuffer; // Contient les vertices et les normales
    QGLBuffer simuBuffer; // Contient les données physiques des objets (masse, vitesse initial, centre...)
    //! [2]
    GLuint cubeTexture;
    QGLShaderProgram coloringShaderProgram;
    //! [3]
    int numSpotlightVertices;
    QGLBuffer spotlightBuffer;
    //! [3]
    double lightAngle;


};
//! [4]

#endif // GlWidget_H
