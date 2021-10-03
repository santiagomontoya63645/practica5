#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "objetos.h"
#include "logica.h"
#include <QKeyEvent>
#include <QTimer>
#include <QIcon>
#include <time.h>
#include <ctime>
#include <vector>
#include <QMediaPlayer>

#define columnas 23
#define filas 13
#define pixeles 60

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void mover();
    void explotar();
    void morir();
    void muerte_enemigo1();
    void muerte_enemigo2();
    void muerte_enemigo3();
    void muerte_enemigo4();
    void muerte_enemigo5();
    void muerte_enemigo6();
public:
    void keyPressEvent(QKeyEvent *i);
    void setup_mainwindow(); //Mostrar la pantalla como se desea
    void generar_mapa();
    void generar_enemigos();
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    objetos *Bomber;
    objetos *bomba;
    objetos *bombar;
    objetos *bombal;
    objetos *bombau;
    objetos *bombad;
    objetos *enemigo1;
    objetos *enemigo2;
    objetos *enemigo3;
    objetos *enemigo4;
    objetos *enemigo5;
    objetos *enemigo6;
    QTimer *time;
    QTimer *tiMuerte1;
    QTimer *tiMuerte2;
    QTimer *tiMuerte3;
    QTimer *tiMuerte4;
    QTimer *tiMuerte5;
    QTimer *tiMuerte6;
    objetos *mapa[columnas][filas], *puntaje;
    logica *l_mapa;
    QMediaPlayer * bsound;
    QMediaPlayer * esound;
    QMediaPlayer * msound;
    QMediaPlayer * music;
    QString movimientos[12];
    QString bombas[9];
    QString ladrillos[2];
    QString valcomsprite[11];
    QString onealsprite[7];
    QString muerte[7];
    int matriz[columnas][filas];
    int posx=60,posy=180,posxb,posyb,pose1x,pose1y,pose2x,pose2y,pose3x,pose3y,pose4x,pose4y,pose5x,pose5y,pose6x,pose6y,vidas=3,contm=0,contmv=6;
    int contd=3,contf=0,conti=6,contp=9,pasos=0,exp=0,cont1=3,cont2=3,cont3=3,cont4=3,cont5=3,cont6=3,mov=1,mov1=1,mov2=1,mov3=1,mov4=1,mov5=1,enemigos=6,puntos=0,level=1,levelant=1,puntosglob=0;
    bool r=false,l=false,u=false,d=false,bomb=false, bandmuerte=true; //Necesarios, sino se comprueba que se activó un extremo de la bomba y se elimina, el programa crashea
};

#endif // MAINWINDOW_H
