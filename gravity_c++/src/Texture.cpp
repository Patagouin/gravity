#include "Texture.h"

Texture::Texture()
{
}

void Texture::chargementTextureGL()
{
    //cubeTexture = bindTexture(QPixmap(":/cubeTexture.png"));
}

void Texture::listerTextures()
{
    QDir dir(QString("textures/"));


   //listeTextures.append(dir.entryList(QDir::Files, QDir::Name));

}
