#include "Enemy.h"

Enemy::Enemy(QObject *parent)
{}
Enemy::Enemy(QPoint _pos, QPixmap _img)
{
    this->Enemy_Speed=0.3;
    this->setPos(_pos);
    this->setPixmap(_img);
}

void Enemy::EnemyMove_right(QPoint _dir)
{
    this->moveBy(_dir.x()*Enemy_Speed,_dir.y()*Enemy_Speed);
}

void Enemy::EnemyMove_left(QPoint _dir)
{
    this->moveBy(-(_dir.x()*Enemy_Speed),-(_dir.y()*Enemy_Speed));
}
