#include "Gamecontrol.h"


Gamecontrol* Gamecontrol::instance=nullptr;
Gamecontrol::Gamecontrol() {}

void Gamecontrol::GameInit()
{
    mGameview.setSceneRect(QRect(0,0,1278,720));
    mScene.setSceneRect(QRect(0,0,1280,720));
    gamestart.setSceneRect(QRect(0,0,1280,720));
    gamestart.addPixmap(QPixmap(":/background/Map/start.png"));
}
