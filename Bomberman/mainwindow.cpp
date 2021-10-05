#include "mainwindow.h"
#include "ui_mainwindow.h"
void MainWindow::funcionActivacionTimer(){
    ui->lcdNumber->display(contadorTIEMPO);
    contadorTIEMPO--;
    if(contadorTIEMPO==0) {
        contadorTIEMPO=180;
        vidas=vidas-1;
        ui->label_4->setNum(vidas);
        bandmuerte=false;
        if(bandmuerte==false){
             time=new QTimer;
             time->start(250);
             //vidas=vidas-1;
             //ui->label_4->setNum(vidas);
             connect(time,SIGNAL(timeout()),this,SLOT(morir()));

        }
    }
}
void MainWindow::mover()
{
    if(((posx)/pixeles==pose1x && (posy/pixeles)-2==pose1y) || ((posx)/pixeles==pose2x && (posy/pixeles)-2==pose2y) || ((posx)/pixeles==pose3x && (posy/pixeles)-2==pose3y) || ((posx)/pixeles==pose4x && (posy/pixeles)-2==pose4y) ||((posx)/pixeles==pose5x && (posy/pixeles)-2==pose5y) || ((posx)/pixeles==pose6x && (posy/pixeles)-2==pose6y)){
        if(bandmuerte==true){
            bandmuerte=false;
            vidas=vidas-1;
            ui->label_4->setNum(vidas);
            if(bomb==false){
                time=new QTimer;
                time->start(250);
                connect(time,SIGNAL(timeout()),this,SLOT(morir()));
            }
       }
    }

    if(float(posy)/float(pixeles)!=float((posy)/pixeles)){
        if(((posx)/pixeles==pose1x && (posy/pixeles)-1==pose1y) || ((posx)/pixeles==pose2x && (posy/pixeles)-1==pose2y) || ((posx)/pixeles==pose3x && (posy/pixeles)-1==pose3y) || ((posx)/pixeles==pose4x && (posy/pixeles)-1==pose4y) ||((posx)/pixeles==pose5x && (posy/pixeles)-1==pose5y) || ((posx)/pixeles==pose6x && (posy/pixeles)-1==pose6y)){
            if(bandmuerte==true){
                bandmuerte=false;
                vidas=vidas-1;
                ui->label_4->setNum(vidas);
                if(bomb==false){
                    time=new QTimer;
                    time->start(250);
                    connect(time,SIGNAL(timeout()),this,SLOT(morir()));
                }
           }
        }
    }

    else if(float(posx)/float(pixeles)!=float((posx)/pixeles)){
        if((((posx)/pixeles)+1==pose1x && (posy/pixeles)-2==pose1y) || (((posx)/pixeles)+1==pose2x && (posy/pixeles)-2==pose2y) || (((posx)/pixeles)+1==pose3x && (posy/pixeles)-2==pose3y) || (((posx)/pixeles)+1==pose4x && (posy/pixeles)-2==pose4y) ||(((posx)/pixeles)+1==pose5x && (posy/pixeles)-2==pose5y) || (((posx)/pixeles)+1==pose6x && (posy/pixeles)-2==pose6y)){
            if(bandmuerte==true){
                bandmuerte=false;
                vidas=vidas-1;
                ui->label_4->setNum(vidas);
                if(bomb==false){
                    time=new QTimer;
                    time->start(250);
                    connect(time,SIGNAL(timeout()),this,SLOT(morir()));
                }
           }
        }
    }
    if(mov==1){
        if(matriz[pose1x+1][pose1y]==0){
            if(cont1>5) cont1=3;
            if(level==1) enemigo1->setPixmap(QPixmap(valcomsprite[cont1]).scaled(60,60));
            else enemigo1->setPixmap(QPixmap(onealsprite[cont1]).scaled(60,60));
            enemigo1->setX(enemigo1->x()+60);
            pose1x=pose1x+1;
            cont1++;
        }
        else{
            cont1=0;
            mov=1+rand()%(5-1);
        }
    }
    else if(mov==2){
        if(matriz[pose1x][pose1y+1]==0){
            if(cont1>5) cont1=3;
            if(level==1) enemigo1->setPixmap(QPixmap(valcomsprite[cont1]).scaled(60,60));
            else enemigo1->setPixmap(QPixmap(onealsprite[cont1]).scaled(60,60));
            enemigo1->setY(enemigo1->y()+60);
            pose1y=pose1y+1;
            cont1++;
        }
        else{
            cont1=0;
            mov=1+rand()%(5-1);
        }
    }
    else if(mov==3){
        if(matriz[pose1x-1][pose1y]==0){
            if(cont1>2) cont1=0;
            if(level==1) enemigo1->setPixmap(QPixmap(valcomsprite[cont1]).scaled(60,60));
            else enemigo1->setPixmap(QPixmap(onealsprite[cont1]).scaled(60,60));
            enemigo1->setX(enemigo1->x()-60);
            pose1x=pose1x-1;
            cont1++;
        }
        else{
            cont1=3;
            mov=1+rand()%(5-1);
        }
    }
    else if(mov==4){
        if(matriz[pose1x][pose1y-1]==0){
            if(cont1>2) cont1=0;
            if(level==1) enemigo1->setPixmap(QPixmap(valcomsprite[cont1]).scaled(60,60));
            else enemigo1->setPixmap(QPixmap(onealsprite[cont1]).scaled(60,60));
            enemigo1->setY(enemigo1->y()-60);
            pose1y=pose1y-1;
            cont1++;
        }
        else{
            cont1=0;
            mov=1+rand()%(5-1);
        }
    }

    if(mov1==1){
        if(matriz[pose2x+1][pose2y]==0){
            if(cont2>5) cont2=3;
            if(level==1) enemigo2->setPixmap(QPixmap(valcomsprite[cont2]).scaled(60,60));
            else enemigo2->setPixmap(QPixmap(onealsprite[cont2]).scaled(60,60));
            enemigo2->setX(enemigo2->x()+60);
            pose2x=pose2x+1;
            cont2++;
        }
        else{
            cont2=0;
            mov1=1+rand()%(5-1);
        }
    }
    else if(mov1==2){
        if(matriz[pose2x][pose2y+1]==0){
            if(cont2>5) cont2=3;
            if(level==1) enemigo2->setPixmap(QPixmap(valcomsprite[cont2]).scaled(60,60));
            else enemigo2->setPixmap(QPixmap(onealsprite[cont2]).scaled(60,60));
            enemigo2->setY(enemigo2->y()+60);
            pose2y=pose2y+1;
            cont2++;
        }
        else{
            cont2=0;
            mov1=1+rand()%(5-1);
        }
    }
    else if(mov1==3){
        if(matriz[pose2x-1][pose2y]==0){
            if(cont2>2) cont2=0;
            if(level==1) enemigo2->setPixmap(QPixmap(valcomsprite[cont2]).scaled(60,60));
            else enemigo2->setPixmap(QPixmap(onealsprite[cont2]).scaled(60,60));
            enemigo2->setX(enemigo2->x()-60);
            pose2x=pose2x-1;
            cont2++;
        }
        else{
            cont2=3;
            mov1=1+rand()%(5-1);
        }
    }
    else if(mov1==4){
        if(matriz[pose2x][pose2y-1]==0){
            if(cont2>2) cont2=0;
            if(level==1) enemigo2->setPixmap(QPixmap(valcomsprite[cont2]).scaled(60,60));
            else enemigo2->setPixmap(QPixmap(onealsprite[cont2]).scaled(60,60));
            enemigo2->setY(enemigo2->y()-60);
            pose2y=pose2y-1;
            cont2++;
        }
        else{
            cont2=0;
            mov1=1+rand()%(5-1);
        }
    }

    if(mov2==1){
        if(matriz[pose3x+1][pose3y]==0){
            if(cont3>5) cont3=3;
            if(level==1) enemigo3->setPixmap(QPixmap(valcomsprite[cont3]).scaled(60,60));
            else enemigo3->setPixmap(QPixmap(onealsprite[cont3]).scaled(60,60));
            enemigo3->setX(enemigo3->x()+60);
            pose3x=pose3x+1;
            cont3++;
        }
        else{
            cont3=0;
            mov2=1+rand()%(5-1);
        }
    }
    else if(mov2==2){
        if(matriz[pose3x][pose3y+1]==0){
            if(cont3>5) cont3=3;
            if(level==1) enemigo3->setPixmap(QPixmap(valcomsprite[cont3]).scaled(60,60));
            else enemigo3->setPixmap(QPixmap(onealsprite[cont3]).scaled(60,60));
            enemigo3->setY(enemigo3->y()+60);
            pose3y=pose3y+1;
            cont3++;
        }
        else{
            cont3=0;
            mov2=1+rand()%(5-1);
        }
    }
    else if(mov2==3){
        if(matriz[pose3x-1][pose3y]==0){
            if(cont3>2) cont3=0;
            if(level==1) enemigo3->setPixmap(QPixmap(valcomsprite[cont3]).scaled(60,60));
            else enemigo3->setPixmap(QPixmap(onealsprite[cont3]).scaled(60,60));
            enemigo3->setX(enemigo3->x()-60);
            pose3x=pose3x-1;
            cont3++;
        }
        else{
            cont3=3;
            mov2=1+rand()%(5-1);
        }
    }
    else if(mov2==4){
        if(matriz[pose3x][pose3y-1]==0){
            if(cont3>2) cont3=0;
            if(level==1) enemigo3->setPixmap(QPixmap(valcomsprite[cont3]).scaled(60,60));
            else enemigo3->setPixmap(QPixmap(onealsprite[cont3]).scaled(60,60));
            enemigo3->setY(enemigo3->y()-60);
            pose3y=pose3y-1;
            cont3++;
        }
        else{
            cont3=0;
            mov2=1+rand()%(5-1);
        }
    }

    if(mov3==1){
        if(matriz[pose4x+1][pose4y]==0){
            if(cont4>5) cont4=3;
            if(level==1) enemigo4->setPixmap(QPixmap(valcomsprite[cont4]).scaled(60,60));
            else enemigo4->setPixmap(QPixmap(onealsprite[cont4]).scaled(60,60));
            enemigo4->setX(enemigo4->x()+60);
            pose4x=pose4x+1;
            cont4++;
        }
        else{
            cont4=0;
            mov3=1+rand()%(5-1);
        }
    }
    else if(mov3==2){
        if(matriz[pose4x][pose4y+1]==0){
            if(cont4>5) cont4=3;
            if(level==1) enemigo4->setPixmap(QPixmap(valcomsprite[cont4]).scaled(60,60));
            else enemigo4->setPixmap(QPixmap(onealsprite[cont4]).scaled(60,60));
            enemigo4->setY(enemigo4->y()+60);
            pose4y=pose4y+1;
            cont4++;
        }
        else{
            cont4=0;
            mov3=1+rand()%(5-1);
        }
    }
    else if(mov3==3){
        if(matriz[pose4x-1][pose4y]==0){
            if(cont4>2) cont4=0;
            if(level==1) enemigo4->setPixmap(QPixmap(valcomsprite[cont4]).scaled(60,60));
            else enemigo4->setPixmap(QPixmap(onealsprite[cont4]).scaled(60,60));
            enemigo4->setX(enemigo4->x()-60);
            pose4x=pose4x-1;
            cont4++;
        }
        else{
            cont4=3;
            mov3=1+rand()%(5-1);
        }
    }
    else if(mov3==4){
        if(matriz[pose4x][pose4y-1]==0){
            if(cont4>2) cont4=0;
            if(level==1) enemigo4->setPixmap(QPixmap(valcomsprite[cont4]).scaled(60,60));
            else enemigo4->setPixmap(QPixmap(onealsprite[cont4]).scaled(60,60));
            enemigo4->setY(enemigo4->y()-60);
            pose4y=pose4y-1;
            cont4++;
        }
        else{
            cont4=0;
            mov3=1+rand()%(5-1);
        }
    }

    if(mov4==1){
        if(matriz[pose5x+1][pose5y]==0){
            if(cont5>5) cont5=3;
            if(level==1) enemigo5->setPixmap(QPixmap(valcomsprite[cont5]).scaled(60,60));
            else enemigo5->setPixmap(QPixmap(onealsprite[cont5]).scaled(60,60));
            enemigo5->setX(enemigo5->x()+60);
            pose5x=pose5x+1;
            cont5++;
        }
        else{
            cont5=0;
            mov4=1+rand()%(5-1);
        }
    }
    else if(mov4==2){
        if(matriz[pose5x][pose5y+1]==0){
            if(cont5>5) cont5=3;
            if(level==1) enemigo5->setPixmap(QPixmap(valcomsprite[cont5]).scaled(60,60));
            else enemigo5->setPixmap(QPixmap(onealsprite[cont5]).scaled(60,60));
            enemigo5->setY(enemigo5->y()+60);
            pose5y=pose5y+1;
            cont5++;
        }
        else{
            cont5=0;
            mov4=1+rand()%(5-1);
        }
    }
    else if(mov4==3){
        if(matriz[pose5x-1][pose5y]==0){
            if(cont5>2) cont5=0;
            if(level==1) enemigo5->setPixmap(QPixmap(valcomsprite[cont5]).scaled(60,60));
            else enemigo5->setPixmap(QPixmap(onealsprite[cont5]).scaled(60,60));
            enemigo5->setX(enemigo5->x()-60);
            pose5x=pose5x-1;
            cont5++;
        }
        else{
            cont5=3;
            mov4=1+rand()%(5-1);
        }
    }
    else if(mov4==4){
        if(matriz[pose5x][pose5y-1]==0){
            if(cont5>2) cont5=0;
            if(level==1) enemigo5->setPixmap(QPixmap(valcomsprite[cont5]).scaled(60,60));
            else enemigo5->setPixmap(QPixmap(onealsprite[cont5]).scaled(60,60));
            enemigo5->setY(enemigo5->y()-60);
            pose5y=pose5y-1;
            cont5++;
        }
        else{
            cont5=0;
            mov4=1+rand()%(5-1);
        }
    }

    if(mov5==1){
        if(matriz[pose6x+1][pose6y]==0){
            if(cont6>5) cont6=3;
            if(level==1) enemigo6->setPixmap(QPixmap(valcomsprite[cont6]).scaled(60,60));
            else enemigo6->setPixmap(QPixmap(onealsprite[cont6]).scaled(60,60));
            enemigo6->setX(enemigo6->x()+60);
            pose6x=pose6x+1;
            cont6++;
        }
        else{
            cont6=0;
            mov5=1+rand()%(5-1);
        }
    }
    else if(mov5==2){
        if(matriz[pose6x][pose6y+1]==0){
            if(cont6>5) cont6=3;
            if(level==1) enemigo6->setPixmap(QPixmap(valcomsprite[cont6]).scaled(60,60));
            else enemigo6->setPixmap(QPixmap(onealsprite[cont6]).scaled(60,60));
            enemigo6->setY(enemigo6->y()+60);
            pose6y=pose6y+1;
            cont6++;
        }
        else{
            cont6=0;
            mov5=1+rand()%(5-1);
        }
    }
    else if(mov5==3){
        if(matriz[pose6x-1][pose6y]==0){
            if(cont6>2) cont6=0;
            if(level==1) enemigo6->setPixmap(QPixmap(valcomsprite[cont6]).scaled(60,60));
            else enemigo6->setPixmap(QPixmap(onealsprite[cont6]).scaled(60,60));
            enemigo6->setX(enemigo6->x()-60);
            pose6x=pose6x-1;
            cont6++;
        }
        else{
            cont6=3;
            mov5=1+rand()%(5-1);
        }
    }
    else if(mov5==4){
        if(matriz[pose6x][pose6y-1]==0){
            if(cont6>2) cont6=0;
            if(level==1) enemigo6->setPixmap(QPixmap(valcomsprite[cont6]).scaled(60,60));
            else enemigo6->setPixmap(QPixmap(onealsprite[cont6]).scaled(60,60));
            enemigo6->setY(enemigo6->y()-60);
            pose6y=pose6y-1;
            cont6++;
        }
        else{
            cont6=0;
            mov5=1+rand()%(5-1);
        }
    }
}

