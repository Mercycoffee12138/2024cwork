#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include<QGraphicsPixmapItem>

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = nullptr);
    QGraphicsPixmapItem fufu;
signals:
};

#endif // PLAYER_H
