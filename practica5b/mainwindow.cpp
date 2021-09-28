#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup_mainwindow();
    generar_mapa();
}

void MainWindow::setup_mainwindow()
{
    int sizex, sizey;
    escena = new QGraphicsScene;

    sizex=columnas*pixeles;
    sizey=(filas+2)*pixeles;
    setGeometry(0,0,sizex+2,sizey+2);
    setMinimumSize(sizex+2,sizey+2);
    setMaximumSize(sizex+2,sizey+2);
    setWindowTitle("Bomberman");
    setWindowIcon(QIcon(":/sprites/Sprites/Icono.png"));
    ui->graphicsView->setGeometry(0,0,sizex+2,sizey+2);

    escena->setSceneRect(0,0,sizex,sizey);
    ui->graphicsView->setScene(escena);
}

void MainWindow::generar_mapa()
{
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/Sonidos/music.mp3"));
    music->play();
    int ** m_mapa;
    l_mapa = new logica(columnas,filas);
    if(levelant!=level && l_mapa->p<=0.8) l_mapa->p=l_mapa->p+0.1;
    puntaje = new objetos(pixeles);
    puntaje->resize(pixeles*columnas,pixeles*2);
    puntaje->setX(0);
    puntaje->setY(0);
    m_mapa=l_mapa->generar_mapa();

    for(int x=0;x<columnas;x++){
        for(int y=0;y<filas;y++) {
            mapa[x][y] = new objetos(pixeles);
            mapa[x][y]->setup_tipo(m_mapa[x][y]);
            matriz[x][y]=m_mapa[x][y];
            mapa[x][y]->setX(pixeles*x);
            mapa[x][y]->setY(pixeles*(y+2));
            escena->addItem(mapa[x][y]);
        }
    }
    escena->addItem(puntaje);
}


MainWindow::~MainWindow()
{
    delete ui;
}