void MainWindow::explotar()
{
    bomba->setPixmap(QPixmap(bombas[exp]).scaled(60,60));
    exp++;
    if(exp==4){
        esound->setMedia(QUrl("qrc:/Sonidos/Explo.mp3"));
        esound->play();
        //Animación extremo derecho de bomba
        if(matriz[(posxb+60)/pixeles][(posyb/pixeles)-2]==0 && matriz[(posxb+120)/pixeles][(posyb/pixeles)-2]==0){
            bombar= new objetos();
            bombar->setPos(posxb+60,posyb);
            bombar->setPixmap(QPixmap(bombas[8]).scaled(120,60));
            escena->addItem(bombar);
            r=true;
            if(((posxb)/pixeles==pose1x && (posyb/pixeles)-2==pose1y) || ((posxb+60)/pixeles==pose1x && (posyb/pixeles)-2==pose1y) || ((posxb+120)/pixeles==pose1x && (posyb/pixeles)-2==pose1y)){
                pose1x=0;
                pose1y=0;
                tiMuerte1=new QTimer;
                tiMuerte1->start(250);
                connect(tiMuerte1,SIGNAL(timeout()),this,SLOT(muerte_enemigo1()));
            }
            if(((posxb)/pixeles==pose2x && (posyb/pixeles)-2==pose2y) || ((posxb+60)/pixeles==pose2x && (posyb/pixeles)-2==pose2y) || ((posxb+120)/pixeles==pose2x && (posyb/pixeles)-2==pose2y)){
                pose2x=0;
                pose2y=0;
                tiMuerte2=new QTimer;
                tiMuerte2->start(250);
                connect(tiMuerte2,SIGNAL(timeout()),this,SLOT(muerte_enemigo2()));
            }
            if(((posxb)/pixeles==pose3x && (posyb/pixeles)-2==pose3y) || ((posxb+60)/pixeles==pose3x && (posyb/pixeles)-2==pose3y) || ((posxb+120)/pixeles==pose3x && (posyb/pixeles)-2==pose3y)){
                pose3x=0;
                pose3y=0;
                tiMuerte3=new QTimer;
                tiMuerte3->start(250);
                connect(tiMuerte3,SIGNAL(timeout()),this,SLOT(muerte_enemigo3()));
            }
            if(((posxb)/pixeles==pose4x && (posyb/pixeles)-2==pose4y) || ((posxb+60)/pixeles==pose4x && (posyb/pixeles)-2==pose4y) || ((posxb+120)/pixeles==pose4x && (posyb/pixeles)-2==pose4y)){
                pose4x=0;
                pose4y=0;
                tiMuerte4=new QTimer;
                tiMuerte4->start(250);
                connect(tiMuerte4,SIGNAL(timeout()),this,SLOT(muerte_enemigo4()));
            }
            if(((posxb)/pixeles==pose5x && (posyb/pixeles)-2==pose5y) || ((posxb+60)/pixeles==pose5x && (posyb/pixeles)-2==pose5y) || ((posxb+120)/pixeles==pose5x && (posyb/pixeles)-2==pose5y)){
                pose5x=0;
                pose5y=0;
                tiMuerte5=new QTimer;
                tiMuerte5->start(250);
                connect(tiMuerte5,SIGNAL(timeout()),this,SLOT(muerte_enemigo5()));
            }
            if(((posxb)/pixeles==pose6x && (posyb/pixeles)-2==pose6y) || ((posxb+60)/pixeles==pose6x && (posyb/pixeles)-2==pose6y) || ((posxb+120)/pixeles==pose6x && (posyb/pixeles)-2==pose6y)){
                pose6x=0;
                pose6y=0;
                tiMuerte6=new QTimer;
                tiMuerte6->start(250);
                connect(tiMuerte6,SIGNAL(timeout()),this,SLOT(muerte_enemigo6()));
            }
            if(((posxb)/pixeles==posx/pixeles && (posyb/pixeles)-2==(posy/pixeles)-2) || ((posxb+60)/pixeles==posx/pixeles && (posyb/pixeles)-2==(posy/pixeles)-2) || ((posxb+120)/pixeles==posx/pixeles && (posyb/pixeles)-2==(posy/pixeles)-2)){
                if(bandmuerte==true){
                    bandmuerte=false;
                    vidas=vidas-1;
                    ui->label_4->setNum(vidas);
                }
            }
        }
        else if(matriz[(posxb+60)/pixeles][(posyb/pixeles)-2]==0){
            bombar= new objetos();
            bombar->setPos(posxb+60,posyb);
            bombar->setPixmap(QPixmap(bombas[8]).scaled(60,60));
            escena->addItem(bombar);
            if(matriz[(posxb+120)/pixeles][(posyb/pixeles)-2]==1){
                matriz[(posxb+120)/pixeles][(posyb/pixeles)-2]=0;
                mapa[(posxb+120)/pixeles][(posyb/pixeles)-2]->setPixmap(QPixmap(ladrillos[0]).scaled(60,60));
            }
            r=true;
            if(((posxb)/pixeles==pose1x && (posyb/pixeles)-2==pose1y) || ((posxb+60)/pixeles==pose1x && (posyb/pixeles)-2==pose1y)){
                pose1x=0;
                pose1y=0;
                tiMuerte1=new QTimer;
                tiMuerte1->start(250);
                connect(tiMuerte1,SIGNAL(timeout()),this,SLOT(muerte_enemigo1()));
            }
            if(((posxb)/pixeles==pose2x && (posyb/pixeles)-2==pose2y) || ((posxb+60)/pixeles==pose2x && (posyb/pixeles)-2==pose2y)){
                pose2x=0;
                pose2y=0;
                tiMuerte2=new QTimer;
                tiMuerte2->start(250);
                connect(tiMuerte2,SIGNAL(timeout()),this,SLOT(muerte_enemigo2()));
            }
            if(((posxb)/pixeles==pose3x && (posyb/pixeles)-2==pose3y) || ((posxb+60)/pixeles==pose3x && (posyb/pixeles)-2==pose3y)){
                pose3x=0;
                pose3y=0;
                tiMuerte3=new QTimer;
                tiMuerte3->start(250);
                connect(tiMuerte3,SIGNAL(timeout()),this,SLOT(muerte_enemigo3()));
            }
            if(((posxb)/pixeles==pose4x && (posyb/pixeles)-2==pose4y) || ((posxb+60)/pixeles==pose4x && (posyb/pixeles)-2==pose4y)){
                pose4x=0;
                pose4y=0;
                tiMuerte4=new QTimer;
                tiMuerte4->start(250);
                connect(tiMuerte4,SIGNAL(timeout()),this,SLOT(muerte_enemigo4()));
            }
            if(((posxb)/pixeles==pose5x && (posyb/pixeles)-2==pose5y) || ((posxb+60)/pixeles==pose5x && (posyb/pixeles)-2==pose5y)){
                pose5x=0;
                pose5y=0;
                tiMuerte5=new QTimer;
                tiMuerte5->start(250);
                connect(tiMuerte5,SIGNAL(timeout()),this,SLOT(muerte_enemigo5()));
            }
            if(((posxb)/pixeles==pose6x && (posyb/pixeles)-2==pose6y) || ((posxb+60)/pixeles==pose6x && (posyb/pixeles)-2==pose6y)){
                pose6x=0;
                pose6y=0;
                tiMuerte6=new QTimer;
                tiMuerte6->start(250);
                connect(tiMuerte6,SIGNAL(timeout()),this,SLOT(muerte_enemigo6()));
            }
            if(((posxb)/pixeles==posx/pixeles && (posyb/pixeles)-2==(posy/pixeles)-2) || ((posxb+60)/pixeles==posx/pixeles && (posyb/pixeles)-2==(posy/pixeles)-2)){
                if(bandmuerte==true){
                    bandmuerte=false;
                    vidas=vidas-1;
                    ui->label_4->setNum(vidas);
                }
            }
        }
        else if (matriz[(posxb+60)/pixeles][(posyb/pixeles)-2]==1){
            matriz[(posxb+60)/pixeles][(posyb/pixeles)-2]=0;
            mapa[(posxb+60)/pixeles][(posyb/pixeles)-2]->setPixmap(QPixmap(ladrillos[0]).scaled(60,60));
            puntos=puntos+100;ui->label->setNum(puntos);
            if(((posxb)/pixeles==pose1x && (posyb/pixeles)-2==pose1y)){
                pose1x=0;
                pose1y=0;
                tiMuerte1=new QTimer;
                tiMuerte1->start(250);
                connect(tiMuerte1,SIGNAL(timeout()),this,SLOT(muerte_enemigo1()));
            }
            if(((posxb)/pixeles==pose2x && (posyb/pixeles)-2==pose2y)){
                pose2x=0;
                pose2y=0;
                tiMuerte2=new QTimer;
                tiMuerte2->start(250);
                connect(tiMuerte2,SIGNAL(timeout()),this,SLOT(muerte_enemigo2()));
            }
            if(((posxb)/pixeles==pose3x && (posyb/pixeles)-2==pose3y)){
                pose3x=0;
                pose3y=0;
                tiMuerte3=new QTimer;
                tiMuerte3->start(250);
                connect(tiMuerte3,SIGNAL(timeout()),this,SLOT(muerte_enemigo3()));
            }
            if(((posxb)/pixeles==pose4x && (posyb/pixeles)-2==pose4y)){
                pose4x=0;
                pose4y=0;
                tiMuerte4=new QTimer;
                tiMuerte4->start(250);
                connect(tiMuerte4,SIGNAL(timeout()),this,SLOT(muerte_enemigo4()));
            }
            if(((posxb)/pixeles==pose5x && (posyb/pixeles)-2==pose5y)){
                pose5x=0;
                pose5y=0;
                tiMuerte5=new QTimer;
                tiMuerte5->start(250);
                connect(tiMuerte5,SIGNAL(timeout()),this,SLOT(muerte_enemigo5()));
            }
            if(((posxb)/pixeles==pose6x && (posyb/pixeles)-2==pose6y)){
                pose6x=0;
                pose6y=0;
                tiMuerte6=new QTimer;
                tiMuerte6->start(250);
                connect(tiMuerte6,SIGNAL(timeout()),this,SLOT(muerte_enemigo6()));
            }
            if(((posxb)/pixeles==posx/pixeles && (posyb/pixeles)-2==(posy/pixeles)-2)){
                if(bandmuerte==true){
                    bandmuerte=false;
                    vidas=vidas-1;
                    ui->label_4->setNum(vidas);
                }
            }
        }
        //Animación extremo izquierdo de bomba
        if(matriz[(posxb-10)/pixeles][(posyb/pixeles)-2]==0 && matriz[(posxb-70)/pixeles][(posyb/pixeles)-2]==0){
            bombal= new objetos();
            bombal->setPos(posxb-120,posyb);
            bombal->setPixmap(QPixmap(bombas[6]).scaled(120,60));
            escena->addItem(bombal);
            l=true;
            if(((posxb)/pixeles==pose1x && (posyb/pixeles)-2==pose1y) || ((posxb-10)/pixeles==pose1x && (posyb/pixeles)-2==pose1y) || ((posxb-70)/pixeles==pose1x && (posyb/pixeles)-2==pose1y)){
                pose1x=0;
                pose1y=0;
                tiMuerte1=new QTimer;
                tiMuerte1->start(250);
                connect(tiMuerte1,SIGNAL(timeout()),this,SLOT(muerte_enemigo1()));
            }
            if(((posxb)/pixeles==pose2x && (posyb/pixeles)-2==pose2y) || ((posxb-10)/pixeles==pose2x && (posyb/pixeles)-2==pose2y) || ((posxb-70)/pixeles==pose2x && (posyb/pixeles)-2==pose2y)){
                pose2x=0;
                pose2y=0;
                tiMuerte2=new QTimer;
                tiMuerte2->start(250);
                connect(tiMuerte2,SIGNAL(timeout()),this,SLOT(muerte_enemigo2()));
            }
            if(((posxb)/pixeles==pose3x && (posyb/pixeles)-2==pose3y) || ((posxb-10)/pixeles==pose3x && (posyb/pixeles)-2==pose3y) || ((posxb-70)/pixeles==pose3x && (posyb/pixeles)-2==pose3y)){
                pose3x=0;
                pose3y=0;
                tiMuerte3=new QTimer;
                tiMuerte3->start(250);
                connect(tiMuerte3,SIGNAL(timeout()),this,SLOT(muerte_enemigo3()));
            }
            if(((posxb)/pixeles==pose4x && (posyb/pixeles)-2==pose4y) || ((posxb-10)/pixeles==pose4x && (posyb/pixeles)-2==pose4y) || ((posxb-70)/pixeles==pose4x && (posyb/pixeles)-2==pose4y)){
                pose4x=0;
                pose4y=0;
                tiMuerte4=new QTimer;
                tiMuerte4->start(250);
                connect(tiMuerte4,SIGNAL(timeout()),this,SLOT(muerte_enemigo4()));
            }
            if(((posxb)/pixeles==pose5x && (posyb/pixeles)-2==pose5y) || ((posxb-10)/pixeles==pose5x && (posyb/pixeles)-2==pose5y) || ((posxb-70)/pixeles==pose5x && (posyb/pixeles)-2==pose5y)){
                pose5x=0;
                pose5y=0;
                tiMuerte5=new QTimer;
                tiMuerte5->start(250);
                connect(tiMuerte5,SIGNAL(timeout()),this,SLOT(muerte_enemigo5()));
            }
            if(((posxb)/pixeles==pose6x && (posyb/pixeles)-2==pose6y) || ((posxb-10)/pixeles==pose6x && (posyb/pixeles)-2==pose6y) || ((posxb-70)/pixeles==pose6x && (posyb/pixeles)-2==pose6y)){
                pose6x=0;
                pose6y=0;
                tiMuerte6=new QTimer;
                tiMuerte6->start(250);
                connect(tiMuerte6,SIGNAL(timeout()),this,SLOT(muerte_enemigo6()));
            }
            if(((posxb)/pixeles==posx/pixeles && (posyb/pixeles)-2==(posy/pixeles)-2) || ((posxb-10)/pixeles==posx/pixeles && (posyb/pixeles)-2==(posy/pixeles)-2) || ((posxb-70)/pixeles==posx/pixeles && (posyb/pixeles)-2==(posy/pixeles)-2)){
                if(bandmuerte==true){
                    bandmuerte=false;
                    vidas=vidas-1;
                    ui->label_4->setNum(vidas);
                }
            }
        }
        else if(matriz[(posxb-10)/pixeles][(posyb/pixeles)-2]==0){
            bombal= new objetos();
            bombal->setPos(posxb-60,posyb);
            bombal->setPixmap(QPixmap(bombas[6]).scaled(60,60));
            escena->addItem(bombal);
            l=true;
            if(matriz[(posxb-70)/pixeles][(posyb/pixeles)-2]==1){
                matriz[(posxb-70)/pixeles][(posyb/pixeles)-2]=0;
                mapa[(posxb-70)/pixeles][(posyb/pixeles)-2]->setPixmap(QPixmap(ladrillos[0]).scaled(60,60));
            }
            if(((posxb)/pixeles==pose1x && (posyb/pixeles)-2==pose1y) || ((posxb-10)/pixeles==pose1x && (posyb/pixeles)-2==pose1y)){
                pose1x=0;
                pose1y=0;
                tiMuerte1=new QTimer;
                tiMuerte1->start(250);
                connect(tiMuerte1,SIGNAL(timeout()),this,SLOT(muerte_enemigo1()));
            }
            if(((posxb)/pixeles==pose2x && (posyb/pixeles)-2==pose2y) || ((posxb-10)/pixeles==pose2x && (posyb/pixeles)-2==pose2y)){
                pose2x=0;
                pose2y=0;
                tiMuerte2=new QTimer;
                tiMuerte2->start(250);
                connect(tiMuerte2,SIGNAL(timeout()),this,SLOT(muerte_enemigo2()));
            }
            if(((posxb)/pixeles==pose3x && (posyb/pixeles)-2==pose3y) || ((posxb-10)/pixeles==pose3x && (posyb/pixeles)-2==pose3y)){
                pose3x=0;
                pose3y=0;
                tiMuerte3=new QTimer;
                tiMuerte3->start(250);
                connect(tiMuerte3,SIGNAL(timeout()),this,SLOT(muerte_enemigo3()));
            }
            if(((posxb)/pixeles==pose4x && (posyb/pixeles)-2==pose4y) || ((posxb-10)/pixeles==pose4x && (posyb/pixeles)-2==pose4y)){
                pose4x=0;
                pose4y=0;
                tiMuerte4=new QTimer;
                tiMuerte4->start(250);
                connect(tiMuerte4,SIGNAL(timeout()),this,SLOT(muerte_enemigo4()));
            }
            if(((posxb)/pixeles==pose5x && (posyb/pixeles)-2==pose5y) || ((posxb-10)/pixeles==pose5x && (posyb/pixeles)-2==pose5y)){
                pose5x=0;
                pose5y=0;
                tiMuerte5=new QTimer;
                tiMuerte5->start(250);
                connect(tiMuerte5,SIGNAL(timeout()),this,SLOT(muerte_enemigo5()));
            }
            if(((posxb)/pixeles==pose6x && (posyb/pixeles)-2==pose6y) || ((posxb-10)/pixeles==pose6x && (posyb/pixeles)-2==pose6y)){
                pose6x=0;
                pose6y=0;
                tiMuerte6=new QTimer;
                tiMuerte6->start(250);
                connect(tiMuerte6,SIGNAL(timeout()),this,SLOT(muerte_enemigo6()));
            }
            if(((posxb)/pixeles==posx/pixeles && (posyb/pixeles)-2==(posy/pixeles)-2) || ((posxb-10)/pixeles==posx/pixeles && (posyb/pixeles)-2==(posy/pixeles)-2)){
                if(bandmuerte==true){
                    bandmuerte=false;
                    vidas=vidas-1;
                    ui->label_4->setNum(vidas);
                }
            }
        }
        else if(matriz[(posxb-10)/pixeles][(posyb/pixeles)-2]==1){
            matriz[(posxb-10)/pixeles][(posyb/pixeles)-2]=0;
            mapa[(posxb-10)/pixeles][(posyb/pixeles)-2]->setPixmap(QPixmap(ladrillos[0]).scaled(60,60));
            if(((posxb)/pixeles==pose1x && (posyb/pixeles)-2==pose1y)){
                pose1x=0;
                pose1y=0;
                tiMuerte1=new QTimer;
                tiMuerte1->start(250);
                connect(tiMuerte1,SIGNAL(timeout()),this,SLOT(muerte_enemigo1()));
            }
            if(((posxb)/pixeles==pose2x && (posyb/pixeles)-2==pose2y)){
                pose2x=0;
                pose2y=0;
                tiMuerte2=new QTimer;
                tiMuerte2->start(250);
                connect(tiMuerte2,SIGNAL(timeout()),this,SLOT(muerte_enemigo2()));
            }
            if(((posxb)/pixeles==pose3x && (posyb/pixeles)-2==pose3y)){
                pose3x=0;
                pose3y=0;
                tiMuerte3=new QTimer;
                tiMuerte3->start(250);
                connect(tiMuerte3,SIGNAL(timeout()),this,SLOT(muerte_enemigo3()));
            }
            if(((posxb)/pixeles==pose4x && (posyb/pixeles)-2==pose4y)){
                pose4x=0;
                pose4y=0;
                tiMuerte4=new QTimer;
                tiMuerte4->start(250);
                connect(tiMuerte4,SIGNAL(timeout()),this,SLOT(muerte_enemigo4()));
            }
            if(((posxb)/pixeles==pose5x && (posyb/pixeles)-2==pose5y)){
                pose5x=0;
                pose5y=0;
                tiMuerte5=new QTimer;
                tiMuerte5->start(250);
                connect(tiMuerte5,SIGNAL(timeout()),this,SLOT(muerte_enemigo5()));
            }
            if(((posxb)/pixeles==pose6x && (posyb/pixeles)-2==pose6y)){
                pose6x=0;
                pose6y=0;
                tiMuerte6=new QTimer;
                tiMuerte6->start(250);
                connect(tiMuerte6,SIGNAL(timeout()),this,SLOT(muerte_enemigo6()));
            }
            if(((posxb)/pixeles==posx/pixeles && (posyb/pixeles)-2==(posy/pixeles)-2)){
                if(bandmuerte==true){
                    bandmuerte=false;
                    vidas=vidas-1;
                    ui->label_4->setNum(vidas);
                }
            }
        }
        //Animación superior
        if(matriz[posxb/pixeles][((posyb-10)/pixeles)-2]==0 && matriz[(posxb)/pixeles][((posyb-70)/pixeles)-2]==0){
            bombau= new objetos();
            bombau->setPos(posxb,posyb-120);
            bombau->setPixmap(QPixmap(bombas[5]).scaled(60,120));
            escena->addItem(bombau);
            u=true;
            if(((posxb)/pixeles==pose1x && (posyb/pixeles)-2==pose1y) || ((posxb)/pixeles==pose1x && ((posyb-10)/pixeles)-2==pose1y) || ((posxb)/pixeles==pose1x && ((posyb-70)/pixeles)-2==pose1y)){
                pose1x=0;
                pose1y=0;
                tiMuerte1=new QTimer;
                tiMuerte1->start(250);
                connect(tiMuerte1,SIGNAL(timeout()),this,SLOT(muerte_enemigo1()));
            }
            if(((posxb)/pixeles==pose2x && (posyb/pixeles)-2==pose2y) || ((posxb)/pixeles==pose2x && ((posyb-10)/pixeles)-2==pose2y) || ((posxb)/pixeles==pose2x && ((posyb-70)/pixeles)-2==pose2y)){
                pose2x=0;
                pose2y=0;
                tiMuerte2=new QTimer;
                tiMuerte2->start(250);
                connect(tiMuerte2,SIGNAL(timeout()),this,SLOT(muerte_enemigo2()));
            }
            if(((posxb)/pixeles==pose3x && (posyb/pixeles)-2==pose3y) || ((posxb)/pixeles==pose3x && ((posyb-10)/pixeles)-2==pose3y) || ((posxb)/pixeles==pose3x && ((posyb-70)/pixeles)-2==pose3y)){
                pose3x=0;
                pose3y=0;
                tiMuerte3=new QTimer;
                tiMuerte3->start(250);
                connect(tiMuerte3,SIGNAL(timeout()),this,SLOT(muerte_enemigo3()));
            }
            if(((posxb)/pixeles==pose4x && (posyb/pixeles)-2==pose4y) || ((posxb)/pixeles==pose4x && ((posyb-10)/pixeles)-2==pose4y) || ((posxb)/pixeles==pose4x && ((posyb-70)/pixeles)-2==pose4y)){
                pose4x=0;
                pose4y=0;
                tiMuerte4=new QTimer;
                tiMuerte4->start(250);
                connect(tiMuerte4,SIGNAL(timeout()),this,SLOT(muerte_enemigo4()));
            }
            if(((posxb)/pixeles==pose5x && (posyb/pixeles)-2==pose5y) || ((posxb)/pixeles==pose5x && ((posyb-10)/pixeles)-2==pose5y) || ((posxb)/pixeles==pose5x && ((posyb-70)/pixeles)-2==pose5y)){
                pose5x=0;
                pose5y=0;
                tiMuerte5=new QTimer;
                tiMuerte5->start(250);
                connect(tiMuerte5,SIGNAL(timeout()),this,SLOT(muerte_enemigo5()));
            }
            if(((posxb)/pixeles==pose6x && (posyb/pixeles)-2==pose6y) || ((posxb)/pixeles==pose6x && ((posyb-10)/pixeles)-2==pose6y) || ((posxb)/pixeles==pose6x && ((posyb-70)/pixeles)-2==pose6y)){
                pose6x=0;
                pose6y=0;
                tiMuerte6=new QTimer;
                tiMuerte6->start(250);
                connect(tiMuerte6,SIGNAL(timeout()),this,SLOT(muerte_enemigo6()));
            }
            if(((posxb)/pixeles==posx/pixeles && (posyb/pixeles)-2==(posy/pixeles)-2) || ((posxb)/pixeles==posx/pixeles && ((posyb-10)/pixeles)-2==(posy/pixeles)-2) || ((posxb)/pixeles==posx/pixeles && ((posyb-70)/pixeles)-2==(posy/pixeles)-2)){
                if(bandmuerte==true){
                    bandmuerte=false;
                    vidas=vidas-1;
                    ui->label_4->setNum(vidas);
                }
            }
        }
        else if(matriz[posxb/pixeles][((posyb-10)/pixeles)-2]==0){
            bombau= new objetos();
            bombau->setPos(posxb,posyb-60);
            bombau->setPixmap(QPixmap(bombas[5]).scaled(60,60));
            escena->addItem(bombau);
            u=true;
            if(matriz[(posxb)/pixeles][((posyb-70)/pixeles)-2]==1){
                matriz[posxb/pixeles][((posyb-70)/pixeles)-2]=0;
                mapa[posxb/pixeles][((posyb-70)/pixeles)-2]->setPixmap(QPixmap(ladrillos[0]).scaled(60,60));
            }
            if(((posxb)/pixeles==pose1x && (posyb/pixeles)-2==pose1y) || ((posxb)/pixeles==pose1x && ((posyb-10)/pixeles)-2==pose1y)){
                pose1x=0;
                pose1y=0;
                tiMuerte1=new QTimer;
                tiMuerte1->start(250);
                connect(tiMuerte1,SIGNAL(timeout()),this,SLOT(muerte_enemigo1()));
            }
            if(((posxb)/pixeles==pose2x && (posyb/pixeles)-2==pose2y) || ((posxb)/pixeles==pose2x && ((posyb-10)/pixeles)-2==pose2y)){
                pose2x=0;
                pose2y=0;
                tiMuerte2=new QTimer;
                tiMuerte2->start(250);
                connect(tiMuerte2,SIGNAL(timeout()),this,SLOT(muerte_enemigo2()));
            }
            if(((posxb)/pixeles==pose3x && (posyb/pixeles)-2==pose3y) || ((posxb)/pixeles==pose3x && ((posyb-10)/pixeles)-2==pose3y)){
                pose3x=0;
                pose3y=0;
                tiMuerte3=new QTimer;
                tiMuerte3->start(250);
                connect(tiMuerte3,SIGNAL(timeout()),this,SLOT(muerte_enemigo3()));
            }
            if(((posxb)/pixeles==pose4x && (posyb/pixeles)-2==pose4y) || ((posxb)/pixeles==pose4x && ((posyb-10)/pixeles)-2==pose4y)){
                pose4x=0;
                pose4y=0;
                tiMuerte4=new QTimer;
                tiMuerte4->start(250);
                connect(tiMuerte4,SIGNAL(timeout()),this,SLOT(muerte_enemigo4()));
            }
            if(((posxb)/pixeles==pose5x && (posyb/pixeles)-2==pose5y) || ((posxb)/pixeles==pose5x && ((posyb-10)/pixeles)-2==pose5y)){
                pose5x=0;
                pose5y=0;
                tiMuerte5=new QTimer;
                tiMuerte5->start(250);
                connect(tiMuerte5,SIGNAL(timeout()),this,SLOT(muerte_enemigo5()));
            }
            if(((posxb)/pixeles==pose6x && (posyb/pixeles)-2==pose6y) || ((posxb)/pixeles==pose6x && ((posyb-10)/pixeles)-2==pose6y)){
                pose6x=0;
                pose6y=0;
                tiMuerte6=new QTimer;
                tiMuerte6->start(250);
                connect(tiMuerte6,SIGNAL(timeout()),this,SLOT(muerte_enemigo6()));
            }
            if(((posxb)/pixeles==posx/pixeles && (posyb/pixeles)-2==(posy/pixeles)-2) || ((posxb)/pixeles==posx/pixeles && ((posyb-10)/pixeles)-2==(posy/pixeles)-2)){
                if(bandmuerte==true){
                    bandmuerte=false;
                    vidas=vidas-1;
                    ui->label_4->setNum(vidas);
                }
            }
        }
        else if(matriz[posxb/pixeles][((posyb-10)/pixeles)-2]==1){
            matriz[posxb/pixeles][((posyb-10)/pixeles)-2]=0;
            mapa[posxb/pixeles][((posyb-10)/pixeles)-2]->setPixmap(QPixmap(ladrillos[0]).scaled(60,60));
            if(((posxb)/pixeles==pose1x && (posyb/pixeles)-2==pose1y)){
                pose1x=0;
                pose1y=0;
                tiMuerte1=new QTimer;
                tiMuerte1->start(250);
                connect(tiMuerte1,SIGNAL(timeout()),this,SLOT(muerte_enemigo1()));
            }
            if(((posxb)/pixeles==pose2x && (posyb/pixeles)-2==pose2y)){
                pose2x=0;
                pose2y=0;
                tiMuerte2=new QTimer;
                tiMuerte2->start(250);
                connect(tiMuerte2,SIGNAL(timeout()),this,SLOT(muerte_enemigo2()));
            }
            if(((posxb)/pixeles==pose3x && (posyb/pixeles)-2==pose3y)){
                pose3x=0;
                pose3y=0;
                tiMuerte3=new QTimer;
                tiMuerte3->start(250);
                connect(tiMuerte3,SIGNAL(timeout()),this,SLOT(muerte_enemigo3()));
            }
            if(((posxb)/pixeles==pose4x && (posyb/pixeles)-2==pose4y)){
                pose4x=0;
                pose4y=0;
                tiMuerte4=new QTimer;
                tiMuerte4->start(250);
                connect(tiMuerte4,SIGNAL(timeout()),this,SLOT(muerte_enemigo4()));
            }
            if(((posxb)/pixeles==pose5x && (posyb/pixeles)-2==pose5y)){
                pose5x=0;
                pose5y=0;
                tiMuerte5=new QTimer;
                tiMuerte5->start(250);
                connect(tiMuerte5,SIGNAL(timeout()),this,SLOT(muerte_enemigo5()));
            }
            if(((posxb)/pixeles==pose6x && (posyb/pixeles)-2==pose6y)){
                pose6x=0;
                pose6y=0;
                tiMuerte6=new QTimer;
                tiMuerte6->start(250);
                connect(tiMuerte6,SIGNAL(timeout()),this,SLOT(muerte_enemigo6()));
            }
            if(((posxb)/pixeles==posx/pixeles && (posyb/pixeles)-2==(posy/pixeles)-2)){
                if(bandmuerte==true){
                    bandmuerte=false;
                    vidas=vidas-1;
                    ui->label_4->setNum(vidas);
                }
            }
        }
        //Animación inferior
        if(matriz[(posxb)/pixeles][((posyb+60)/pixeles)-2]==0 && matriz[(posxb)/pixeles][((posyb+120)/pixeles)-2]==0){
            bombad= new objetos();
            bombad->setPos(posxb,posyb+60);
            bombad->setPixmap(QPixmap(bombas[7]).scaled(60,120));
            escena->addItem(bombad);
            d=true;
            if(((posxb)/pixeles==pose1x && (posyb/pixeles)-2==pose1y) || ((posxb)/pixeles==pose1x && ((posyb+60)/pixeles)-2==pose1y) || ((posxb)/pixeles==pose1x && ((posyb-70)/pixeles)-2==pose1y)){
                pose1x=0;
                pose1y=0;
                tiMuerte1=new QTimer;
                tiMuerte1->start(250);
                connect(tiMuerte1,SIGNAL(timeout()),this,SLOT(muerte_enemigo1()));
            }
            if(((posxb)/pixeles==pose2x && (posyb/pixeles)-2==pose2y) || ((posxb)/pixeles==pose2x && ((posyb+60)/pixeles)-2==pose2y) || ((posxb)/pixeles==pose2x && ((posyb+120)/pixeles)-2==pose2y)){
                pose2x=0;
                pose2y=0;
                tiMuerte2=new QTimer;
                tiMuerte2->start(250);
                connect(tiMuerte2,SIGNAL(timeout()),this,SLOT(muerte_enemigo2()));
            }
            if(((posxb)/pixeles==pose3x && (posyb/pixeles)-2==pose3y) || ((posxb)/pixeles==pose3x && ((posyb+60)/pixeles)-2==pose3y) || ((posxb)/pixeles==pose3x && ((posyb+120)/pixeles)-2==pose3y)){
                pose3x=0;
                pose3y=0;
                tiMuerte3=new QTimer;
                tiMuerte3->start(250);
                connect(tiMuerte3,SIGNAL(timeout()),this,SLOT(muerte_enemigo3()));
            }
            if(((posxb)/pixeles==pose4x && (posyb/pixeles)-2==pose4y) || ((posxb)/pixeles==pose4x && ((posyb+60)/pixeles)-2==pose4y) || ((posxb)/pixeles==pose4x && ((posyb+120)/pixeles)-2==pose4y)){
                pose4x=0;
                pose4y=0;
                tiMuerte4=new QTimer;
                tiMuerte4->start(250);
                connect(tiMuerte4,SIGNAL(timeout()),this,SLOT(muerte_enemigo4()));
            }
            if(((posxb)/pixeles==pose5x && (posyb/pixeles)-2==pose5y) || ((posxb)/pixeles==pose5x && ((posyb+60)/pixeles)-2==pose5y) || ((posxb)/pixeles==pose5x && ((posyb+120)/pixeles)-2==pose5y)){
                pose5x=0;
                pose5y=0;
                tiMuerte5=new QTimer;
                tiMuerte5->start(250);
                connect(tiMuerte5,SIGNAL(timeout()),this,SLOT(muerte_enemigo5()));
            }
            if(((posxb)/pixeles==pose6x && (posyb/pixeles)-2==pose6y) || ((posxb)/pixeles==pose6x && ((posyb+60)/pixeles)-2==pose6y) || ((posxb)/pixeles==pose6x && ((posyb+120)/pixeles)-2==pose6y)){
                pose6x=0;
                pose6y=0;
                tiMuerte6=new QTimer;
                tiMuerte6->start(250);
                connect(tiMuerte6,SIGNAL(timeout()),this,SLOT(muerte_enemigo6()));
            }
            if(((posxb)/pixeles==posx/pixeles && (posyb/pixeles)-2==(posy/pixeles)-2) || ((posxb)/pixeles==posx/pixeles && ((posyb+60)/pixeles)-2==(posy/pixeles)-2) || ((posxb)/pixeles==posx/pixeles && ((posyb+120)/pixeles)-2==(posy/pixeles)-2)){
                if(bandmuerte==true){
                    bandmuerte=false;
                    vidas=vidas-1;
                    ui->label_4->setNum(vidas);
                }
            }
        }
        else if(matriz[(posxb)/pixeles][((posyb+60)/pixeles)-2]==0){
            bombad= new objetos();
            bombad->setPos(posxb,posyb+60);
            bombad->setPixmap(QPixmap(bombas[7]).scaled(60,60));
            escena->addItem(bombad);
            if(matriz[(posxb)/pixeles][((posyb+120)/pixeles)-2]==1){
                matriz[(posxb)/pixeles][((posyb+120)/pixeles)-2]=0;
                mapa[(posxb)/pixeles][((posyb+120)/pixeles)-2]->setPixmap(QPixmap(ladrillos[0]).scaled(60,60));
                puntos=puntos+100;
                ui->label->setNum(puntos);

            }
            d=true;
            if(((posxb)/pixeles==pose1x && (posyb/pixeles)-2==pose1y) || ((posxb)/pixeles==pose1x && ((posyb+60)/pixeles)-2==pose1y)){
                pose1x=0;
                pose1y=0;
                tiMuerte1=new QTimer;
                tiMuerte1->start(250);
                connect(tiMuerte1,SIGNAL(timeout()),this,SLOT(muerte_enemigo1()));
            }
            if(((posxb)/pixeles==pose2x && (posyb/pixeles)-2==pose2y) || ((posxb)/pixeles==pose2x && ((posyb+60)/pixeles)-2==pose2y)){
                pose2x=0;
                pose2y=0;
                tiMuerte2=new QTimer;
                tiMuerte2->start(250);
                connect(tiMuerte2,SIGNAL(timeout()),this,SLOT(muerte_enemigo2()));
            }
            if(((posxb)/pixeles==pose3x && (posyb/pixeles)-2==pose3y) || ((posxb)/pixeles==pose3x && ((posyb+60)/pixeles)-2==pose3y)){
                pose3x=0;
                pose3y=0;
                tiMuerte3=new QTimer;
                tiMuerte3->start(250);
                connect(tiMuerte3,SIGNAL(timeout()),this,SLOT(muerte_enemigo3()));
            }
            if(((posxb)/pixeles==pose4x && (posyb/pixeles)-2==pose4y) || ((posxb)/pixeles==pose4x && ((posyb+60)/pixeles)-2==pose4y)){
                pose4x=0;
                pose4y=0;
                tiMuerte4=new QTimer;
                tiMuerte4->start(250);
                connect(tiMuerte4,SIGNAL(timeout()),this,SLOT(muerte_enemigo4()));
            }
            if(((posxb)/pixeles==pose5x && (posyb/pixeles)-2==pose5y) || ((posxb)/pixeles==pose5x && ((posyb+60)/pixeles)-2==pose5y)){
                pose5x=0;
                pose5y=0;
                tiMuerte5=new QTimer;
                tiMuerte5->start(250);
                connect(tiMuerte5,SIGNAL(timeout()),this,SLOT(muerte_enemigo5()));
            }
            if(((posxb)/pixeles==pose6x && (posyb/pixeles)-2==pose6y) || ((posxb)/pixeles==pose6x && ((posyb+60)/pixeles)-2==pose6y)){
                pose6x=0;
                pose6y=0;
                tiMuerte6=new QTimer;
                tiMuerte6->start(250);
                connect(tiMuerte6,SIGNAL(timeout()),this,SLOT(muerte_enemigo6()));
            }
            if(((posxb)/pixeles==posx/pixeles && (posyb/pixeles)-2==(posy/pixeles)-2) || ((posxb)/pixeles==posx/pixeles && ((posyb+60)/pixeles)-2==(posy/pixeles)-2)){
                if(bandmuerte==true){
                    bandmuerte=false;
                    vidas=vidas-1;
                    ui->label_4->setNum(vidas);
                }
            }
        }
        else if (matriz[(posxb)/pixeles][((posyb+60)/pixeles)-2]==1){
            matriz[(posxb)/pixeles][((posyb+60)/pixeles)-2]=0;
            mapa[(posxb)/pixeles][((posyb+60)/pixeles)-2]->setPixmap(QPixmap(ladrillos[0]).scaled(60,60));
            if(((posxb)/pixeles==pose1x && (posyb/pixeles)-2==pose1y)){
                pose1x=0;
                pose1y=0;
                tiMuerte1=new QTimer;
                tiMuerte1->start(250);
                connect(tiMuerte1,SIGNAL(timeout()),this,SLOT(muerte_enemigo1()));
            }
            if(((posxb)/pixeles==pose2x && (posyb/pixeles)-2==pose2y)){
                pose2x=0;
                pose2y=0;
                tiMuerte2=new QTimer;
                tiMuerte2->start(250);
                connect(tiMuerte2,SIGNAL(timeout()),this,SLOT(muerte_enemigo2()));
            }
            if(((posxb)/pixeles==pose3x && (posyb/pixeles)-2==pose3y)){
                pose3x=0;
                pose3y=0;
                tiMuerte3=new QTimer;
                tiMuerte3->start(250);
                connect(tiMuerte3,SIGNAL(timeout()),this,SLOT(muerte_enemigo3()));
            }
            if(((posxb)/pixeles==pose4x && (posyb/pixeles)-2==pose4y)){
                pose4x=0;
                pose4y=0;
                tiMuerte4=new QTimer;
                tiMuerte4->start(250);
                connect(tiMuerte4,SIGNAL(timeout()),this,SLOT(muerte_enemigo4()));
            }
            if(((posxb)/pixeles==pose5x && (posyb/pixeles)-2==pose5y)){
                pose5x=0;
                pose5y=0;
                tiMuerte5=new QTimer;
                tiMuerte5->start(250);
                connect(tiMuerte5,SIGNAL(timeout()),this,SLOT(muerte_enemigo5()));
            }
            if(((posxb)/pixeles==pose6x && (posyb/pixeles)-2==pose6y)){
                pose6x=0;
                pose6y=0;
                tiMuerte6=new QTimer;
                tiMuerte6->start(250);
                connect(tiMuerte6,SIGNAL(timeout()),this,SLOT(muerte_enemigo6()));
            }
            if(((posxb)/pixeles==posx/pixeles && (posyb/pixeles)-2==(posy/pixeles)-2)){
                if(bandmuerte==true){
                    bandmuerte=false;
                    vidas=vidas-1;
                    ui->label_4->setNum(vidas);
                }
            }
        }
    }
    if(exp==5){
        exp=0;
        bomba->deleteLater();
        if(r==true){
            r=false;
            bombar->deleteLater();
        }
        if(l==true){
            l=false;
            bombal->deleteLater();
        }
        if(u==true){
            u=false;
            bombau->deleteLater();
        }
        if(d==true){
            d=false;
            bombad->deleteLater();
        }
        if(matriz[(posxb+120)/pixeles][(posyb/pixeles)-2]==0){mapa[(posxb+120)/pixeles][(posyb/pixeles)-2]->setPixmap(QPixmap(ladrillos[1]).scaled(60,60));}//puntos=puntos+100;ui->label->setNum(puntos);}
        if(matriz[(posxb+60)/pixeles][(posyb/pixeles)-2]==0){ mapa[(posxb+60)/pixeles][(posyb/pixeles)-2]->setPixmap(QPixmap(ladrillos[1]).scaled(60,60));}//puntos=puntos+100;ui->label->setNum(puntos);}
        if(matriz[(posxb-70)/pixeles][(posyb/pixeles)-2]==0) {mapa[(posxb-70)/pixeles][(posyb/pixeles)-2]->setPixmap(QPixmap(ladrillos[1]).scaled(60,60));}//puntos=puntos+100;ui->label->setNum(puntos);}
        if(matriz[(posxb-10)/pixeles][(posyb/pixeles)-2]==0) {mapa[(posxb-10)/pixeles][(posyb/pixeles)-2]->setPixmap(QPixmap(ladrillos[1]).scaled(60,60));}//puntos=puntos+100;ui->label->setNum(puntos);}
        if(matriz[posxb/pixeles][((posyb-70)/pixeles)-2]==0) {mapa[posxb/pixeles][((posyb-70)/pixeles)-2]->setPixmap(QPixmap(ladrillos[1]).scaled(60,60));}//puntos=puntos+100;ui->label->setNum(puntos);}
        if(matriz[posxb/pixeles][((posyb-10)/pixeles)-2]==0) {mapa[posxb/pixeles][((posyb-10)/pixeles)-2]->setPixmap(QPixmap(ladrillos[1]).scaled(60,60));}//puntos=puntos+100;ui->label->setNum(puntos);}
        if(matriz[(posxb)/pixeles][((posyb+120)/pixeles)-2]==0){ mapa[(posxb)/pixeles][((posyb+120)/pixeles)-2]->setPixmap(QPixmap(ladrillos[1]).scaled(60,60));}//puntos=puntos+100;ui->label->setNum(puntos);}
        if(matriz[(posxb)/pixeles][((posyb+60)/pixeles)-2]==0){ mapa[(posxb)/pixeles][((posyb+60)/pixeles)-2]->setPixmap(QPixmap(ladrillos[1]).scaled(60,60));}//puntos=puntos+100;ui->label->setNum(puntos);}

        matriz[posxb/pixeles][(posyb/pixeles)-2]=0;
        bomb=false;
        time->stop();
        if(!tiMuerte1->isActive() && !tiMuerte2->isActive() && !tiMuerte3->isActive() && !tiMuerte4->isActive() && !tiMuerte5->isActive() && !tiMuerte6->isActive()){
            if(bandmuerte==false){
                time=new QTimer;
                time->start(250);
                connect(time,SIGNAL(timeout()),this,SLOT(morir()));
            }
        }
    }
}

