#include "logica.h"

logica::logica(int col, int fil)
{
    srand(time(NULL));
    x=col;
    y=fil;
}

int **logica::generar_mapa()
{
    matriz = new int * [x];
    for(int col=0;col<x;col++){
        matriz[col] = new int [y];
        for(int fil=0;fil<y;fil++){
            if(col==0 || col==x-1 || fil==0 || fil==y-1 || (fil%2==0 && col%2==0)) matriz[col][fil]=2;
            else if(!aleatorio() || (col==1 && fil==1) || (col==2 && fil==1) || (col==1 && fil==2)) matriz[col][fil]=0;
            else matriz[col][fil]=1;
        }
    }
    return matriz;
}

logica::~logica()
{
    delete [] matriz;
}

bool logica::aleatorio()
{
    int n, x;
    n=rand();
    x=p*(RAND_MAX+1)-1;
    return n<=x;
}
