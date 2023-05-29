#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QPalette palette;
    palette.setColor(QPalette::Background, Qt::gray);
    w.setPalette(palette);
    w.show();
    return a.exec();
}
