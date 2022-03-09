#include "snake.h"
#include "ui_snake.h"
#include<qrect.h>
#include<qtimer.h>
#include<QKeyEvent>
#include<QDebug>
#include<QFont>
#include<QPixmap>


Snake::Snake(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Snake),blsrun(false),speed(500)
{
    ui->setupUi(this);
    this->setGeometry(QRect(600,300,290,310)); //距左边框，上边框，长，宽

}

Snake::~Snake()
{
    delete ui;
}

void Snake::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    if(!blsrun){
        InitSnake();
    }
    //画面背景

    //外墙
    painter.setPen(Qt::black);
    painter.setBrush(Qt::gray);
    painter.drawRect(15,15,260,260);

    //内墙
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.drawRect(20,20,250,250);
    painter.drawPixmap(20,20,250,250,QPixmap(":/new/prefix1/image/nasa.jpg"));
    //画格子
    painter.setPen(Qt::gray);
//    for(int i=2;i<=27;i++){
//        painter.drawLine(20,i*10,270,i*10);  //起点坐标到终点的坐标
//        painter.drawLine(i*10,20,i*10,270);  //画竖线，横坐标不变
//    }

    //显示游戏开始、结束
    QFont font1("Courier",24);
    painter.setFont(font1);
    painter.setPen(Qt::red);
    painter.setBrush(Qt::red);
    painter.drawText(40,150,sDisplay);
    //得分显示
    QFont font2("Courier",15);
    painter.setFont(font2);
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::blue);
    painter.drawText(140,300,scoreLabel);
    painter.drawText(230,300,QString::number(nScore));

    //画蛇
    painter.setPen(Qt::black);
    painter.setBrush(Qt::blue);
    //painter.drawRect(vSnakeRect);
    painter.drawRect(food);
    painter.drawRects(&vSnakeRect[0],vSnakeRect.size());
    if(blsOver)//游戏结束，停止计时器
        timer->stop();

}
void Snake::InitSnake(){
    Direction=2;
    blsrun=true;
    blsOver=false;

    sDisplay="游戏开始";
    scoreLabel="得分：";
    nScore=0;
    food=CreateRect();//创建食物
    //QRect rect(100,70,10,10);
    //vSnakeRect=rect;
    vSnakeRect.resize(5);
    for(int i=0;i<vSnakeRect.size();i++){
        QRect rect(100,70+10*i,10,10);
        vSnakeRect[vSnakeRect.size()-1-i]=rect;
    }
    timer=new QTimer(this); //设定计时器
    timer->start(speed);     //500ms触发一次
    connect(timer,SIGNAL(timeout()),SLOT(Snake_Update()));  //信号与槽（触发的函数）
}
void Snake::Snake_Update(){
    sDisplay="";
    SnakeHead=vSnakeRect.first();
    IsEat();
    IsHit();
    for(int j=0;j<vSnakeRect.size()-1;j++)
        vSnakeRect[vSnakeRect.size()-1-j]=vSnakeRect[vSnakeRect.size()-2-j];

    switch (Direction) {
    case 1:
        SnakeHead.setTop(SnakeHead.top()-10);
        SnakeHead.setBottom(SnakeHead.bottom()-10);
        break;
    case 2:
        SnakeHead.setTop(SnakeHead.top()+10);
        SnakeHead.setBottom(SnakeHead.bottom()+10);
        break;
    case 3:
        SnakeHead.setLeft(SnakeHead.left()-10);
        SnakeHead.setRight(SnakeHead.right()-10);
        break;
    case 4:
        SnakeHead.setLeft(SnakeHead.left()+10);
        SnakeHead.setRight(SnakeHead.right()+10);
    default:;



    }
    vSnakeRect[0]=SnakeHead;
    if(SnakeHead.left()<20||SnakeHead.right()>270||SnakeHead.top()<20 || SnakeHead.bottom()>270){
        sDisplay="游戏结束";
        blsOver=true;
    }

    update();//paintEvent更新


    update();

}
void Snake::keyPressEvent(QKeyEvent *event){
    QKeyEvent *key=(QKeyEvent*) event;
    switch(key->key()){
    case Qt::Key_Up:Direction=1;
        break;
    case Qt::Key_Down:Direction=2;   //2代表下
        break;
    case Qt::Key_Left:Direction=3;   //3代表左
        break;
    case Qt::Key_Right:Direction=4;   //4代表右
        break;
    default:;
    }
}
QRect Snake::CreateRect(){
    int x,y;
    x=qrand()%25;//生成小于25的整数
    y=qrand()%25;
    QRect rect(20+x*10,20+y*10,10,10);//食物小方块位置
    return rect;
}
void Snake::IsEat(){
    if(SnakeHead==food){//如果蛇头和食物重合，说明已经撞到食物了
        SnakeHead=food;//吃到食物，食物就变为蛇头
        nScore+=10;
        vSnakeRect.push_back(vSnakeRect.last());//将最后一个节点再次加到容器里，让蛇身变长
        food=CreateRect();//吃到食物后再生成一个食物
        speed-=50;
        timer->stop();
        timer->start(speed);
    }

}
void Snake::IsHit(){
    for(int i=1;i<vSnakeRect.size();i++){//遍历蛇身
        if(SnakeHead==vSnakeRect[i]){//蛇头和蛇身重合
            sDisplay="游戏结束";
            blsOver=true;
            update();
        }
    }
}
