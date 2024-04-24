#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include<QGraphicsView>
#include<QGraphicsScene>
#include<QTimer>
#include<QList>
#include<QGraphicsPixmapItem>
#include"Bullet.h"
#include"Enemy.h"
#include"Player.h"
#include"fuxian.h"
class Gamecontrol
{
public:
    Gamecontrol();
    static Gamecontrol* instance;
public:
    static Gamecontrol*Instance()
    {
        if(instance==nullptr)
        {
            return instance=new Gamecontrol;
        }
    }
    ~Gamecontrol()
    {
        if(instance!=nullptr)
        {
            delete instance;
        }
        instance=nullptr;
    }

    //初始化
    void GameInit();
    //游戏定时器
    void GameStart();
    //游戏结束
    void Gameover();
protected:
    QGraphicsView mGameview;
    QGraphicsScene mScene;
    QGraphicsScene gamestart;


    Player fufuplayer;
    fuxian boss1;
    bool facingside=true;
    bool shoot=false;
    bool flying_condition=false;
    bool defense_condition=false;
    bool defense_switch=false;
    bool attackingmagic_controller=false;


    QGraphicsPixmapItem mCloud;
    QGraphicsPixmapItem mGrass;
    QGraphicsPixmapItem mSky;
    QGraphicsPixmapItem background[10];
    QGraphicsPixmapItem Defensemagic;

    //移动定时器
    QTimer*mbackgroundTimer;
    QTimer*fufuMoveTimer;
    QTimer*fufufacingside;
    QTimer*location_restrict;
    QTimer*normalattackingmagictimer;
    QTimer*bullet_controller;
    QTimer*magicmove;
    QTimer*mEnemycreatTimer;
    QTimer*mEnemymove;
    QTimer*flying_timer;
    QTimer*Enemyattckingmovetimer;
    QTimer*Enemyattackingcreattimer;
    QTimer*defensemagictimer;
    //容器
    QList<int>mKeyList1;
    QList<Bullet*>mBulletList_left;
    QList<Bullet*>mBulletList_right;
    QList<Bullet*>EnemyBulletList;
    QList<Enemy*>mEnemyList_left;
    QList<Enemy*>mEnemyList_right;
    QList<fuxian*>mfuxianList;

};

#endif // GAMECONTROL_H
