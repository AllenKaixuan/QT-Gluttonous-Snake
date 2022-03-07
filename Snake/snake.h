#ifndef SNAKE_H
#define SNAKE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Snake; }
QT_END_NAMESPACE

class Snake : public QMainWindow
{
    Q_OBJECT

public:
    Snake(QWidget *parent = nullptr);
    ~Snake();
    void paintEvent(QPaintEvent *event);
    void InitSnake();
    void keyPressEvent(QKeyEvent *event);

private slots:             //定义为槽函数
    void Snake_update();

private:
    Ui::Snake *ui;
    QRect vSnakeRect;
    QTimer *timer;
    int Direction;


};
#endif // SNAKE_H
