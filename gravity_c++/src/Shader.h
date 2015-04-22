#ifndef SHADER_H
#define SHADER_H
#include <QGLShaderProgram>
#include <QGLBuffer>
#include <QHash>
#include <QStringList>
#include <QDir>

class Shader
{
public:
    Shader();
    void listerPrograms();
    void chargementShaderGL();
    QString nomProgramsCourant;
    QGLShaderProgram programsCourant;
private:
    QStringList *listeShaders;

    QGLBuffer spotlightBuffer;
};

#endif // SHADER_H
