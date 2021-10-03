#ifndef OBJETOS_H
#define OBJETOS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>

class objetos : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    objetos();
    objetos(int tam);
    objetos(QString name);
    void setup_tipo(int tipo);
    void resize(int x,int y);
private:
    QString mapa[4];
    int size;
};

#endif // OBJETOS_H
