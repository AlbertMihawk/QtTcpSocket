#include "mainwindow_tcpserver.h"
#include "widget_client.h"
#include <QApplication>
#include <QDebug>
#define cout qDebug() << "[" << __FILE__ << ":" << "__LINE__" << "]"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow_TcpServer s;
    s.move(150,230);
    s.show();
    cout << s.pos().x() << "/" << s.pos().y();
    Widget_client c;
    c.move(800,230);
    c.show();

    return a.exec();
}
