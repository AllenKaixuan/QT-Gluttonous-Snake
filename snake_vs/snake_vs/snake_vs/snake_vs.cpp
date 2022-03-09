#include "snake_vs.h"
#include "ui_snake_vs.h"
#include<qrect.h>
#include<qtimer.h>
#include<QKeyEvent>
#include<QDebug>
#include<QFont>
#include<QPixmap>


Snake::Snake(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::SnakeClass), blsrun(false), speed(500)
{
   /* ui->setupUi(this);*/
    this->setGeometry(QRect(600, 300, 290, 310)); //����߿��ϱ߿򣬳�����

}

Snake::~Snake()
{
    delete ui;
}

void Snake::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    if (!blsrun) {
        InitSnake();
    }
    //���汳��

    //��ǽ
    painter.setPen(Qt::black);
    painter.setBrush(Qt::gray);
    painter.drawRect(15, 15, 260, 260);

    //��ǽ
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.drawRect(20, 20, 250, 250);
    painter.drawPixmap(20, 20, 250, 250, QPixmap(":/new/prefix1/image/nasa.jpg"));
    //������
    painter.setPen(Qt::gray);
    //    for(int i=2;i<=27;i++){
    //        painter.drawLine(20,i*10,270,i*10);  //������굽�յ������
    //        painter.drawLine(i*10,20,i*10,270);  //�����ߣ������겻��
    //    }

        //��ʾ��Ϸ��ʼ������
    QFont font1("Times", 24);
    painter.setFont(font1);
    painter.setPen(Qt::red);
    painter.setBrush(Qt::red);
    painter.drawText(40, 150, sDisplay);
    //�÷���ʾ
    QFont font2("Times", 15);
    painter.setFont(font2);
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::blue);
    painter.drawText(140, 300, scoreLabel);
    painter.drawText(230, 300, QString::number(nScore));

    //����
    painter.setPen(Qt::black);
    painter.setBrush(Qt::blue);
    //painter.drawRect(vSnakeRect);
    painter.drawRect(food);
    painter.drawRects(&vSnakeRect[0], vSnakeRect.size());
    if (blsOver)//��Ϸ������ֹͣ��ʱ��
        timer->stop();

}
void Snake::InitSnake() {
    Direction = 2;
    blsrun = true;
    blsOver = false;

    sDisplay = "game start";
    scoreLabel = "score:";
    nScore = 0;
    food = CreateRect();//����ʳ��
    //QRect rect(100,70,10,10);
    //vSnakeRect=rect;
    vSnakeRect.resize(5);
    for (int i = 0; i < vSnakeRect.size(); i++) {
        QRect rect(100, 70 + 10 * i, 10, 10);
        vSnakeRect[vSnakeRect.size() - 1 - i] = rect;
    }
    timer = new QTimer(this); //�趨��ʱ��
    timer->start(speed);     //500ms����һ��
    connect(timer, SIGNAL(timeout()), SLOT(Snake_Update()));  //�ź���ۣ������ĺ�����
}
void Snake::Snake_Update() {
    sDisplay = "";
    SnakeHead = vSnakeRect.first();
    IsEat();
    IsHit();
    for (int j = 0; j < vSnakeRect.size() - 1; j++)
        vSnakeRect[vSnakeRect.size() - 1 - j] = vSnakeRect[vSnakeRect.size() - 2 - j];

    switch (Direction) {
    case 1:
        SnakeHead.setTop(SnakeHead.top() - 10);
        SnakeHead.setBottom(SnakeHead.bottom() - 10);
        break;
    case 2:
        SnakeHead.setTop(SnakeHead.top() + 10);
        SnakeHead.setBottom(SnakeHead.bottom() + 10);
        break;
    case 3:
        SnakeHead.setLeft(SnakeHead.left() - 10);
        SnakeHead.setRight(SnakeHead.right() - 10);
        break;
    case 4:
        SnakeHead.setLeft(SnakeHead.left() + 10);
        SnakeHead.setRight(SnakeHead.right() + 10);
    default:;



    }
    vSnakeRect[0] = SnakeHead;
    if (SnakeHead.left() < 20 || SnakeHead.right() > 270 || SnakeHead.top() < 20 || SnakeHead.bottom() > 270) {
        sDisplay = "game over";
        blsOver = true;
    }

    update();//paintEvent����


    update();

}
void Snake::keyPressEvent(QKeyEvent* event) {
    QKeyEvent* key = (QKeyEvent*)event;
    switch (key->key()) {
    case Qt::Key_Up:Direction = 1;
        break;
    case Qt::Key_Down:Direction = 2;   //2������
        break;
    case Qt::Key_Left:Direction = 3;   //3������
        break;
    case Qt::Key_Right:Direction = 4;   //4������
        break;
    default:;
    }
}
QRect Snake::CreateRect() {
    int x, y;
    x = qrand() % 25;//����С��25������
    y = qrand() % 25;
    QRect rect(20 + x * 10, 20 + y * 10, 10, 10);//ʳ��С����λ��
    return rect;
}
void Snake::IsEat() {
    if (SnakeHead == food) {//�����ͷ��ʳ���غϣ�˵���Ѿ�ײ��ʳ����
        SnakeHead = food;//�Ե�ʳ�ʳ��ͱ�Ϊ��ͷ
        nScore += 10;
        vSnakeRect.push_back(vSnakeRect.last());//�����һ���ڵ��ٴμӵ������������䳤
        food = CreateRect();//�Ե�ʳ���������һ��ʳ��
        speed -= 50;
        timer->stop();
        timer->start(speed);
    }

}
void Snake::IsHit() {
    for (int i = 1; i < vSnakeRect.size(); i++) {//��������
        if (SnakeHead == vSnakeRect[i]) {//��ͷ�������غ�
            sDisplay = "��Ϸ����";
            blsOver = true;
            update();
        }
    }
}
