#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QGraphicsPixmapItem>
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QTimer>
#include<QList>
#include"Player.h"
#include"Bullet.h"
#include"Enemy.h"
#include<QMediaPlayer>
#include"fuxian.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    //人物移动
    void fufuMove();
    //按键事件
    void keyPressEvent(QKeyEvent*event);
    void keyReleaseEvent(QKeyEvent*event);

    void player_facingside();
    void player_gravity();
    void attckingmagiccontroller();

    void normalattackingmagic();
    void flyingmagic();
    void normaldefensemagic();
    void flyingappearance();
    void defensemagic();

    void CreatEnemy();

    void Enemyattckingmagic();
    void fuxiandefensemagic();
    void fuxiandefensemagicover();


    void Collision_fuxian();
    void Collision_fufu();


    void start();
    void backgroundchange();

private:
    Ui::Widget *ui;

    double background_Speed=-0.8;
    double cloud_Speed=-0.8;
    double fufu_Speed=1.5;
    double gravity=1;

    QGraphicsView mGameview;
    QGraphicsScene mScene;
    QGraphicsScene gamestart;


    Player fufuplayer;
    fuxian *boss1=new fuxian;
    bool facingside=true;
    bool shoot=false;
    bool flying_condition=false;
    bool flying_switch=false;
    bool defense_condition=false;
    bool defense_switch=false;
    bool attackingmagic_controller=false;

    bool the_first=true;
    bool the_second=false;

    bool fuxiandefense_condition[8]={false,false,false,false,false,false,false,false};
    bool start_condition=false;
    bool changeend=true;


    QGraphicsPixmapItem mCloud;
    QGraphicsPixmapItem mGrass;
    QGraphicsPixmapItem mSky;
    QGraphicsPixmapItem background[10];
    QGraphicsPixmapItem Defensemagic;
    QGraphicsPixmapItem fuxiandefense;

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
    QTimer*defenseusedmagictimer;
    QTimer*Backgroundchangetimer;
    //容器
    QList<int>mKeyList1;
    QList<Bullet*>mBulletList_left;
    QList<Bullet*>mBulletList_right;
    QList<Bullet*>EnemyBulletList;
    QList<Enemy*>mEnemyList_left;
    QList<Enemy*>mEnemyList_right;
    QList<fuxian*>mfuxianList;
    QList<QGraphicsPixmapItem*>DefensemagicList;

    //背景音乐
    QMediaPlayer *mMeidaBG;


};
#endif // WIDGET_H
