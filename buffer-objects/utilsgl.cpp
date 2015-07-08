#include "utilsgl.h"

void calculateNormales(QVector<QVector3D> vertices, QVector<QVector3D> &dstNormales){
    QVector3D tmp;

    for (int i =0; i < vertices.size(); i+=3){
        tmp = QVector3D::crossProduct(vertices.at(i+1) - vertices.at(i) , vertices.at(i+2) - vertices.at(i));

        dstNormales << tmp;
        dstNormales << tmp;
        dstNormales << tmp;
    }
}
