#include "snake.h"
#include "ui_snake.h"
#include<QPainter>
#include<QTimer>

Snake::Snake(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Snake)
{
    ui->setupUi(this);
    this->setGeometry(QRect(900,300,290,310)); //距左边框，上边框，长，宽

}

Snake::~Snake()
{
    delete ui;
}

void Snake::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    InitSnake();
    //画面背景
    //外墙
    painter.setPen(Qt::black);
    painter.setBrush(Qt::gray);
    painter.drawRect(15,15,260,260);

    //内墙
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.drawRect(20,20,250,250);

    //画格子
    painter.setPen(Qt::gray);
    for(int i=2;i<=27;i++){
        painter.drawLine(20,i*10,270,i*10);  //起点坐标到终点的坐标
        painter.drawLine(i*10,20,i*10,270);  //画竖线，横坐标不变
    }
    //画蛇
    painter.setPen(Qt::black);
    painter.setBrush(Qt::blue);
    painter.drawRect(vSnakeRect);
}
void Snake::InitSnake(){
    QRect rect(100,70,10,10);
    vSnakeRect=rect;

    timer=new QTimer(this); //设定计时器
    timer->start(500);     //500ms触发一次
    connect(timer,SIGNAL(timeout()),SLOT(snake_update()));  //信号与槽（触发的函数）
}
void Snake::Snake_update(){

}
void Snake::keyPressEvent(QKeyEvent *event){
    QKeyEvent *key=(QKeyEvent*) event;
    switch(key->ket()){
        case Qt::Key_Up:Direction=1;
        break;
    case


    }
}
