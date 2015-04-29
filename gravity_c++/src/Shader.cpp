#include "Shader.h"
//!
//! \brief Shader::Shader
//!
Shader::Shader()
{
    listeShaders = QStringList() << ":/coloringVertexShader.vsh" << ":/coloringFragmentShader.fsh";
    // Exception si aucun shader n'est trouve
    programsCourant.addShaderFromSourceCode(QGLShader::Vertex, listeShaders.at(1)); // Les shaders sont classes par ordre alphabetique v>f
    programsCourant.addShaderFromSourceCode(QGLShader::Fragment, listeShaders.at(0));
    programsCourant.link();

    //nomProgramsCourant = QString(QFileInfo(listeShaders.at(0)).fileName().append()).section('.',0,0);

}

Shader::Shader(const Shader &other)
{

}

void Shader::listerPrograms()
{
    QDir dir(QString("shaders/"));

    listeShaders.append(dir.entryList(QDir::Files, QDir::Name));
}



//!
//! \brief Shader::shaderGL charge le shader pré-sélectionné
//!
void Shader::chargementShaderGL()
{
    // lumieres shaders
//    lightingShaderProgram.addShaderFromSourceFile(QGLShader::Vertex, ":/lightingVertexShader.vsh");
//    lightingShaderProgram.addShaderFromSourceFile(QGLShader::Fragment, ":/lightingFragmentShader.fsh");
//    lightingShaderProgram.link();

//    coloringShaderProgram.addShaderFromSourceFile(QGLShader::Vertex, ":/coloringVertexShader.vsh");
//    coloringShaderProgram.addShaderFromSourceFile(QGLShader::Fragment, ":/coloringFragmentShader.fsh");
//    coloringShaderProgram.link();
}


