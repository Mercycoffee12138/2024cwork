#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include<QGraphicsPixmapItem>

class Enemy : public QGraphicsPixmapItem
{
public:
    explicit Enemy(QObject *parent = nullptr);
    Enemy(QPoint _pos,QPixmap _img);
    double Enemy_Speed;
    void EnemyMove_left(QPoint _dir=QPoint (2,0));
    void EnemyMove_right(QPoint _dir=QPoint (2,0));
signals:
};

#endif // ENEMY_H
