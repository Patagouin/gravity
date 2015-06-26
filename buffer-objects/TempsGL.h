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

    void calculerTemps();

    QString tempsToString(const QString &format, const QString &delimit);

    int getTimeElapsedMs();

    void pause();
    void unpause();



    static int timeToMs(QTime date); // date heure de la journée hh:mm:ss:zzzz
    static int timeToMs(int h, int m, int s, int ms); // date heure de la journée hh:mm:ss:zzzz
    static int timeToMs(int *_hmsms);

    static QTime msToTime(int ms);
    static void msToTime(int ms, int *time);

    static int msToTimeH(int ms);
    static int msToTimeM(int ms); // Retourne seulement les minutes du temps (ie: 7 200 000 = 0 car 7 200 000 = 2h:00m:00s:000ms)
    static int msToTimeS(int ms);
    static int msToTimeMS(int ms);

    static int msToNbH(int ms);
    static int msToNbM(int ms); // Retourne seulement les minutes du temps (ie: 7 200 000 = 0 car 7 200 000 = 2h:00m:00s:000ms)
    static int msToNbS(int ms);

    void getTemps(int *src); //effet de bord
    int getTempsH();
    int getTempsM();
    int getTempsS();
    int getTempsMs();



    void setTemps(int h, int m, int s, int ms);

    float getIps() const;
    void setIps(float value);

    bool getIsPause() const;
    void setIsPause(bool value);
private:
    GlWidget* ref;
    float ips;

    int temps[4]; // Hour, Minute, Sec, MiliSec


    int hmsms[4]; // Hour, Minute, Sec, MiliSec

    bool isPause; // flag

    QTime tempsUtilitaire;


private Q_SLOTS:
    void tic();

};

#endif // TEMPSGL_H
