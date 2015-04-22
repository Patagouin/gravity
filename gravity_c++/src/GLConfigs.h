#ifndef GLCONFIGS_H
#define GLCONFIGS_H

#include <QMatrix4x4>
#include "GLWidget.h"

// ???? a inclure ?
#include <QGLBuffer>

class GLConfigs
{

public:
    GLConfigs();
    ~GLConfigs();
    configurerGL(); //QMatrix4x4 matriceProjection dans les parametres
    void declencherInitializeGL();
private:

    bool testProfondeur = true;
    bool testCoteFace = true;

};

#endif // GLCONFIGS_H
