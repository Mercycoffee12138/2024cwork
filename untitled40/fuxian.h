#ifndef FUXIAN_H
#define FUXIAN_H

#include <QObject>
#include<QGraphicsPixmapItem>

class fuxian : public QObject
{
    Q_OBJECT
public:
    explicit fuxian(QObject *parent = nullptr);
    QGraphicsPixmapItem killingmagicstarter;
signals:
};

#endif // FUXIAN_H
