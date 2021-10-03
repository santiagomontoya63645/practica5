#ifndef LOGICA_H
#define LOGICA_H

#include <cstdlib>
#include <time.h>

class logica
{
public:
    logica(int col, int fil);
    int **generar_mapa();
    ~logica();
    float p=0.3;
private:
    bool aleatorio();
    int ** matriz;
    int x,y;
};

#endif // LOGICA_H
