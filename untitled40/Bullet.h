#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include<QGraphicsPixmapItem>
#include<QMediaPlayer>

class Bullet : public QGraphicsPixmapItem
{
    const static int mSpeed=3;
public:
    enum BulletType
    {
        BT_Player,
        BT_Enemy
    };
    explicit Bullet(QObject *parent = nullptr);
    Bullet(QPoint _pos,QPixmap _img,int _type);
    Bullet(QPoint _pos, QPixmap _img);

    int mBulletType;

    void BulletMove_right(QPoint _dir=QPoint (mSpeed,0));
    void BulletMove_left(QPoint _dir=QPoint (mSpeed,0));

    QMediaPlayer mMedia_bullet;
    void bullet_sound();


signals:
};

#endif // BULLET_H
