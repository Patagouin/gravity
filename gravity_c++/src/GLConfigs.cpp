#include "GLConfigs.h"


GLConfigs::GLConfigs() : testProfondeur(true), testCoteFace(true)
{
}

GLConfigs::~GLConfigs()
{
}



void GLConfigs::configurerGL() //QMatrix4x4 matriceProjection dans les parametres
{
    #ifdef WIN32
        glActiveTexture = (PFNGLACTIVETEXTUREPROC) wglGetProcAddress((LPCSTR) "glActiveTexture"); //Adresse de la fonction gl
    #endif
    if (testProfondeur)
        glEnable(GL_DEPTH_TEST);
    if (testCoteFace)
        glEnable(GL_CULL_FACE);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


bool GLConfigs::getTestProfondeur() const
{
    return testProfondeur;
}

void GLConfigs::setTestProfondeur(bool value)
{
    testProfondeur = value;
}
bool GLConfigs::getTestCoteFace() const
{
    return testCoteFace;
}

void GLConfigs::setTestCoteFace(bool value)
{
    testCoteFace = value;
}


