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

#include "GlWidget.h"
#include <QTimer>
#include <QMouseEvent>
#include <QWheelEvent>

#ifdef WIN32
    #include <GL/glext.h>
    PFNGLACTIVETEXTUREPROC pGlActiveTexture = NULL;
    #define glActiveTexture pGlActiveTexture
#endif //WIN32

GlWidget::GlWidget(MesObjets _objets, QWidget *parent)
    : QGLWidget(QGLFormat(/* Additional format options */), parent), mesObjets(_objets), sv(SystemeVision(freeFly,this->size()))
{

    //printf("GLfFly.avancement = %f\n", sv.fFly.getAvancement());


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeout()));
    timer->start(200);

}

GlWidget::~GlWidget()
{
}

QSize GlWidget::sizeHint() const
{
    return QSize(640, 480);
}

//! [0]
void GlWidget::initializeGL()
{
    //! [0]
    #ifdef WIN32
        glActiveTexture = (PFNGLACTIVETEXTUREPROC) wglGetProcAddress((LPCSTR) "glActiveTexture");
    #endif

    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);

    qglClearColor(QColor(Qt::black));

    lightingShaderProgram.addShaderFromSourceFile(QGLShader::Vertex, ":/lightingVertexShader.vsh");
    lightingShaderProgram.addShaderFromSourceFile(QGLShader::Fragment, ":/lightingFragmentShader.fsh");
    lightingShaderProgram.link();



    //! [1]

    numCubeVertices = 0;
    for (int i = 0; i < mesObjets.objets.size(); i++)
        numCubeVertices += mesObjets.objets.at(i).getForme().size();


    cubeBuffer.create();
    cubeBuffer.bind();
    cubeBuffer.allocate(numCubeVertices * (3 + 3 + 2) * sizeof(GLfloat));

    int offset = 0;
    for (int i = 0; i < mesObjets.objets.size(); i++){
        cubeBuffer.write(offset, mesObjets.objets.at(i).getForme().constData(), (numCubeVertices/mesObjets.objets.size()) * 3 * sizeof(GLfloat));
        offset += (numCubeVertices/mesObjets.objets.size()) * 3 * sizeof(GLfloat);
    }
    for (int i = 0; i < mesObjets.objets.size(); i++){
        cubeBuffer.write(offset, mesObjets.objets.at(i).getNormales().constData(), (numCubeVertices/mesObjets.objets.size()) * 3 * sizeof(GLfloat));
        offset += (numCubeVertices/mesObjets.objets.size()) * 3 * sizeof(GLfloat);
    }
    for (int i = 0; i < mesObjets.objets.size(); i++){
        cubeBuffer.write(offset, mesObjets.objets.at(i).getTextureCoords().constData(), (numCubeVertices/mesObjets.objets.size()) * 2 * sizeof(GLfloat));
        offset += (numCubeVertices/mesObjets.objets.size()) * 2 * sizeof(GLfloat);
    }

    cubeBuffer.release();
    //! [1]

    cubeTexture = bindTexture(QPixmap(":/cubeTexture.png"));

    coloringShaderProgram.addShaderFromSourceFile(QGLShader::Vertex, ":/coloringVertexShader.vsh");
    coloringShaderProgram.addShaderFromSourceFile(QGLShader::Fragment, ":/coloringFragmentShader.fsh");
    coloringShaderProgram.link();

    QVector<QVector3D> spotlightVertices;
    QVector<QVector3D> spotlightColors;

    spotlightVertices << QVector3D(   0,    1,    0) << QVector3D(-0.5,    0,  0.5) << QVector3D( 0.5,    0,  0.5) // Front
                      << QVector3D(   0,    1,    0) << QVector3D( 0.5,    0, -0.5) << QVector3D(-0.5,    0, -0.5) // Back
                      << QVector3D(   0,    1,    0) << QVector3D(-0.5,    0, -0.5) << QVector3D(-0.5,    0,  0.5) // Left
                      << QVector3D(   0,    1,    0) << QVector3D( 0.5,    0,  0.5) << QVector3D( 0.5,    0, -0.5) // Right
                      << QVector3D(-0.5,    0, -0.5) << QVector3D( 0.5,    0, -0.5) << QVector3D( 0.5,    0,  0.5) // Bottom
                      << QVector3D( 0.5,    0,  0.5) << QVector3D(-0.5,    0,  0.5) << QVector3D(-0.5,    0, -0.5);
    spotlightColors << QVector3D(0., 0.2, 0.) << QVector3D(0., 0.2, 0.) << QVector3D(0., 0.2, 0.) // Front
                    << QVector3D(0., 0.2, 0.) << QVector3D(0., 0.2, 0.) << QVector3D(0., 0.2, 0.) // Back
                    << QVector3D(0., 0.2, 0.) << QVector3D(0., 0.2, 0.) << QVector3D(0., 0.2, 0.) // Left
                    << QVector3D(0., 0.2, 0.) << QVector3D(0., 0.2, 0.) << QVector3D(0., 0.2, 0.) // Right
                    << QVector3D(  0,   1,   0) << QVector3D(  0,   1,   0) << QVector3D(  0,   1,   0) // Bottom
                    << QVector3D(  0,   1,   0) << QVector3D(  0,   1,   0) << QVector3D(  0,   1,   0);

    //! [2]
    numSpotlightVertices = 18;

    spotlightBuffer.create();
    spotlightBuffer.bind();
    spotlightBuffer.allocate(numSpotlightVertices * (3 + 3) * sizeof(GLfloat));

    offset = 0;
    cubeBuffer.write(offset, spotlightVertices.constData(), numSpotlightVertices * 3 * sizeof(GLfloat));
    offset += numSpotlightVertices * 3 * sizeof(GLfloat);
    cubeBuffer.write(offset, spotlightColors.constData(), numSpotlightVertices * 3 * sizeof(GLfloat));

    spotlightBuffer.release();
}
//! [2]

