#include "Player.h"

Player::Player(QObject *parent)
    : QObject{parent}
{
    fufu.setPixmap(QPixmap(":/player/Player/fufu_right_001.png"));
    fufu.setPos(250,340);
}
