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
    void configurerGL(); //QMatrix4x4 matriceProjection dans les parametres

    bool getTestProfondeur() const;
    void setTestProfondeur(bool value);

    bool getTestCoteFace() const;
    void setTestCoteFace(bool value);

private:

    bool testProfondeur;
    bool testCoteFace;

};

#endif // GLCONFIGS_H
