#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
#include<QToolButton>
#include<QTimer>
#include<QKeyEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->setupUi(this);
    this->setFixedSize(1280,720);

    mGameview.setSceneRect(QRect(0,0,1278,720));
    mScene.setSceneRect(QRect(0,0,1280,720));
    gamestart.setSceneRect(QRect(0,0,1280,720));
    gamestart.addPixmap(QPixmap(":/background/Map/start.png"));

    auto startbtn=new QPushButton();
        //startbtn->autoRaise();
    //startbtn->resize(175,70);
    startbtn->setFlat(true);
    startbtn->setFocusPolicy(Qt::NoFocus);
    startbtn->setIcon(QIcon(":/start/start/ui_start_idle.png"));
    startbtn->setIconSize(QSize(175,70));
    startbtn->move(549,500);
    connect(startbtn,&QToolButton::clicked,[this](){
        mGameview.setScene(&mScene);
        mGameview.show();
        //背景音乐
        this->mMeidaBG=new QMediaPlayer;
        this->mMeidaBG->setSource(QUrl("qrc:/music/Music/bgm.mp3"));
        this->mMeidaBG->play();
    });
    gamestart.addWidget(startbtn);




    for(int i=0;i<10;i++)
    {
        background[i].setPixmap(QPixmap(":/background/Map/background1.png"));
        mScene.addItem(&background[i]);
        background[i].setPos(1279*(i-4),0);
    }
    mCloud.setPixmap(QPixmap(":/background/Map/cloud1.png"));
    Defensemagic.setPixmap(QPixmap(":/bullet/bullet/defense_001.png"));
    //设置位置
    mCloud.setPos(650,50);
    //player_right_001.setPos(250,340);
    //图片元素添加到场景

    mScene.addItem(&mCloud);
    mScene.addItem(&fufuplayer.fufu);
    mScene.addItem(&boss1.killingmagicstarter);
    //设置视图场景
    mGameview.setScene(&mScene);
    mGameview.setScene(&gamestart);
    mGameview.setParent(this);
    mGameview.show();

    //人物移动
    fufuMoveTimer=new QTimer(this);
    fufuMoveTimer->start(1000/144);
    connect(fufuMoveTimer,&QTimer::timeout,this,&Widget::fufuMove);
    //角色朝向
    fufufacingside=new QTimer(this);
    fufufacingside->start(1000/144);
    connect(fufufacingside,&QTimer::timeout,this,&Widget::player_facingside);
    connect(fufufacingside,&QTimer::timeout,this,&Widget::player_gravity);

    //fufu攻击子弹生成
    normalattackingmagictimer=new QTimer(this);
    normalattackingmagictimer->start(1000/144);
    connect(normalattackingmagictimer,&QTimer::timeout,this,&Widget::normalattackingmagic);

    bullet_controller=new QTimer(this);
    bullet_controller->start(1000/144);
    connect(bullet_controller,&QTimer::timeout,this,&Widget:: attckingmagiccontroller);

    //子弹移动
    magicmove=new QTimer(this);
    magicmove->start(1000/144);
    connect(magicmove,&QTimer::timeout,[this](){
        for(auto bullet:mBulletList_right)
        {
            bullet->BulletMove_right();
        }
        for(auto bullet:mBulletList_left)
        {
            bullet->BulletMove_left();
        }
    });

    mEnemycreatTimer=new QTimer(this);
    mEnemycreatTimer->start(5000);
    connect(mEnemycreatTimer,&QTimer::timeout,this,&Widget::CreatEnemy);

    mEnemymove=new QTimer(this);
    mEnemymove->start(1000/144);
    connect(mEnemymove,&QTimer::timeout,[this](){
        for(auto enemy:mEnemyList_left)
        {
            enemy->EnemyMove_left();
        }
        for(auto enemy:mEnemyList_right)
        {
            enemy->EnemyMove_right();
        }
    });

    flying_timer=new QTimer(this);
    flying_timer->start(1000/144);
    connect(flying_timer,&QTimer::timeout,this,&Widget::flyingmagic);

    Enemyattackingcreattimer=new QTimer(this);
    Enemyattackingcreattimer->start(50000/144);
    connect(Enemyattackingcreattimer,&QTimer::timeout,this,&Widget::Enemyattckingmagic);

    Enemyattckingmovetimer=new QTimer(this);
    Enemyattckingmovetimer->start(900/144);
    connect(Enemyattckingmovetimer,&QTimer::timeout,[this](){
        for(auto bullet:EnemyBulletList)
        {
            bullet->BulletMove_left();
        }
    });

    defensemagictimer=new QTimer(this);
    defensemagictimer->start(1000/144);
    connect(defensemagictimer,&QTimer::timeout,this,&Widget::normaldefensemagic);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::fufuMove()
{
    for(int KeyCode:mKeyList1)
    {
        switch(KeyCode)
        {
        case Qt::Key_S:{
            if(fufuplayer.fufu.y()+fufu_Speed>340){fufuplayer.fufu.setY(340);break;}
            else{fufuplayer.fufu.moveBy(0,fufu_Speed);break;}}
        case Qt::Key_A:{
            if(fufuplayer.fufu.x()-fufu_Speed<0)
            {fufuplayer.fufu.setX(0);
                for(int i=0;i<10;i++)
                {
                    background[i].moveBy(fufu_Speed,0);
                }
                mCloud.moveBy(fufu_Speed,0);
                break;
            }
            else
            {fufuplayer.fufu.moveBy(-fufu_Speed,0);break;}}
        case Qt::Key_D:{
            if(fufuplayer.fufu.x()+fufu_Speed>798)
            {fufuplayer.fufu.setX(798);
                for(int i=0;i<10;i++)
                {
                    background[i].moveBy(-fufu_Speed,0);
                }
                mCloud.moveBy(-fufu_Speed,0);
                break;
            }
            else
            {fufuplayer.fufu.moveBy(fufu_Speed,0);break;}}
        }
    }
}

