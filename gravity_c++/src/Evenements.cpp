#include "Evenements.h"

Evenements::Evenements(Simulation *simu)
{
    simu = simu;
}

void Evenements::mousePressEvent(QMouseEvent *event)
{
    lastMousePosition = event->pos();

    event->accept();
}

void Evenements::mouseMoveEvent(QMouseEvent *event)
{
    int deltaX = event->x() - lastMousePosition.x();
    int deltaY = event->y() - lastMousePosition.y();

    if (event->buttons() & Qt::LeftButton) {
        alpha -= deltaX;
        while (alpha < 0)
            alpha += 360;

        while (alpha >= 360)
            alpha -= 360;


        beta -= deltaY;
        if (beta < -90)
            beta = -90;

        if (beta > 90)
            beta = 90;

    }


    lastMousePosition = event->pos();

    event->accept();

     emit deplacement(event); // Signal qui sera capturé par QLabel de MyWindow
}




void Evenements::wheelEvent(QWheelEvent *event)
{
    int delta = event->delta();

    if (event->orientation() == Qt::Vertical) {
        if (delta < 0)
            distance *= 1.1;
         else if (delta > 0)
            distance *= 0.9;

    }

    event->accept();
}
/*
QMatrix4x4 mMatrix;
QMatrix4x4 vMatrix;


QMatrix4x4 cameraTransformation;
cameraTransformation.rotate(alpha, 0, 1, 0);
cameraTransformation.rotate(beta, 1, 0, 0);

QVector3D cameraPosition = cameraTransformation * QVector3D(0, 0, distance);
QVector3D cameraUpDirection = cameraTransformation * QVector3D(0, 1, 0);

vMatrix.lookAt(cameraPosition, QVector3D(0, 0, 0), cameraUpDirection);

mMatrix.setToIdentity();
*/
/*
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

lightingShaderProgram.setUniformValue("ambientColor", QColor(32, 32, 32));
lightingShaderProgram.setUniformValue("diffuseColor", QColor(128, 128, 128));
lightingShaderProgram.setUniformValue("specularColor", QColor(255, 255, 255));
lightingShaderProgram.setUniformValue("ambientReflection", (GLfloat) 1.0);
lightingShaderProgram.setUniformValue("diffuseReflection", (GLfloat) 1.0);
lightingShaderProgram.setUniformValue("specularReflection", (GLfloat) 1.0);
lightingShaderProgram.setUniformValue("shininess", (GLfloat) 100.0);
lightingShaderProgram.setUniformValue("texture", 0);

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
cubeBuffer.release();
*/
/*//! [4]
    // preparationObjet.cpp
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
    */
/*coloringShaderProgram.disableAttributeArray("vertex");
    coloringShaderProgram.disableAttributeArray("color");

    coloringShaderProgram.release();
    */
/*alpha = 25;
    beta = -25;
    distance = 2.5;
    lightAngle = 0;
    */
