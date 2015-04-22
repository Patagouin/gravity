#include "GLConfigs.h"


GLConfigs::GLConfigs()
{
}

GLConfigs::~GLConfigs()
{
}

GLConfigs::declencherInitializeGL(){ // sera deplacer dans simulation
    initializeGL(); // appel dans cette f° a configurerGL
}

GLConfigs::configurerGL() //QMatrix4x4 matriceProjection dans les parametres
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