void Widget::keyPressEvent(QKeyEvent *event)
{
    mKeyList1.append(event->key());
    switch(event->key())
    {
    case::Qt::Key_Y:{defense_condition=true;break;}
    case::Qt::Key_J:{flying_condition=true;break;}
    case::Qt::Key_G:{attackingmagic_controller=true;shoot=true;break;}
    case Qt::Key_A:{facingside=false;break;}
    case Qt::Key_D:{facingside=true;break;}
    }
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    //移除按键
    switch (event->key()) {
    case::Qt::Key_Y:{defense_condition=false;break;}
    case::Qt::Key_J:{flying_condition=false;break;}
    case::Qt::Key_G:{shoot=false;break;}
    }
    if(mKeyList1.contains(event->key()))
    {
        mKeyList1.removeOne(event->key());
    }
}

void Widget::player_facingside()
{
    if(facingside)
    {
        fufuplayer.fufu.setPixmap(QPixmap(":/player/Player/fufu_right_001.png"));
    }
    else
    {
        fufuplayer.fufu.setPixmap(QPixmap(":/player/Player/fufu_left_001.png"));
    }
}

void Widget::player_gravity()
{
    if(fufuplayer.fufu.y()<340)
    {
        fufuplayer.fufu.moveBy(0,gravity);
    }
}

void Widget::attckingmagiccontroller()
{
    if(attackingmagic_controller)
    {
        attackingmagic_controller=false;
    }
}

void Widget::normalattackingmagic()
{
    if(facingside&&shoot&&attackingmagic_controller)
    {
        QPixmap img(":/bullet/bullet/bullets_003.png");
        //QPixmap img(":/bullet/bullet/bullets_001.png");
        QPoint pos(fufuplayer.fufu.x()+132,fufuplayer.fufu.y()+17);
       // int randy=(rand()%660);
        //QPoint pos(fufuplayer.fufu.x()+132,randy);
        Bullet *bullet=new Bullet(pos,img,0);
        mScene.addItem(bullet);
        mBulletList_right.append(bullet);
    }
    else if(!facingside&&shoot&&attackingmagic_controller)
    {
        QPixmap img(":/bullet/bullet/bullets_001.png");
        QPoint pos(fufuplayer.fufu.x(),fufuplayer.fufu.y()+17);
        Bullet *bullet=new Bullet(pos,img,0);
        mScene.addItem(bullet);
        mBulletList_left.append(bullet);
    }

}

void Widget::flyingmagic()
{
    for(int KeyCode:mKeyList1)
    {
        switch(KeyCode)
        {
        case Qt::Key_W:{
            if(flying_condition)
            {
                if(fufuplayer.fufu.y()-fufu_Speed<0)
                {
                    fufuplayer.fufu.setY(0);
                    break;
                }
                else
                {
                    fufuplayer.fufu.moveBy(0,-fufu_Speed*2);
                    break;
                }
            }
            else if(!flying_condition&&fufuplayer.fufu.y()<290)
            {
                break;
            }
            else if(!flying_condition&&fufuplayer.fufu.y()>290)
            {
                if(fufuplayer.fufu.y()>290&&fufuplayer.fufu.y()-fufu_Speed<290)
                {
                    fufuplayer.fufu.setY(290);
                    break;
                }
                else if(fufuplayer.fufu.y()<290)
                {
                    fufuplayer.fufu.setY(290);
                }
                else
                {
                    fufuplayer.fufu.moveBy(0,-fufu_Speed-gravity);
                    break;
                }
            }
        }
        }
    }
}

void Widget::normaldefensemagic()
{
    if(defense_condition)
    {
        QPoint _pos(fufuplayer.fufu.x()+150,fufuplayer.fufu.y()-20);
        Defensemagic.setPos(_pos);
        mScene.addItem(&Defensemagic);
        defense_switch=true;
    }
    else if(!defense_condition&&defense_switch)
    {
        mScene.removeItem(&Defensemagic);
        defense_switch=false;
    }
}

void Widget::CreatEnemy()
{
    int rand_enemy_left=(rand()%4)+1;
    int rand_enemy_right=(rand()%4)+1;
    QString str1;
    QString str2;
    str1=QString(":/Enemy/Enemy/enemy_00%1_left.png").arg(rand_enemy_left);
    str2=QString(":/Enemy/Enemy/enemy_00%1_right.png").arg(rand_enemy_right);
    QPixmap pixmap1(str1);
    QPixmap pixmap2(str2);
    int randy1=(rand()%480);
    int randy2=(rand()%480);
    Enemy*enemy1=new Enemy(QPoint(1280,randy1),pixmap1);
    Enemy*enemy2=new Enemy(QPoint(-300,randy2),pixmap2);

    mScene.addItem(enemy1);
    mScene.addItem(enemy2);

    mEnemyList_left.append(enemy1);
    mEnemyList_right.append(enemy2);
}

void Widget::Enemyattckingmagic()
{
    QPixmap img(":/bullet/bullet/bullets_001 (2).png");
    int randy=(rand()%660);
    QPoint pos(790,randy);
    Bullet *bullet=new Bullet(pos,img,0);
    mScene.addItem(bullet);
    mBulletList_left.append(bullet);
}



