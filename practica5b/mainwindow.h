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
    MainWindow(QWidget *parent = nullptr);
    void setup_mainwindow();
    void generar_mapa();
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    QMediaPlayer * music;

    int matriz[columnas][filas];
    int level=1,levelant=1;
    QString ladrillos[2];
    objetos *mapa[columnas][filas], *puntaje;
    logica *l_mapa;
};
#endif // MAINWINDOW_H
