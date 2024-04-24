#ifndef GAMEOBJECTPOOL_H
#define GAMEOBJECTPOOL_H

#include <QObject>

class GameObjectPool : public QObject
{
    Q_OBJECT
public:
    explicit GameObjectPool(QObject *parent = nullptr);

signals:
};

#endif // GAMEOBJECTPOOL_H
