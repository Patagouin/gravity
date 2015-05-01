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
#ifndef GLWidget_H
#define GLWidget_H

/* Utilise la classe GLConfig et utilise le module preparation objet */

#include <QGLWidget>
#include "MesObjets.h" // Ne doit pas connaitre le type de données
#include "PreparationObjet.h"
#include "GLConfigs.h"


#include <QGLShaderProgram>
#include <QGLBuffer>

//! [0]
class GLWidget : public QGLWidget
{
    //! [0]
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();
    QSize sizeHint() const;


protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL(MesObjets mesObjets);
    /*
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);
    */

    //! [1]
private:
    //! [1]

    QMatrix4x4 pMatrix;   //plusieurs fois
    /*
    QGLShaderProgram lightingShaderProgram; // 1 fois
    //! [2]
    int numCubeVertices; //1 fois
    QGLBuffer cubeBuffer; //1 fois
    //! [2]
    GLuint cubeTexture; // 1 fois
    QGLShaderProgram coloringShaderProgram; // 1 fois
    //! [3]
    int numSpotlightVertices; // 1 fois
    QGLBuffer spotlightBuffer; // 1 fois
    */
    //! [3]
    /*
    double lightAngle;
    double alpha;
    double beta;
    double distance;
    */
/*
    QPoint lastMousePosition;
*/
/*
private Q_SLOTS:
    void timeout();
    */
/*
Q_SIGNALS:
     void deplacement(QMouseEvent *event);
     */
    //! [4]
};
//! [4]

#endif // GLWidget_H
