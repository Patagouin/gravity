#include <QMouseEvent>
#include <QWheelEvent>
#include <QString>

#include "GlWidget.h"
#include "utilsgl.h"

#define IPS 60.0
#define INFO_TOP_X 20 // En pixel
#define INFO_TOP_Y 20 // En pixel
#define ECART_X 0 // En pixel
#define ECART_Y 10 // En pixel
#define MIN_SIZE_TO_DISPLAY_INFO_X 150
#define MIN_SIZE_TO_DISPLAY_INFO_Y 150
#define NB_LUMIERE_MAX 32

#ifdef WIN32
    #include <GL/glext.h>
    PFNGLACTIVETEXTUREPROC pGlActiveTexture = NULL;
    #define glActiveTexture pGlActiveTexture
#endif //WIN32

GlWidget::GlWidget(MesObjets _objets,  MesLumieres _lumieres, QWidget *parent)
    : QGLWidget(QGLFormat(/* Additional format options */), parent), mesObjets(_objets),
      mesLumieres(_lumieres), sv(SystemeVision(spherique,this->size(), IPS))
{


    temps = new TempsGL(this, IPS);


}

GlWidget::~GlWidget()
{
    delete(temps);
}

QSize GlWidget::sizeHint() const
{
    return QSize(640, 480);
}

void GlWidget::updateView()
{
    float vitesseRotationLampe = 1; // 1/x tour par sec
    int hmsms[4];
    temps->getTemps(hmsms);

    int ms = TempsGL::timeToMs(hmsms);
    lightAngle = vitesseRotationLampe * (ms/1000.0) * 360.;
    while (lightAngle >= 360) {
        lightAngle -= 360;
    }
    updateGL();
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

    nbVertices = 0;
    for (int i = 0; i < mesObjets.objets.size(); i++)
        nbVertices += mesObjets.objets.at(i).getForme().size();


    objetsBuffer.create();
    objetsBuffer.bind(); // associe le buffer au context actuelle
    objetsBuffer.allocate(nbVertices * 6 * sizeof(GLfloat));

    int offset = 0;
    for (int i = 0; i < mesObjets.objets.size(); i++){
        objetsBuffer.write(offset, mesObjets.objets.at(i).getForme().constData(), mesObjets.objets.at(i).getForme().size() * 3 * sizeof(GLfloat));
        offset += mesObjets.objets.at(i).getForme().size() * 3 * sizeof(GLfloat);
    }

    // Données de rendu envoyé au gpu
    for (int i = 0; i < mesObjets.objets.size(); i++){

        if (mesObjets.objets.at(i).getNormales().size() != mesObjets.objets.at(i).getForme().size()){
            QVector <QVector3D> dstNormales;

            calculateNormales(mesObjets.objets.at(i).getForme(), dstNormales);
            mesObjets.objets[i].setNormales(dstNormales);
        }
        objetsBuffer.write(offset, mesObjets.objets.at(i).getNormales().constData() ,mesObjets.objets.at(i).getForme().size() * 3 * sizeof(GLfloat));
        offset += mesObjets.objets.at(i).getForme().size() * 3 * sizeof(GLfloat);
    }
    /*
    for (int i = 0; i < mesObjets.objets.size(); i++){
        objetsBuffer.write(offset, mesObjets.objets.at(i).getTextureCoords().constData(), (nbVertices/mesObjets.objets.size()) * 2 * sizeof(GLfloat));
        offset += (nbVertices/mesObjets.objets.size()) * 2 * sizeof(GLfloat);
    }*/

    objetsBuffer.release();

    // Données de physique envoyé au gpu

//    simuBuffer.create();
//    simuBuffer.bind();
//    simuBuffer.allocate(nbVertices * (1 + 3) * sizeof(GLfloat)); // (masse, centre)
//    offset = 0;
//    for (int i = 0; i < mesObjets.objets.size(); i++){
//        for (int j = 0; j < mesObjets.objets.at(i).getForme().size(); j++){
//            simuBuffer.write(offset, mesObjets.objets.at(i).getMasse() , sizeof(GLfloat));
//            offset += sizeof(GLfloat);
//        }
//    }
//    for (int i = 0; i < mesObjets.objets.size(); i++){
//        for (int j = 0; j < mesObjets.objets.at(i).getForme().size(); j++){
//            simuBuffer.write(offset, mesObjets.objets.at(i).getCentre() , 3 * sizeof(GLfloat));
//            offset += 3 * sizeof(GLfloat);
//        }
//    }

//    simuBuffer.release();



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
    objetsBuffer.write(offset, spotlightVertices.constData(), numSpotlightVertices * 3 * sizeof(GLfloat));
    offset += numSpotlightVertices * 3 * sizeof(GLfloat);
    objetsBuffer.write(offset, spotlightColors.constData(), numSpotlightVertices * 3 * sizeof(GLfloat));

    spotlightBuffer.release();
}
//! [2]

