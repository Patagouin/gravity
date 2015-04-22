#ifndef TEXTURE_H
#define TEXTURE_H

#include <QGLBuffer>
#include <QStringList>
#include <QDir>
#include <QString>

class Texture
{
public:
    Texture();
    void chargementTextureGL();
    void listerTextures(); //charge les noms des fichiers

private:

     QStringList *listeTextures;

    GLuint cubeTexture;

};

#endif // TEXTURE_H
