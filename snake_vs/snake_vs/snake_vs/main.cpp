#include "snake_vs.h"
#include <QTextCodec>

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Snake w;
    w.show();

   
    return a.exec();
   

}

