/****************************************************************************
**
** Copyright (C) 2012 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "GLWidget.h"
/*
#include <QTimer>

#include <QMouseEvent>
#include <QWheelEvent>
*/
#include "AbstractObjet.h"
#include "ObjetClassique.h"
#include "Shader.h"

/* Cette classe permet de faire le rendu OpenGL, elle ne connait pas les buffers qui ont été envoyés
 * au GPU (fait dans preparationObjet), les shaders sont initialisé dans la classe Shader et certains
 * paramètres sont fournis dans la classe GLConfig, l'envoie des buffer (ceux du GPU) vers un shader
 * particulier se fait dans preparationObjet */

#ifdef WIN32
    #include <GL/glext.h>
    PFNGLACTIVETEXTUREPROC pGLActiveTexture = NULL;
    #define glActiveTexture pGLActiveTexture
#endif //WIN32

#define PRIMITIVE_FACE GL_TRIANGLES // a changer en TRIANGLES_FAN

GLWidget::GLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(/* Additional format options */), parent)
{
    /*
    alpha = 25;
    beta = -25;
    distance = 2.5;
    lightAngle = 0;
    */
    /*
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
    timer->start(17);
    */
}

GLWidget::~GLWidget()
{
}

QSize GLWidget::sizeHint() const
{
    return QSize(640, 480);
}

//! [0]
void GLWidget::initializeGL()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    qglClearColor(QColor(Qt::black));

    program.addShaderFromSourceFile(QGLShader::Vertex, ":/vertex.vsh");
    program.addShaderFromSourceFile(QGLShader::Fragment, ":/fragment.fsh");
    program.link();