void GlWidget::resizeGL(int width, int height)
{
    if (height == 0) {
        height = 1;
    }
    sv.changeTailleAffichage(QSize(width, height));
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
    if (mesLumieres.lumieres.size() > NB_LUMIERE_MAX){
        qDebug() << "Seul les premieres lumieres ont été prises en compte";
    }
    for (int i = 0; i < mesLumieres.lumieres.size(); i++){
        if (i < NB_LUMIERE_MAX){
            lightingShaderProgram.setUniformValue("lightPosition", vMatrix * lightPosition);

            lightingShaderProgram.setUniformValue("absoluteLightPosition", lightPosition); // Pour réduir l'effet du diffuse cela la distance

        }
    }
    lightingShaderProgram.setUniformValue("ambientColor", QColor(17, 17, 17));
    lightingShaderProgram.setUniformValue("diffuseColor", QColor(64, 255, 64));
    lightingShaderProgram.setUniformValue("specularColor", QColor(0, 255, 0));
    lightingShaderProgram.setUniformValue("ambientReflection", (GLfloat) 1.0);
    lightingShaderProgram.setUniformValue("diffuseReflection", (GLfloat) 1.0);
    lightingShaderProgram.setUniformValue("specularReflection", (GLfloat) 1.0);
    lightingShaderProgram.setUniformValue("shininess", (GLfloat) 200.0);
    lightingShaderProgram.setUniformValue("texture", 0);


    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, cubeTexture);
    glActiveTexture(0);

    //! [4]
    objetsBuffer.bind();
    int offset = 0;


    lightingShaderProgram.setAttributeBuffer("vertex", GL_FLOAT, offset, 3, 0);
    lightingShaderProgram.enableAttributeArray("vertex");
    offset += nbVertices * 3 * sizeof(GLfloat);
    lightingShaderProgram.setAttributeBuffer("normal", GL_FLOAT, offset, 3, 0);
    lightingShaderProgram.enableAttributeArray("normal");
    offset += nbVertices * 3 * sizeof(GLfloat);
//    lightingShaderProgram.setAttributeBuffer("textureCoordinate", GL_FLOAT, offset, 2, 0);
//    lightingShaderProgram.enableAttributeArray("textureCoordinate");
//    offset += nbVertices/2 * 2 * sizeof(GLfloat);

    objetsBuffer.release();

    // Physique
//    simuBuffer.bind();
//    offset = 0;
//    lightingShaderProgram.setAttributeBuffer("masse", GL_FLOAT, offset, 1, 0);
//    lightingShaderProgram.enableAttributeArray("masse");
//    offset += nbVertices * 3 * sizeof(GLfloat);
//    lightingShaderProgram.setAttributeBuffer("normal", GL_FLOAT, offset, 3, 0);
//    lightingShaderProgram.enableAttributeArray("normal");
//    offset += nbVertices * 3 * sizeof(GLfloat);

    glDrawArrays(GL_TRIANGLES, 0, nbVertices);
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

    // Affichage du texte en premier plan
    if (size().height() > MIN_SIZE_TO_DISPLAY_INFO_Y && size().width() > MIN_SIZE_TO_DISPLAY_INFO_X){
        renderText(INFO_TOP_X, INFO_TOP_Y,
                  QString("IPS = " + QString::number(temps->getIps()) ), QFont("Courier") );

        renderText(INFO_TOP_X + ECART_X,
                   INFO_TOP_Y + ECART_Y,
                  QString("Temps = ") + temps->tempsToString("hh:mm:ss:zzz", ":"), QFont("Courier"))  ;
    }

       //! [6]
}

void GlWidget::mousePressEvent(QMouseEvent *event)
{
    sv.mousePressEvent(event);
    updateView();
}

void GlWidget::mouseMoveEvent(QMouseEvent *event)
{
    sv.mouseMoveEvent(event);
    updateView();

}

void GlWidget::wheelEvent(QWheelEvent *event)
{
    sv.wheelEvent(event);
    updateView();

}

void GlWidget::mouseReleaseEvent(QMouseEvent *event)
{
    sv.mouseReleaseEvent(event);
    updateView();
}

void GlWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Space){
        if (temps->getIsPause())
            temps->unpause();
        else
            temps->pause();
    }
}

//! [6]



