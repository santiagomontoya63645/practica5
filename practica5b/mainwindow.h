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
#define columnas 25
#define filas 13
#define pixeles 60

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void setup_mainwindow();
    void generar_mapa();
    void keyPressEvent(QKeyEvent *i);

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString movimientos[12];
    QGraphicsScene *escena;
    QMediaPlayer * music;
    objetos *Bomber;
    int matriz[columnas][filas];
    int level=1,levelant=1,contd=6,posx=60,posy=180,contf=3,conti=9,contp=9;
    QString ladrillos[2];
    objetos *mapa[columnas][filas], *puntaje;
    logica *l_mapa;
    bool bandmuerte=true;
};
#endif // MAINWINDOW_H