//    program.addShaderFromSourceFile(QGLShader::Fragment, ":/lightingFragmentShader.fsh");
//    program.link();



    //! [0]
    // S'occuper de l'initialisation de objets
    //configurerGL();

    //fondGL(); //chargement du fond

    //chargementShaderGL(); // chargement des shaders

    //chargementTextureGL();

    /*
    #ifdef WIN32
        glActiveTexture = (PFNGLACTIVETEXTUREPROC) wglGetProcAddress((LPCSTR) "glActiveTexture");
    #endif
    */
    // glConfig.cc
        /*
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    */
    // Monde.cpp
    /*
    qglClearColor(QColor(Qt::black));
    */
    // preparationObjet.cpp changer la méthode de diffusion de la lumiere
    /*
    program.addShaderFromSourceFile(QGLShader::Vertex, ":/lightingVertexShader.vsh");
    program.addShaderFromSourceFile(QGLShader::Fragment, ":/lightingFragmentShader.fsh");
    program.link();
    */
    /*
    // MesObjets.cpp
    QVector<QVector3D> cubeVertices;
    QVector<QVector3D> cubeNormals;
    QVector<QVector2D> cubeTextureCoordinates;


    // Par des triangles
    cubeVertices << QVector3D(-0.5, -0.5,  0.5) << QVector3D( 0.5, -0.5,  0.5) << QVector3D( 0.5,  0.5,  0.5) // Front
                 << QVector3D( 0.5,  0.5,  0.5) << QVector3D(-0.5,  0.5,  0.5) << QVector3D(-0.5, -0.5,  0.5)
                 << QVector3D( 0.5, -0.5, -0.5) << QVector3D(-0.5, -0.5, -0.5) << QVector3D(-0.5,  0.5, -0.5) // Back
                 << QVector3D(-0.5,  0.5, -0.5) << QVector3D( 0.5,  0.5, -0.5) << QVector3D( 0.5, -0.5, -0.5)
                 << QVector3D(-0.5, -0.5, -0.5) << QVector3D(-0.5, -0.5,  0.5) << QVector3D(-0.5,  0.5,  0.5) // Left
                 << QVector3D(-0.5,  0.5,  0.5) << QVector3D(-0.5,  0.5, -0.5) << QVector3D(-0.5, -0.5, -0.5)
                 << QVector3D( 0.5, -0.5,  0.5) << QVector3D( 0.5, -0.5, -0.5) << QVector3D( 0.5,  0.5, -0.5) // Right
                 << QVector3D( 0.5,  0.5, -0.5) << QVector3D( 0.5,  0.5,  0.5) << QVector3D( 0.5, -0.5,  0.5)
                 << QVector3D(-0.5,  0.5,  0.5) << QVector3D( 0.5,  0.5,  0.5) << QVector3D( 0.5,  0.5, -0.5) // Top
                 << QVector3D( 0.5,  0.5, -0.5) << QVector3D(-0.5,  0.5, -0.5) << QVector3D(-0.5,  0.5,  0.5)
                 << QVector3D(-0.5, -0.5, -0.5) << QVector3D( 0.5, -0.5, -0.5) << QVector3D( 0.5, -0.5,  0.5) // Bottom
                 << QVector3D( 0.5, -0.5,  0.5) << QVector3D(-0.5, -0.5,  0.5) << QVector3D(-0.5, -0.5, -0.5);
    cubeNormals << QVector3D( 0,  0,  1) << QVector3D( 0,  0,  1) << QVector3D( 0,  0,  1) // Front
                << QVector3D( 0,  0,  1) << QVector3D( 0,  0,  1) << QVector3D( 0,  0,  1)
                << QVector3D( 0,  0, -1) << QVector3D( 0,  0, -1) << QVector3D( 0,  0, -1) // Back
                << QVector3D( 0,  0, -1) << QVector3D( 0,  0, -1) << QVector3D( 0,  0, -1)
                << QVector3D(-1,  0,  0) << QVector3D(-1,  0,  0) << QVector3D(-1,  0,  0) // Left
                << QVector3D(-1,  0,  0) << QVector3D(-1,  0,  0) << QVector3D(-1,  0,  0)
                << QVector3D( 1,  0,  0) << QVector3D( 1,  0,  0) << QVector3D( 1,  0,  0) // Right
                << QVector3D( 1,  0,  0) << QVector3D( 1,  0,  0) << QVector3D( 1,  0,  0)
                << QVector3D( 0,  1,  0) << QVector3D( 0,  1,  0) << QVector3D( 0,  1,  0) // Top
                << QVector3D( 0,  1,  0) << QVector3D( 0,  1,  0) << QVector3D( 0,  1,  0)
                << QVector3D( 0, -1,  0) << QVector3D( 0, -1,  0) << QVector3D( 0, -1,  0) // Bottom
                << QVector3D( 0, -1,  0) << QVector3D( 0, -1,  0) << QVector3D( 0, -1,  0);
    cubeTextureCoordinates << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Front
                           << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
                           << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Back
                           << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
                           << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Left
                           << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
                           << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Right
                           << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
                           << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Top
                           << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0)
                           << QVector2D(0, 0) << QVector2D(1, 0) << QVector2D(1, 1) // Bottom
                           << QVector2D(1, 1) << QVector2D(0, 1) << QVector2D(0, 0);

    */

    //! [1]
    // PreparationObjet.cpp ->envoyer les vertices vers le buffer graphic card
    /*
    numCubeVertices = 36;

    cubeBuffer.create();
    cubeBuffer.bind();
    cubeBuffer.allocate(numCubeVertices * (3 + 3 + 2) * sizeof(GLfloat));

    int offset = 0;
    cubeBuffer.write(offset, cubeVertices.constData(), numCubeVertices * 3 * sizeof(GLfloat));
    offset += numCubeVertices * 3 * sizeof(GLfloat);
    cubeBuffer.write(offset, cubeNormals.constData(), numCubeVertices * 3 * sizeof(GLfloat));
    offset += numCubeVertices * 3 * sizeof(GLfloat);
    cubeBuffer.write(offset, cubeTextu  reCoordinates.constData(), numCubeVertices * 2 * sizeof(GLfloat));

    cubeBuffer.release();
    */
    //! [1]
    // MesObjets.cpp
    /*
    cubeTexture = bindTexture(QPixmap(":/cubeTexture.png"));
    // preparationObjet.cpp
    coloringShaderProgram.addShaderFromSourceFile(QGLShader::Vertex, ":/coloringVertexShader.vsh");
    coloringShaderProgram.addShaderFromSourceFile(QGLShader::Fragment, ":/coloringFragmentShader.fsh");
    coloringShaderProgram.link();
    */
    // MesObjets.cpp
    /*
    QVector<QVector3D> spotlightVertices;
    QVector<QVector3D> spotlightColors;

    spotlightVertices << QVector3D(   0,    1,    0) << QVector3D(-0.5,    0,  0.5) << QVector3D( 0.5,    0,  0.5) // Front
                      << QVector3D(   0,    1,    0) << QVector3D( 0.5,    0, -0.5) << QVector3D(-0.5,    0, -0.5) // Back
                      << QVector3D(   0,    1,    0) << QVector3D(-0.5,    0, -0.5) << QVector3D(-0.5,    0,  0.5) // Left
                      << QVector3D(   0,    1,    0) << QVector3D( 0.5,    0,  0.5) << QVector3D( 0.5,    0, -0.5) // Right
                      << QVector3D(-0.5,    0, -0.5) << QVector3D( 0.5,    0, -0.5) << QVector3D( 0.5,    0,  0.5) // Bottom
                      << QVector3D( 0.5,    0,  0.5) << QVector3D(-0.5,    0,  0.5) << QVector3D(-0.5,    0, -0.5);
    spotlightColors << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) // Front
                    << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) // Back
                    << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) // Left
                    << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) << QVector3D(0.2, 0.2, 0.2) // Right
                    << QVector3D(  1,   1,   1) << QVector3D(  1,   1,   1) << QVector3D(  1,   1,   1) // Bottom
                    << QVector3D(  1,   1,   1) << QVector3D(  1,   1,   1) << QVector3D(  1,   1,   1);
*/
    //! [2]
    // preparationObjets.cpp
    /*
    numSpotlightVertices = 18;

    spotlightBuffer.create();
    spotlightBuffer.bind();
    spotlightBuffer.allocate(numSpotlightVertices * (3 + 3) * sizeof(GLfloat));

    offset = 0;
    cubeBuffer.write(offset, spotlightVertices.constData(), numSpotlightVertices * 3 * sizeof(GLfloat));
    offset += numSpotlightVertices * 3 * sizeof(GLfloat);
    cubeBuffer.write(offset, spotlightColors.constData(), numSpotlightVertices * 3 * sizeof(GLfloat));

    spotlightBuffer.release();
    */


}
//! [2]

