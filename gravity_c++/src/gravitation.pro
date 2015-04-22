QT += core gui opengl

TARGET = gravitation

TEMPLATE = app

SOURCES +=\
    AbstractObjet.cpp \
    Camera.cpp \
    Lampe.cpp \
    MesObjets.cpp \
    Micro.cpp \
    Monde.cpp \
    ObjetClassique.cpp \
    main.cpp \
    MyWindow.cpp \
    PreparationObjet.cpp \
    Temps.cpp \
    GLWidget.cpp \
    GLConfigs.cpp \
    Physique.cpp \
    Simulation.cpp \
    VueUtilisateur.cpp \
    Evenements.cpp \
    Shader.cpp \
    Texture.cpp


HEADERS += \
    AbstractObjet.h \
    Camera.h \
    Lampe.h \
    MesObjets.h \
    Micro.h \
    Monde.h \
    ObjetClassique.h \
    MyWindow.h \
    PreparationObjet.h \
    Temps.h \
    GLWidget.h \
    GLConfigs.h \
    Physique.h \
    Simulation.h \
    VueUtilisateur.h \
    Evenements.h \
    Shader.h \
    Texture.h

OTHER_FILES += \
    programs/coloringFragmentShader.fsh \
    programs/lightingFragmentShader.fsh \
    programs/coloringVertexShader.vsh \
    programs/lightingVertexShader.vsh \
    textures/cubeTexture.png



