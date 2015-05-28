QT += core gui opengl

TARGET = buffer-objects

TEMPLATE = app

SOURCES += main.cpp\
    MesObjets.cpp \
    ObjetClassique.cpp \
    GlWidget.cpp

HEADERS += \
    MesObjets.h \
    ObjetClassique.h \
    GlWidget.h

OTHER_FILES += coloringFragmentShader.fsh\
               coloringVertexShader.vsh\
               lightingFragmentShader.fsh\
               lightingVertexShader.vsh \
    Procédure.txt

RESOURCES += resources.qrc