void GLWidget::resizeGL(int width, int height)
{

    if (height == 0) {
        height = 1;
    }
    // glConfig.cpp
    //configurerGL(getPMatrix());

    pMatrix.setToIdentity();
    pMatrix.perspective(60.0, (float) width / (float) height, 0.001, 1000);

    glViewport(0, 0, width, height);
}

//! [3]
void GLWidget::paintGL(QList<AbstractObjet> &mesObjets)
{
    preparation.chargerObjets(mesObjets);
    //! [3]
    // GLConfig.cpp

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QMatrix4x4 mMatrix;
    QMatrix4x4 vMatrix;


    QMatrix4x4 cameraTransformation;
    cameraTransformation.rotate(alpha, 0, 1, 0);
    cameraTransformation.rotate(beta, 1, 0, 0);

    QVector3D cameraPosition = cameraTransformation * QVector3D(0, 0, distance);
    QVector3D cameraUpDirection = cameraTransformation * QVector3D(0, 1, 0);

    vMatrix.lookAt(cameraPosition, QVector3D(0, 0, 0), cameraUpDirection);

    mMatrix.setToIdentity();
        // preparationObjet.cpp

    QMatrix4x4 mvMatrix;
    mvMatrix = vMatrix * mMatrix;

    QMatrix3x3 normalMatrix;
    normalMatrix = mvMatrix.normalMatrix();

    QMatrix4x4 lightTransformation;
    lightTransformation.rotate(lightAngle, 0, 1, 0);

    QVector3D lightPosition = lightTransformation * QVector3D(0, 1, 1);

    program.bind();


    //! [4]
    cubeBuffer.bind();
    int offset = 0;
    program.setAttributeBuffer("vertex", GL_FLOAT, offset, 3, 0);
    program.enableAttributeArray("vertex");
    offset += numCubeVertices * 3 * sizeof(GLfloat);
    program.setAttributeBuffer("normal", GL_FLOAT, offset, 3, 0);
    program.enableAttributeArray("normal");
    offset += numCubeVertices * 3 * sizeof(GLfloat);
    program.setAttributeBuffer("textureCoordinate", GL_FLOAT, offset, 2, 0);
    program.enableAttributeArray("textureCoordinate");
    cubeBuffer.release();

    // reste ici
//    for (int i; i<mesObjets.mesObjetsClassiques.size(); i++){
//        // appel a une methode de preparationObjets

//        ;//glDrawArrays(PRIMITIVE_FACE, 0, numCubeVertices);
//    }
    /*
    //! [4]
    // preparationObjet.cpp
    program.disableAttributeArray("vertex");
    program.disableAttributeArray("normal");
    program.disableAttributeArray("textureCoordinate");

    program.release();

    mMatrix.setToIdentity();
    mMatrix.translate(lightPosition);
    mMatrix.rotate(lightAngle, 0, 1, 0);
    mMatrix.rotate(45, 1, 0, 0);
    mMatrix.scale(0.1);

    coloringShaderProgram.bind();

    coloringShaderProgram.setUniformValue("mvpMatrix", pMatrix * vMatrix * mMatrix);

    //! [5]
    spotlightBuffer.bind();
    offset = 0;
    coloringShaderProgram.setAttributeBuffer("vertex", GL_FLOAT, offset, 3, 0);
    coloringShaderProgram.enableAttributeArray("vertex");
    offset += numSpotlightVertices * 3 * sizeof(GLfloat);
    coloringShaderProgram.setAttributeBuffer("color", GL_FLOAT, offset, 3, 0);
    coloringShaderProgram.enableAttributeArray("color");
    spotlightBuffer.release();
    */
    // reste ici
    //glDrawArrays(PRIMITIVE_FACE, 0, numSpotlightVertices);
    //! [5]
    // preparationObjet.cpp
    /*
    coloringShaderProgram.disableAttributeArray("vertex");
    coloringShaderProgram.disableAttributeArray("color");

    coloringShaderProgram.release();
    */
    //! [6]
}

