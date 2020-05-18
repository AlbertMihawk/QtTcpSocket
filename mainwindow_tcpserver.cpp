#include "mainwindow_tcpserver.h"
#include "ui_mainwindow_tcpserver.h"


MainWindow_TcpServer::MainWindow_TcpServer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow_TcpServer)
{
    ui->setupUi(this);
    int port = 23333;
    QString str = "server(port：%1 )";
    str = str.arg(port);
    this->setWindowTitle(str);

    tcpServer = NULL;
    tcpSocket = NULL;
    ui->btn_send->setDisabled(1);

    //指定父对象，自动回收控件
    tcpServer = new QTcpServer(this);
    //    QHostAddress *host = new QHostAddress();
    //    host->setAddress("127.0.0.1");
    tcpServer->listen(QHostAddress::Any,port);

    connect(tcpServer,&QTcpServer::newConnection,
            [=]()
    {
        //取出建立好连接的套接字
        tcpSocket = tcpServer->nextPendingConnection();
        //获取对方的IP和端口
        QString ip = tcpSocket->peerAddress().toString();
        quint16 port = tcpSocket->peerPort();

        ui->tb_read->append(QString("[ %1 / %2 ], successful connection!").arg(ip).arg(port));
        ui->btn_send->setDisabled(0);

        connect(tcpSocket,&QTcpSocket::readyRead,
                [=]()
        {
            //从通信套接中取出内容
            QByteArray array = tcpSocket->readAll();
            ui->tb_read->append(QString(array));
        });

    });


    connect(ui->btn_send,&QPushButton::clicked,this,&MainWindow_TcpServer::serverSend);


    //    connect(ui->btn_close,&QPushButton::clicked,this,&MainWindow_TcpServer::close);


}

MainWindow_TcpServer::~MainWindow_TcpServer()
{
    delete ui;
}

void MainWindow_TcpServer::serverSend()
{
    if(NULL==tcpServer)return;
    //获取编辑区内容
    QString str = this->ui->te_write->toPlainText();
    //QString to char *
    tcpSocket->write(str.toUtf8().data());


}


void MainWindow_TcpServer::on_btn_close_clicked()
{
    if(NULL!=tcpSocket)
    {
        tcpSocket->disconnectFromHost();
        tcpSocket->close();
    }

    if(NULL==tcpServer)
    {
        tcpServer->close();
    }
//    this->close();
}
