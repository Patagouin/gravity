#include "TempsGL.h"

#include <GlWidget.h>
#include <iostream>
#include <QString>

#define SECTOMS 1000
#define MINTOMS 60000
#define HOURTOMS 3600000

TempsGL::TempsGL(GlWidget *_ref, float _ips) : QTimer(), ref(_ref), ips(_ips)
{
    tempsUtilitaire = QTime();
    tempsUtilitaire.start();
    isPause = false;

    temps[HOUR] = 0;
    temps[MIN] = 0;
    temps[SEC] = 0;
    temps[MS] = 0;

    hmsms[HOUR] = tempsUtilitaire.hour();
    hmsms[MIN]  = tempsUtilitaire.minute();
    hmsms[SEC]  = tempsUtilitaire.second();
    hmsms[MS] = tempsUtilitaire.msec();


    connect(this, SIGNAL(timeout()), this, SLOT(tic()));
    start((1/ips) * SECTOMS); // en ms

}

void TempsGL::calculerTemps()
{
    tempsUtilitaire.restart();
    int msDiff = timeToMs(tempsUtilitaire) - timeToMs(hmsms[HOUR], hmsms[MIN],
                                    hmsms[SEC], hmsms[MS]);

    msToTime(msDiff, temps); // Mise à jour de temps

}

void TempsGL::pause(){

    isPause = true;
    //stop(); // Pas de stop cara sinon pas de deplacement de la camera en situation de pause
    calculerTemps(); // tant que isPause = true plus d'appel à calculerTemps
    tic();


}

void TempsGL::unpause(){
    isPause = false;
    //start();

    tempsUtilitaire.restart();
    int msDiff = timeToMs(tempsUtilitaire) - timeToMs(temps[HOUR], temps[MIN], temps[SEC], temps[MS]);
    msToTime(msDiff, hmsms);


}

void TempsGL::getTemps(int *src){
    if (!isPause)
        calculerTemps();
    *src++ = temps[HOUR];
    *src++ = temps[MIN];
    *src++ = temps[SEC];
    *src   = temps[MS];
}

int TempsGL::getTempsH(){
    if (!isPause)
        calculerTemps();
    return temps[HOUR];
}

int TempsGL::getTempsM(){
    if (!isPause)
        calculerTemps();
    return temps[MIN];

}
int TempsGL::getTempsS(){
    if (!isPause)
        calculerTemps();
    return temps[SEC];

}
int TempsGL::getTempsMs(){
    if (!isPause)
        calculerTemps();
    return temps[MS];
}

void TempsGL::setTemps(int h, int m, int s, int ms)
{
    int msDiff = timeToMs(tempsUtilitaire) - timeToMs(h, m, s, ms);
    msToTime(msDiff, hmsms);

    temps[HOUR] = h;
    temps[MIN] = m;
    temps[SEC] = s;
    temps[MS] = ms;

}

QString TempsGL::tempsToString(const QString &format, const QString &delimit)
{
    if (!isPause)
        calculerTemps();
    QString str =  QString();

    if (format.contains("h")){
        str += QString::number(temps[HOUR]);
        if (QString::number(temps[HOUR]).length() == 1 && format.contains("hh"))
            str.insert(0, "0");
    }
    str += delimit;
    if (format.contains("m")){
        str += QString::number(temps[MIN]);
        if (QString::number(temps[MIN]).length() == 1 && format.contains("mm"))
            str.insert(str.length() - 1, "0");
    }
    str += delimit;
    if (format.contains("s")){
        str += QString::number(temps[SEC]);
        if (QString::number(temps[SEC]).length() == 1 && format.contains("mm"))
            str.insert(str.length() - 1, "0");
    }
    str += delimit;
    if (format.contains("z")){
        int nb = format.count("z");
        int size = QString::number(temps[MS]).length();
        QString tmp;
        if (size > nb)
            tmp = QString::number(temps[MS]).remove(size-nb, size-nb);
        else
            tmp =  QString("0").repeated(nb - size) + QString::number(temps[MS]);
        str += tmp;
    }

    return str;
}

//int TempsGL::getTimeElapsedMs()
//{
//    return tempsUtilitaire.restart();
//}

float TempsGL::getIps() const
{
    return ips;
}

void TempsGL::setIps(float value)
{
    ips = value;
}
bool TempsGL::getIsPause() const
{
    return isPause;
}

void TempsGL::setIsPause(bool value)
{
    isPause = value;
}

int TempsGL::timeToMs(QTime date)
{
    return date.msecsSinceStartOfDay();
}

int TempsGL::timeToMs(int h, int m, int s, int ms)
{
    return ms + s*SECTOMS + m*MINTOMS + h*HOURTOMS;
}

int TempsGL::timeToMs(int *_hmsms)
{
    return _hmsms[MS] +  _hmsms[SEC]*SECTOMS + _hmsms[MIN]*MINTOMS + _hmsms[HOUR]*HOURTOMS;
}

QTime TempsGL::msToTime(int ms)
{
    int h = ms / HOURTOMS;
    ms %= HOURTOMS;
    int m = ms / MINTOMS;
    ms %= MINTOMS;
    int s = ms / SECTOMS;
    ms %= SECTOMS;
    return QTime(h, m, s, ms);
}

void TempsGL::msToTime(int ms, int *time) // Fonction à effet de bord
{
    *time++ = ms / HOURTOMS;
    ms %= HOURTOMS;
    *time++ = ms / MINTOMS;
    ms %= MINTOMS;
    *time++ = ms / SECTOMS;
    ms %= SECTOMS;
    *time = ms;
}

int TempsGL::msToTimeH(int ms)
{
    return ms / HOURTOMS;
}

int TempsGL::msToTimeM(int ms)
{
    ms %= HOURTOMS;
    return ms / MINTOMS;

}

int TempsGL::msToTimeS(int ms)
{
    ms %= HOURTOMS;
    ms %= MINTOMS;
    return ms / SECTOMS;
}

int TempsGL::msToTimeMS(int ms)
{
    ms %= HOURTOMS;
    ms %= MINTOMS;
    ms %= SECTOMS;
    return ms;
}

int TempsGL::msToNbH(int ms)
{
    return ms/HOURTOMS;
}

int TempsGL::msToNbM(int ms)
{
    return ms/MINTOMS;
}

int TempsGL::msToNbS(int ms)
{
    return ms/SECTOMS;
}







void TempsGL::tic()
{
    ref->updateView();
}
