QT += core gui opengl

TARGET = buffer-objects

TEMPLATE = app

SOURCES += main.cpp\
    MesObjets.cpp \
    ObjetClassique.cpp \
    SphereVision.cpp \
    GlWidget.cpp \
    SystemeVision.cpp \
    FreeFlyVision.cpp \
    TempsGL.cpp

HEADERS += \
    MesObjets.h \
    ObjetClassique.h \
    SphereVision.h \
    GlWidget.h \
    SystemeVision.h \
    FreeFlyVision.h \
    TempsGL.h

OTHER_FILES += coloringFragmentShader.fsh\
               coloringVertexShader.vsh\
               lightingFragmentShader.fsh\
               lightingVertexShader.vsh \
    Procédure.txt

RESOURCES += resources.qrc
