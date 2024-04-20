#include "fuxian.h"

fuxian::fuxian(QObject *parent)
    : QObject{parent}
{
    killingmagicstarter.setPixmap(QPixmap(":/Enemy/Enemy/fuxianplus.png"));
    killingmagicstarter.setPos(QPoint(813,20));
}
