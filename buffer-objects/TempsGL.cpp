#include "TempsGL.h"

#include <GlWidget.h>
#include <iostream>
#include <QString>

#define SECTOMS 1000
#define MINTOMS 60000
#define HOURTOMS 3600000

TempsGL::TempsGL(GlWidget *_ref, float _ips) : QTimer(), ref(_ref), ips(_ips)
{
    temps = QTime();
    tmp = QTime();
    temps.start();
    isPause = false;
    hmsms[HOUR] = temps.hour();
    hmsms[MIN]  = temps.minute();
    hmsms[SEC]  = temps.second();
    hmsms[MS] = temps.msec();


    connect(this, SIGNAL(timeout()), this, SLOT(tic()));
    start((1/ips) * SECTOMS); // en ms
}
QTime TempsGL::getTemps() const
{

    return temps;
}
void TempsGL::pause(){
    isPause = true;
    stop();
    qDebug() << "Mise en pause : " << temps.toString("hh:mm:ss:zzz")
             <<  hmsms[HOUR] <<  hmsms[MIN] <<  hmsms[SEC] << hmsms[MS];
    hmsmsBis[HOUR] = temps.hour();
    hmsmsBis[MIN]  = temps.minute();
    hmsmsBis[SEC]  = temps.second();
    hmsmsBis[MS] = temps.msec();
}

void TempsGL::unpause(){
    isPause = false;
    start();

    int msDiff = timeToMs(hmsmsBis[HOUR], hmsmsBis[MIN], hmsmsBis[SEC], hmsmsBis[MS])
                 - timeToMs(hmsms[HOUR], hmsms[MIN], hmsms[SEC], hmsms[MS]);
    int msDiff2 = timeToMs(temps) - msDiff;

    qDebug() << "Unpause : " << temps.toString("hh:mm:ss:zzz") <<
                msToTime(msDiff).toString("hh:mm:ss:zzz") <<
                msToTime(msDiff2).toString("hh:mm:ss:zzz") ;

    hmsms[HOUR] = msToTimeH(msDiff2);
    hmsms[MIN]  = msToTimeM(msDiff2);
    hmsms[SEC] = msToTimeS(msDiff2);
    hmsms[MS] = msToTimeMS(msDiff2);

}


void TempsGL::setTemps(int h, int m, int s, int ms)
{
    temps.setHMS(h, m, s, ms);
}

QString TempsGL::tempsToString(const QString &format)
{
    int msDiff = timeToMs(temps) - timeToMs(hmsms[HOUR], hmsms[MIN],
                                    hmsms[SEC], hmsms[MS]);

    tmp.setHMS(msToTimeH(msDiff), msToTimeM(msDiff),
               msToTimeS(msDiff), msToTimeMS(msDiff));
    return tmp.toString(format);

}

int TempsGL::getTimeElapsedMs()
{
    return temps.restart();
}
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





void TempsGL::tic()
{
    ref->updateView();
}
