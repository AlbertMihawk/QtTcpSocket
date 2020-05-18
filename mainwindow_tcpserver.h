#ifndef MAINWINDOW_TCPSERVER_H
#define MAINWINDOW_TCPSERVER_H

#include <QMainWindow>
#include <QTcpServer> //监听套接字
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow_TcpServer; }
QT_END_NAMESPACE

class MainWindow_TcpServer : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow_TcpServer(QWidget *parent = nullptr);
    ~MainWindow_TcpServer();

private:
    Ui::MainWindow_TcpServer *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;

private slots:
    void serverSend();
    void on_btn_close_clicked();
};
#endif // MAINWINDOW_TCPSERVER_H
