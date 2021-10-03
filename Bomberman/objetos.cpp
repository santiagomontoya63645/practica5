#include "objetos.h"

objetos::objetos()
{

}

objetos::objetos(int tam) //Bloques para diseñar el mapa
{
    mapa[0]=":/sprites/Sprites/Fondo.png";
    mapa[1]=":/sprites/Sprites/ladrillo.png";
    mapa[2]=":/sprites/Sprites/bloque.png";
    mapa[3]=":/sprites/Sprites/Bloque_puntaje.png";

    size=tam;
}

objetos::objetos(QString name) //Se usa para el personaje y la bomba
{
    setPixmap(QPixmap(name).scaled(60,60));
}

void objetos::setup_tipo(int tipo)
{
    setPixmap(QPixmap(mapa[tipo]).scaled(size,size));
}

void objetos::resize(int x, int y)
{
    setPixmap(QPixmap(mapa[3]).scaled(x,y));
}
