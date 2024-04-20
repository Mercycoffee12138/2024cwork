#include "Bullet.h"

Bullet::Bullet(QObject *parent)
    {}
Bullet::Bullet(QPoint _pos, QPixmap _img)
{
    this->setPos(_pos);
    this->setPixmap(_img);

}
Bullet::Bullet(QPoint _pos, QPixmap _img, int _type)
{
    this->setPos(_pos);
    this->setPixmap(_img);
    mBulletType=_type;

}

void Bullet::BulletMove_left(QPoint _dir)
{
    this->moveBy(-(_dir.x()),_dir.y());
}

void Bullet::bullet_sound()
{
    if(mBulletType==BT_Player)
    {
        mMedia_bullet.setSource(QUrl("qrc:/music/Music/hit.wav"));
    }
}

void Bullet::BulletMove_right(QPoint _dir)
{
    this->moveBy(_dir.x(),_dir.y());
}