void MainWindow::morir()
{
    Bomber->setPixmap(QPixmap(muerte[contm]).scaled(60,60));
    if(contm==0){
        msound->setMedia(QUrl("qrc:/Sonidos/muerte.mp3"));
        msound->play();
    }
    contm++;
    if(contm>6){
        enemigos=6;
        puntos=puntosglob;
        ui->label->setNum(puntos);
        Bomber->deleteLater();
        contm=0;
        time->stop();
        music->stop();
        generar_mapa();
        Bomber=new objetos(":/sprites/Sprites/frontal.png");
        Bomber->setPos(60,180);
        escena->addItem(Bomber);
        generar_enemigos();
        posx=60;
        posy=180;
        contadorTIEMPO=180;
        bandmuerte=true;
        ui->lcdNumber->display(contadorTIEMPO);
        if(vidas==0){
            bandmuerte=false;
            enemigo1->deleteLater();
            enemigo2->deleteLater();
            enemigo3->deleteLater();
            enemigo4->deleteLater();
            enemigo5->deleteLater();
            enemigo6->deleteLater();
            Bomber->setPixmap(QPixmap(":/sprites/Sprites/game_over.png").scaled(60*columnas,60*(filas+2)));
            Bomber->setPos(0,0);
        }
    }
}

void MainWindow::muerte_enemigo1()
{
    //if(bandmuerte==true){
        if(level==1) enemigo1->setPixmap(QPixmap(valcomsprite[contmv]).scaled(60,60));
        else enemigo1->setPixmap(QPixmap(onealsprite[6]).scaled(60,60));
        contmv++;
        if(contmv==10 && level==1){
            puntos=puntos+100+puntosglob;
            ui->label->setNum(puntos);
            enemigo1->deleteLater();
            enemigos--;
            contmv=6;
            tiMuerte1->stop();
            if(bandmuerte==false){
                time=new QTimer;
                time->start(250);
                connect(time,SIGNAL(timeout()),this,SLOT(morir()));
            }
            if(enemigos==0){
                music->stop();
                puntosglob=puntos;
                enemigos=6;
                vidas=3;
                ui->label_4->setNum(vidas);
                if(level==1){
                    levelant=1;
                    level=2;
                }
                else{
                    levelant=2;
                    level=1;
                }
                Bomber->deleteLater();
                generar_mapa();
                Bomber=new objetos(":/sprites/Sprites/frontal.png");
                Bomber->setPos(60,180);
                escena->addItem(Bomber);
                generar_enemigos();
                posx=60;
                posy=180;
                bandmuerte=true;
            }
        }
        else if(contmv==7 && level==2){
            puntos=puntos+100;
            ui->label->setNum(puntos);
            enemigo1->deleteLater();
            enemigos--;
            contmv=6;
            tiMuerte1->stop();
            if(bandmuerte==false){
                time=new QTimer;
                time->start(250);
                connect(time,SIGNAL(timeout()),this,SLOT(morir()));
            }
            if(enemigos==0){
                music->stop();
                puntosglob=puntos;
                vidas=3;
                ui->label_4->setNum(vidas);
                enemigos=6;
                if(level==1){
                    levelant=1;
                    level=2;
                }
                else{
                    levelant=2;
                    level=1;
                }
                Bomber->deleteLater();
                generar_mapa();
                Bomber=new objetos(":/sprites/Sprites/frontal.png");
                Bomber->setPos(60,180);
                escena->addItem(Bomber);
                generar_enemigos();
                posx=60;
                posy=180;
                bandmuerte=true;
            }
        }
    //}
}
void MainWindow::muerte_enemigo2()
{
    //if(bandmuerte==true){
        if(level==1) enemigo2->setPixmap(QPixmap(valcomsprite[contmv]).scaled(60,60));
        else enemigo2->setPixmap(QPixmap(onealsprite[6]).scaled(60,60));
        contmv++;
        if(contmv==10 && level==1){
            puntos=puntos+100+puntosglob;
            ui->label->setNum(puntos);
            enemigo2->deleteLater();
            enemigos--;
            contmv=6;
            tiMuerte2->stop();
            if(bandmuerte==false){
                time=new QTimer;
                time->start(250);
                connect(time,SIGNAL(timeout()),this,SLOT(morir()));
            }
            if(enemigos==0){
                music->stop();
                puntosglob=puntos;
                enemigos=6;
                vidas=3;
                ui->label_4->setNum(vidas);
                if(level==1){
                    levelant=1;
                    level=2;
                }
                else{
                    levelant=2;
                    level=1;
                }
                Bomber->deleteLater();
                generar_mapa();
                Bomber=new objetos(":/sprites/Sprites/frontal.png");
                Bomber->setPos(60,180);
                escena->addItem(Bomber);
                generar_enemigos();
                posx=60;
                posy=180;
                bandmuerte=true;
            }
        }
        else if(contmv==7 && level==2){
            puntos=puntos+100;
            ui->label->setNum(puntos);
            enemigo2->deleteLater();
            enemigos--;
            contmv=6;
            tiMuerte2->stop();
            if(bandmuerte==false){
                time=new QTimer;
                time->start(250);
                connect(time,SIGNAL(timeout()),this,SLOT(morir()));
            }
            if(enemigos==0){
                music->stop();
                puntosglob=puntos;
                enemigos=6;
                vidas=3;
                ui->label_4->setNum(vidas);
                if(level==1){
                    levelant=1;
                    level=2;
                }
                else{
                    levelant=2;
                    level=1;
                }
                Bomber->deleteLater();
                generar_mapa();
                Bomber=new objetos(":/sprites/Sprites/frontal.png");
                Bomber->setPos(60,180);
                escena->addItem(Bomber);
                generar_enemigos();
                posx=60;
                posy=180;
                bandmuerte=true;
            }
        }
    //}
}
void MainWindow::muerte_enemigo3()
{
    //if(bandmuerte==true){
        if(level==1) enemigo3->setPixmap(QPixmap(valcomsprite[contmv]).scaled(60,60));
        else enemigo3->setPixmap(QPixmap(onealsprite[6]).scaled(60,60));
        contmv++;
        if(contmv==10 && level==1){
            puntos=puntos+100+puntosglob;
            ui->label->setNum(puntos);
            enemigo3->deleteLater();
            enemigos--;
            contmv=6;
            tiMuerte3->stop();
            if(bandmuerte==false){
                time=new QTimer;
                time->start(250);
                connect(time,SIGNAL(timeout()),this,SLOT(morir()));
            }
            if(enemigos==0){
                music->stop();
                puntosglob=puntos;
                enemigos=6;
                vidas=3;
                ui->label_4->setNum(vidas);
                if(level==1){
                    levelant=1;
                    level=2;
                }
                else{
                    levelant=2;
                    level=1;
                }
                Bomber->deleteLater();
                generar_mapa();
                Bomber=new objetos(":/sprites/Sprites/frontal.png");
                Bomber->setPos(60,180);
                escena->addItem(Bomber);
                generar_enemigos();
                posx=60;
                posy=180;
                bandmuerte=true;
            }
        }
        else if(contmv==7 && level==2){
            puntos=puntos+100;
            ui->label->setNum(puntos);
            enemigo3->deleteLater();
            enemigos--;
            contmv=6;
            tiMuerte3->stop();
            if(bandmuerte==false){
                time=new QTimer;
                time->start(250);
                connect(time,SIGNAL(timeout()),this,SLOT(morir()));
            }
            if(enemigos==0){
                music->stop();
                puntosglob=puntos;
                enemigos=6;
                vidas=3;
                ui->label_4->setNum(vidas);
                if(level==1){
                    levelant=1;
                    level=2;
                }
                else{
                    levelant=2;
                    level=1;
                }
                Bomber->deleteLater();
                generar_mapa();
                Bomber=new objetos(":/sprites/Sprites/frontal.png");
                Bomber->setPos(60,180);
                escena->addItem(Bomber);
                generar_enemigos();
                posx=60;
                posy=180;
                bandmuerte=true;
            }
        }
    //}
}
void MainWindow::muerte_enemigo4()
{
    //if(bandmuerte==true){
        if(level==1) enemigo4->setPixmap(QPixmap(valcomsprite[contmv]).scaled(60,60));
        else enemigo4->setPixmap(QPixmap(onealsprite[6]).scaled(60,60));
        contmv++;
        if(contmv==10 && level==1){
            puntos=puntos+100+puntosglob;
            ui->label->setNum(puntos);
            enemigo4->deleteLater();
            enemigos--;
            contmv=6;
            tiMuerte4->stop();
            if(bandmuerte==false){
                time=new QTimer;
                time->start(250);
                connect(time,SIGNAL(timeout()),this,SLOT(morir()));
            }
            if(enemigos==0){
                music->stop();
                puntosglob=puntos;
                enemigos=6;
                vidas=3;
                ui->label_4->setNum(vidas);
                if(level==1){
                    levelant=1;
                    level=2;
                }
                else{
                    levelant=2;
                    level=1;
                }
                Bomber->deleteLater();
                generar_mapa();
                Bomber=new objetos(":/sprites/Sprites/frontal.png");
                Bomber->setPos(60,180);
                escena->addItem(Bomber);
                generar_enemigos();
                posx=60;
                posy=180;
                bandmuerte=true;
            }
        }
        else if(contmv==7 && level==2){
            puntos=puntos+100;
            ui->label->setNum(puntos);
            enemigo4->deleteLater();
            enemigos--;
            contmv=6;
            tiMuerte4->stop();
            if(bandmuerte==false){
                time=new QTimer;
                time->start(250);
                connect(time,SIGNAL(timeout()),this,SLOT(morir()));
            }
            if(enemigos==0){
                music->stop();
                puntosglob=puntos;
                enemigos=6;
                vidas=3;
                ui->label_4->setNum(vidas);
                if(level==1){
                    levelant=1;
                    level=2;
                }
                else{
                    levelant=2;
                    level=1;
                }
                Bomber->deleteLater();
                generar_mapa();
                Bomber=new objetos(":/sprites/Sprites/frontal.png");
                Bomber->setPos(60,180);
                escena->addItem(Bomber);
                generar_enemigos();
                posx=60;
                posy=180;
                bandmuerte=true;
            }
        }
    //}
}
void MainWindow::muerte_enemigo5()
{
    //if(bandmuerte==true){
        if(level==1) enemigo5->setPixmap(QPixmap(valcomsprite[contmv]).scaled(60,60));
        else enemigo5->setPixmap(QPixmap(onealsprite[6]).scaled(60,60));
        contmv++;
        if(contmv==10 && level==1){
            puntos=puntos+100+puntosglob;
            ui->label->setNum(puntos);
            enemigo5->deleteLater();
            enemigos--;
            contmv=6;
            tiMuerte5->stop();
            if(bandmuerte==false){
                time=new QTimer;
                time->start(250);
                connect(time,SIGNAL(timeout()),this,SLOT(morir()));
            }
            if(enemigos==0){
                music->stop();
                puntosglob=puntos;
                enemigos=6;
                vidas=3;
                ui->label_4->setNum(vidas);
                if(level==1){
                    levelant=1;
                    level=2;
                }
                else{
                    levelant=2;
                    level=1;
                }
                Bomber->deleteLater();
                generar_mapa();
                Bomber=new objetos(":/sprites/Sprites/frontal.png");
                Bomber->setPos(60,180);
                escena->addItem(Bomber);
                generar_enemigos();
                posx=60;
                posy=180;
                bandmuerte=true;
            }
        }
        else if(contmv==7 && level==2){
            puntos=puntos+100;
            ui->label->setNum(puntos);
            enemigo5->deleteLater();
            enemigos--;
            contmv=6;
            tiMuerte5->stop();
            if(bandmuerte==false){
                time=new QTimer;
                time->start(250);
                connect(time,SIGNAL(timeout()),this,SLOT(morir()));
            }
            if(enemigos==0){
                music->stop();
                puntosglob=puntos;
                enemigos=6;
                vidas=3;
                ui->label_4->setNum(vidas);
                if(level==1){
                    levelant=1;
                    level=2;
                }
                else{
                    levelant=2;
                    level=1;
                }
                Bomber->deleteLater();
                generar_mapa();
                Bomber=new objetos(":/sprites/Sprites/frontal.png");
                Bomber->setPos(60,180);
                escena->addItem(Bomber);
                generar_enemigos();
                posx=60;
                posy=180;
                bandmuerte=true;
            }
        }
    //}
}
void MainWindow::muerte_enemigo6()
{
    //if(bandmuerte==true){
        if(level==1) enemigo6->setPixmap(QPixmap(valcomsprite[contmv]).scaled(60,60));
        else enemigo6->setPixmap(QPixmap(onealsprite[6]).scaled(60,60));
        contmv++;
        if(contmv==10 && level==1){
            puntos=puntos+100+puntosglob;
            ui->label->setNum(puntos);
            enemigo6->deleteLater();
            enemigos--;
            contmv=6;
            tiMuerte6->stop();
            if(bandmuerte==false){
                time=new QTimer;
                time->start(250);
                connect(time,SIGNAL(timeout()),this,SLOT(morir()));
            }
            if(enemigos==0){
                music->stop();
                puntosglob=puntos;
                enemigos=6;
                vidas=3;
                ui->label_4->setNum(vidas);
                if(level==1){
                    levelant=1;
                    level=2;
                }
                else{
                    levelant=2;
                    level=1;
                }
                Bomber->deleteLater();
                generar_mapa();
                Bomber=new objetos(":/sprites/Sprites/frontal.png");
                Bomber->setPos(60,180);
                escena->addItem(Bomber);
                generar_enemigos();
                posx=60;
                posy=180;
                bandmuerte=true;
            }
        }
        else if(contmv==7 && level==2){
            puntos=puntos+100;
            ui->label->setNum(puntos);
            enemigo6->deleteLater();
            enemigos--;
            contmv=6;
            tiMuerte6->stop();
            if(bandmuerte==false){
                time=new QTimer;
                time->start(250);
                connect(time,SIGNAL(timeout()),this,SLOT(morir()));
            }
            if(enemigos==0){
                music->stop();
                puntosglob=puntos;
                enemigos=6;
                vidas=3;
                ui->label_4->setNum(vidas);
                if(level==1){
                    levelant=1;
                    level=2;
                }
                else{
                    levelant=2;
                    level=1;
                }
                Bomber->deleteLater();
                generar_mapa();
                Bomber=new objetos(":/sprites/Sprites/frontal.png");
                Bomber->setPos(60,180);
                escena->addItem(Bomber);
                generar_enemigos();
                posx=60;
                posy=180;
                bandmuerte=true;
            }
        }
    //}
}

