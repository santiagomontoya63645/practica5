#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    movimientos[0]= ":/sprites/Sprites/frontal.png";
    movimientos[1]= ":/sprites/Sprites/frontpaso1.png";
    movimientos[2]= ":/sprites/Sprites/frontpaso2.png";
    movimientos[3]= ":/sprites/Sprites/derecha.png";
    movimientos[4]= ":/sprites/Sprites/derechap1.png";
    movimientos[5]= ":/sprites/Sprites/derechap2.png";
    movimientos[6]= ":/sprites/Sprites/izquierda.png";
    movimientos[7]= ":/sprites/Sprites/izquierdap1.png";
    movimientos[8]= ":/sprites/Sprites/izquierdap2.png";
    movimientos[9]= ":/sprites/Sprites/poste.png";
    movimientos[10]= ":/sprites/Sprites/postep1.png";
    movimientos[11]= ":/sprites/Sprites/postep2.png";
    ui->setupUi(this);
    setup_mainwindow();
    generar_mapa();
    Bomber=new objetos(":/sprites/Sprites/frontal.png");
    Bomber->setPos(60,180);
    escena->addItem(Bomber);
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
void MainWindow::keyPressEvent(QKeyEvent *i){
    if(i->key()==Qt::Key_D){
        if(contd==6) {contd=3;}
        if (bandmuerte==true){Bomber->setPixmap(QPixmap(movimientos[contd]).scaled(60,60));}
        if(matriz[int((posx+60)/pixeles)][int((posy)/pixeles)-2]==0 && float(posy)/float(pixeles)==float((posy)/pixeles) && bandmuerte==true){
            Bomber->setPixmap(QPixmap(movimientos[contd]).scaled(60,60));
            Bomber->setX(Bomber->x()+10);
            contd++;
            posx=posx+10;
        }

    }
    else if(i->key()==Qt::Key_S){
        if(contf==3)contf=0;
        if (bandmuerte==true){Bomber->setPixmap(QPixmap(movimientos[contf]).scaled(60,60));}
        if(matriz[int((posx)/pixeles)][int((posy+60)/pixeles)-2]==0 && float(posx)/float(pixeles)==float((posx)/pixeles) && bandmuerte==true){
            Bomber->setPixmap(QPixmap(movimientos[contf]).scaled(60,60));
            Bomber->setY(Bomber->y()+10);
            contf++;
            posy=posy+10;
        }
    }
    else if(i->key()==Qt::Key_A){
        if(conti==9) conti=6;
        if (bandmuerte==true) Bomber->setPixmap(QPixmap(movimientos[conti]).scaled(60,60));
        if(matriz[int((posx-10)/pixeles)][int((posy)/pixeles)-2]==0 && float(posy)/float(pixeles)==float((posy)/pixeles) && bandmuerte==true){
            Bomber->setPixmap(QPixmap(movimientos[conti]).scaled(60,60));
            Bomber->setX(Bomber->x()-10);
            conti++;
            posx=posx-10;
        }
    }
    else if(i->key()==Qt::Key_W){
        if(contp==12) contp=9;
        if (bandmuerte==true) Bomber->setPixmap(QPixmap(movimientos[contp]).scaled(60,60));
        if(matriz[int((posx)/pixeles)][int((posy-10)/pixeles)-2]==0 && float(posx)/float(pixeles)==float((posx)/pixeles) && bandmuerte==true){
            Bomber->setPixmap(QPixmap(movimientos[contp]).scaled(60,60));
            Bomber->setY(Bomber->y()-10);
            contp++;
            posy=posy-10;
        }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
    delete escena;
    delete Bomber;
    for(int x=0; x<columnas; x++) for(int y=0; y<filas; y++) delete mapa[x][y];
    delete l_mapa;
    delete puntaje;
    delete music;
}

