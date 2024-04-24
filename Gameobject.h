#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QObject>
#include<QGraphicsPixmapItem>

class Gameobject : public QGraphicsPixmapItem
{

public:
    explicit Gameobject(QObject *parent = nullptr);

signals:
};

#endif // GAMEOBJECT_H
