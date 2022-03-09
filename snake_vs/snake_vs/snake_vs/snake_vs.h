#ifndef SNAKE_H
#define SNAKE_H
#include <QMainWindow>
#include<qpainter.h>
#include<QVector>
#include<qstring.h>

namespace Ui { class SnakeClass {}; };
QT_END_NAMESPACE

class Snake : public QMainWindow
{
    Q_OBJECT

public:
    Snake(QWidget* parent = nullptr);
    ~Snake();
    void paintEvent(QPaintEvent* event);
    void InitSnake();
    void keyPressEvent(QKeyEvent* event);
    void IsEat();
    QRect CreateRect();
    void IsHit();
private slots:             //定义为槽函数
    void Snake_Update();

private:
    Ui::SnakeClass* ui;
    // QRect vSnakeRect;
    QTimer* timer;
    int Direction;
    bool blsrun;
    QVector<QRect> vSnakeRect;
    QRect SnakeHead;//
    bool blsOver;
    QString sDisplay;
    QRect food;//食物
    int nScore;
    QString scoreLabel;
    int speed;
};
#endif // SNAKE_H