void MainWindow::keyPressEvent(QKeyEvent *i)
{
    if(i->key()==Qt::Key_D){
        if(contd==6) contd=3;
        if (bandmuerte==true)Bomber->setPixmap(QPixmap(movimientos[contd]).scaled(60,60));
        if(matriz[int((posx+60)/pixeles)][int((posy)/pixeles)-2]==0 && float(posy)/float(pixeles)==float((posy)/pixeles) && bandmuerte==true){
            Bomber->setPixmap(QPixmap(movimientos[contd]).scaled(60,60));
            Bomber->setX(Bomber->x()+10);
            contd++;
            posx=posx+10;
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
    else if(i->key()==Qt::Key_S){
        if(contf==3) contf=0;
        if (bandmuerte==true) Bomber->setPixmap(QPixmap(movimientos[contf]).scaled(60,60));
        if(matriz[int((posx)/pixeles)][int((posy+60)/pixeles)-2]==0 && float(posx)/float(pixeles)==float((posx)/pixeles) && bandmuerte==true){
            Bomber->setPixmap(QPixmap(movimientos[contf]).scaled(60,60));
            Bomber->setY(Bomber->y()+10);
            contf++;
            posy=posy+10;
        }
    }
    else if(i->key()==Qt::Key_B){
        if(bomb==false && bandmuerte==true){
            bsound->setMedia(QUrl("qrc:/Sonidos/Bomba.mp3"));
            bsound->play();
            bomba=new objetos(":/sprites/Sprites/bomba1.png");
            posxb=(posx/pixeles)*pixeles;
            posyb=(posy/pixeles)*pixeles;
            matriz[posxb/pixeles][(posyb/pixeles)-2]=2;
            bomba->setPos(posxb,posyb);
            escena->addItem(bomba);
            time=new QTimer;
            time->start(750);
            connect(time,SIGNAL(timeout()),this,SLOT(explotar()));
            bomb=true;
        }
    }
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

void MainWindow::generar_enemigos()
{
    int i=0;
    while(i<6){
        if(i==0){
            pose1x=2+rand()%(columnas-2);
            pose1y=2+rand()%(filas-2);
            if(matriz[pose1x][pose1y]==0){
                if(level==1) enemigo1=new objetos(valcomsprite[0]);
                else enemigo1=new objetos(onealsprite[0]);
                enemigo1->setPos(pose1x*pixeles,(pose1y+2)*pixeles);
                escena->addItem(enemigo1);
                i++;
            }
        }
        else if(i==1){
            pose2x=2+rand()%(columnas-2);
            pose2y=2+rand()%(filas-2);
            if(matriz[pose2x][pose2y]==0){
                if(level==1) enemigo2=new objetos(valcomsprite[0]);
                else enemigo2=new objetos(onealsprite[0]);
                enemigo2->setPos(pose2x*pixeles,(pose2y+2)*pixeles);
                escena->addItem(enemigo2);
                i++;
            }
        }
        else if(i==2){
            pose3x=2+rand()%(columnas-2);
            pose3y=2+rand()%(filas-2);
            if(matriz[pose3x][pose3y]==0){
                if(level==1) enemigo3=new objetos(valcomsprite[0]);
                else enemigo3=new objetos(onealsprite[0]);
                enemigo3->setPos(pose3x*pixeles,(pose3y+2)*pixeles);
                escena->addItem(enemigo3);
                i++;
            }
        }
        else if(i==3){
            pose4x=2+rand()%(columnas-2);
            pose4y=2+rand()%(filas-2);
            if(matriz[pose4x][pose4y]==0){
                if(level==1) enemigo4=new objetos(valcomsprite[0]);
                else enemigo4=new objetos(onealsprite[0]);
                enemigo4->setPos(pose4x*pixeles,(pose4y+2)*pixeles);
                escena->addItem(enemigo4);
                i++;
            }
        }
        else if(i==4){
            pose5x=2+rand()%(columnas-2);
            pose5y=2+rand()%(filas-2);
            if(matriz[pose5x][pose5y]==0){
                if(level==1) enemigo5=new objetos(valcomsprite[0]);
                else enemigo5=new objetos(onealsprite[0]);
                enemigo5->setPos(pose5x*pixeles,(pose5y+2)*pixeles);
                escena->addItem(enemigo5);
                i++;
            }
        }
        else if(i==5){
            pose6x=2+rand()%(columnas-2);
            pose6y=2+rand()%(filas-2);
            if(matriz[pose6x][pose6y]==0){
                if(level==1) enemigo6=new objetos(valcomsprite[0]);
                else enemigo6=new objetos(onealsprite[0]);
                enemigo6->setPos(pose6x*pixeles,(pose6y+2)*pixeles);
                escena->addItem(enemigo6);
                i++;
            }
        }
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QTimer *cronometro=new QTimer(this);
    connect(cronometro, SIGNAL(timeout()), this, SLOT(funcionActivacionTimer()));
    cronometro->start(1000);
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

    bombas[0]=":/sprites/Sprites/bomba1.png";
    bombas[1]=":/sprites/Sprites/bomba2.png";
    bombas[2]=":/sprites/Sprites/bomba3.png";
    bombas[3]=":/sprites/Sprites/expcentro.png";
    bombas[4]=":/sprites/Sprites/Fondo.png";
    bombas[5]=":/sprites/Sprites/expup.png";
    bombas[6]=":/sprites/Sprites/expl.png";
    bombas[7]=":/sprites/Sprites/expdown.png";
    bombas[8]=":/sprites/Sprites/expr.png";

    ladrillos[0]=":/sprites/Sprites/lades4.png";
    ladrillos[1]=":/sprites/Sprites/Fondo.png";

    valcomsprite[0]=":/sprites/Sprites/valcomiz1.png";
    valcomsprite[2]=":/sprites/Sprites/valcomiz2.png";
    valcomsprite[4]=":/sprites/Sprites/valcomiz3.png";
    valcomsprite[1]=":/sprites/Sprites/valcomde1.png";
    valcomsprite[3]=":/sprites/Sprites/valcomde2.png";
    valcomsprite[5]=":/sprites/Sprites/valcomde3.png";
    valcomsprite[6]=":/sprites/Sprites/valcmuerte1.png";
    valcomsprite[7]=":/sprites/Sprites/valcmuerte2.png";
    valcomsprite[8]=":/sprites/Sprites/valcmuerte3.png";
    valcomsprite[9]=":/sprites/Sprites/valcmuerte4.png";
    valcomsprite[10]=":/sprites/Sprites/valcmuerte5.png";

    onealsprite[0]=":/sprites/Sprites/onealiz1.png";
    onealsprite[2]=":/sprites/Sprites/onealiz2.png";
    onealsprite[4]=":/sprites/Sprites/onealiz3.png";
    onealsprite[1]=":/sprites/Sprites/onealde1.png";
    onealsprite[3]=":/sprites/Sprites/onealde2.png";
    onealsprite[5]=":/sprites/Sprites/onealde3.png";
    onealsprite[6]=":/sprites/Sprites/onealmuerte.png";

    muerte[0]=":/sprites/Sprites/explo1.png";
    muerte[1]=":/sprites/Sprites/explo2.png";
    muerte[2]=":/sprites/Sprites/explo3.png";
    muerte[3]=":/sprites/Sprites/explo4.png";
    muerte[4]=":/sprites/Sprites/explo5.png";
    muerte[5]=":/sprites/Sprites/explo6.png";
    muerte[6]=":/sprites/Sprites/Fondo.png";

    ui->setupUi(this);
    setup_mainwindow();
    generar_mapa();
    tiMuerte1=new QTimer;
    tiMuerte2=new QTimer;
    tiMuerte3=new QTimer;
    tiMuerte4=new QTimer;
    tiMuerte5=new QTimer;
    tiMuerte6=new QTimer;
    bsound= new QMediaPlayer();
    esound= new QMediaPlayer();
    msound= new QMediaPlayer();
    Bomber=new objetos(":/sprites/Sprites/frontal.png");
    Bomber->setPos(60,180);
    escena->addItem(Bomber);
    generar_enemigos();
    time=new QTimer;
    time->start(450);
    connect(time,SIGNAL(timeout()),this,SLOT(mover()));
    ui->label->setNum(puntos);
    ui->label_4->setNum(vidas);
    ui->graphicsView->setScene(escena);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete escena;
    delete Bomber;
    delete bomba;
    delete bombar;
    delete bombal;
    delete bombau;
    delete bombad;
    delete enemigo1;
    delete enemigo2;
    delete enemigo3;
    delete enemigo4;
    delete enemigo5;
    delete enemigo6;
    delete time;
    delete tiMuerte1;
    delete tiMuerte2;
    delete tiMuerte3;
    delete tiMuerte4;
    delete tiMuerte5;
    delete tiMuerte6;
    for(int x=0; x<columnas; x++) for(int y=0; y<filas; y++) delete mapa[x][y];
    delete l_mapa;
    delete puntaje;
    delete bsound;
    delete esound;
    delete msound;
    delete music;
}
