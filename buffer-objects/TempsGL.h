#ifndef TEMPSGL_H
#define TEMPSGL_H

#include <QTimer>
#include <QTime>

class GlWidget;

enum {HOUR, MIN, SEC, MS};

class TempsGL : public QTimer
{
    Q_OBJECT
public:
    TempsGL(GlWidget *_ref, float ips);


    QTime getTemps() const;
    void setTemps(int h, int m, int s, int ms);

    QString tempsToString(const QString &format);

    int getTimeElapsedMs();

    void pause();
    void unpause();

    float getIps() const;
    void setIps(float value);

    bool getIsPause() const;
    void setIsPause(bool value);

    static int timeToMs(QTime date); // date heure de la journée hh:mm:ss:zzzz
    static int timeToMs(int h, int m, int s, int ms); // date heure de la journée hh:mm:ss:zzzz

    static QTime msToTime(int ms);
    static int msToTimeH(int ms);
    static int msToTimeM(int ms); // Retourne seulement les minutes du temps (ie: 7 200 000 = 0 car 7 200 000 = 2h:00m:00s:000ms)
    static int msToTimeS(int ms);
    static int msToTimeMS(int ms);
private:
    GlWidget* ref;
    float ips;

    int hmsms[4]; // Hour, Minute, Sec, MiliSec
    int hmsmsBis[4]; // To unpause

    bool isPause; // flag

    QTime temps;
    QTime tmp; // Afin de pouvoir comparer


private Q_SLOTS:
    void tic();

};

#endif // TEMPSGL_H