void GLWidget::chargerObjets(QList<AbstractObjet> &nouveauxObjets)
{
    for (int i=0; i<nouveauxObjets.size();i++){

        objetsAbstraitsBuffer[OBJETCLASSIQUE].append(QGLBuffer());
        objetsAbstraitsBuffer[OBJETCLASSIQUE].last().create();
        objetsAbstraitsBuffer[OBJETCLASSIQUE].last().bind();
        objetsAbstraitsBuffer[OBJETCLASSIQUE].last().allocate(3 * nouveauxObjets.at(i).getForme().size() * sizeof(GLfloat));
        objetsAbstraitsBuffer[OBJETCLASSIQUE].last().write(0, nouveauxObjets.at(i).getForme().constData(), nouveauxObjets.at(i).getForme().size() * 3 * sizeof(GLfloat));
        objetsAbstraitsBuffer[OBJETCLASSIQUE].last().release();


        // Rajouter si on veut des textures
    }
}
//! [6]
// Modifié tout ce qui apres et mettre sa dans utilisateur.cpp (IHM)

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    lastMousePosition = event->pos();


    event->accept();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int deltaX = event->x() - lastMousePosition.x();
    int deltaY = event->y() - lastMousePosition.y();

    if (event->buttons() & Qt::LeftButton) {
        alpha -= deltaX;
        while (alpha < 0) {
            alpha += 360;
        }
        while (alpha >= 360) {
            alpha -= 360;
        }

        beta -= deltaY;
        if (beta < -90) {
            beta = -90;
        }
        if (beta > 90) {
            beta = 90;
        }
    }


    lastMousePosition = event->pos();

    event->accept();

     emit deplacement(event); // Signal qui sera capturé par QLabel de MyWindow
}




void GLWidget::wheelEvent(QWheelEvent *event)
{
    int delta = event->delta();

    if (event->orientation() == Qt::Vertical) {
        if (delta < 0) {
            distance *= 1.1;
        } else if (delta > 0) {
            distance *= 0.9;
        }
    }

    event->accept();
}

void GLWidget::timeout()
{
    lightAngle += 1;
    while (lightAngle >= 360) {
        lightAngle -= 360;
    }


    updateGL();
}