void GlWidget::resizeGL(int width, int height)
{
    if (height == 0) {
        height = 1;
    }

    pMatrix.setToIdentity();
    pMatrix.perspective(60.0, (float) width / (float) height, 0.001, 1000);

    glViewport(0, 0, width, height);
}

//! [3]
void GlWidget::paintGL()
{
    //! [3]
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    QMatrix4x4 vMatrix;



    sv.computeViewMatrix();
    vMatrix = sv.getViewMatrix();

    QMatrix4x4 mMatrix;
    mMatrix.setToIdentity();

    QMatrix4x4 mvMatrix;
    mvMatrix = vMatrix * mMatrix;

    QMatrix3x3 normalMatrix;
    normalMatrix = mvMatrix.normalMatrix();

    QMatrix4x4 lightTransformation;
    lightTransformation.rotate(lightAngle, 0, 1, 0);

    QVector3D lightPosition = lightTransformation * QVector3D(0, 1, 1);

    lightingShaderProgram.bind();

    lightingShaderProgram.setUniformValue("mvpMatrix", pMatrix * mvMatrix);
    lightingShaderProgram.setUniformValue("mvMatrix", mvMatrix);
    lightingShaderProgram.setUniformValue("normalMatrix", normalMatrix);
    lightingShaderProgram.setUniformValue("lightPosition", vMatrix * lightPosition);

    lightingShaderProgram.setUniformValue("ambientColor", QColor(17, 17, 17));
    lightingShaderProgram.setUniformValue("diffuseColor", QColor(64, 255, 64));
    lightingShaderProgram.setUniformValue("specularColor", QColor(0, 255, 0));
    lightingShaderProgram.setUniformValue("ambientReflection", (GLfloat) 1.0);
    lightingShaderProgram.setUniformValue("diffuseReflection", (GLfloat) 1.0);
    lightingShaderProgram.setUniformValue("specularReflection", (GLfloat) 1.0);
    lightingShaderProgram.setUniformValue("shininess", (GLfloat) 200.0);
    lightingShaderProgram.setUniformValue("texture", 0);
    lightingShaderProgram.setUniformValue("absoluteLightPosition", lightPosition); // Pour réduir l'effet du diffuse cela la distance


    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, cubeTexture);
    glActiveTexture(0);

    //! [4]
    cubeBuffer.bind();
    int offset = 0;


    lightingShaderProgram.setAttributeBuffer("vertex", GL_FLOAT, offset, 3, 0);
    lightingShaderProgram.enableAttributeArray("vertex");
    offset += numCubeVertices * 3 * sizeof(GLfloat);
    lightingShaderProgram.setAttributeBuffer("normal", GL_FLOAT, offset, 3, 0);
    lightingShaderProgram.enableAttributeArray("normal");
    offset += numCubeVertices * 3 * sizeof(GLfloat);
    lightingShaderProgram.setAttributeBuffer("textureCoordinate", GL_FLOAT, offset, 2, 0);
    lightingShaderProgram.enableAttributeArray("textureCoordinate");
    offset += numCubeVertices/2 * 2 * sizeof(GLfloat);

    cubeBuffer.release();

    glDrawArrays(GL_TRIANGLES, 0, numCubeVertices);
    //! [4]

    lightingShaderProgram.disableAttributeArray("vertex");
    lightingShaderProgram.disableAttributeArray("normal");
    lightingShaderProgram.disableAttributeArray("textureCoordinate");

    lightingShaderProgram.release();

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

    glDrawArrays(GL_TRIANGLES, 0, numSpotlightVertices);
    //! [5]

    coloringShaderProgram.disableAttributeArray("vertex");
    coloringShaderProgram.disableAttributeArray("color");

    coloringShaderProgram.release();
    //! [6]
}

void GlWidget::mousePressEvent(QMouseEvent *event)
{
    sv.mousePressEvent(event);
}

void GlWidget::mouseMoveEvent(QMouseEvent *event)
{
    sv.mouseMoveEvent(event);
}

void GlWidget::wheelEvent(QWheelEvent *event)
{
    sv.wheelEvent(event);
}
//! [6]



void GlWidget::timeout()
{
    lightAngle += 1;
    while (lightAngle >= 360) {
        lightAngle -= 360;
    }

    updateGL();
}
