#include "widget_client.h"
#include "ui_widget_client.h"

Widget_client::Widget_client(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget_client)
{
    ui->setupUi(this);

     tcpClient = new QTcpSocket(this);
    connect(tcpClient,&QTcpSocket::connected,
            [=]()
    {
        ui->tb_read->setPlainText("successful!");

        connect(tcpClient,&QTcpSocket::readyRead,
                [=]()
        {
           QByteArray array = tcpClient->readAll();
           ui->tb_read->append(QString(array).toUtf8());
        });
    });


    //     connect(ui->btn_close,&QPushButton::clicked,this,&Widget_client::close);
}

Widget_client::~Widget_client()
{
    delete ui;
}

void Widget_client::on_btn_connect_clicked()
{
    this->setWindowTitle("Tcp Client");
    QString host = ui->le_host->text();
    int port = ui->le_port->text().toInt();

    tcpClient->connectToHost(host,port);
}

void Widget_client::on_btn_send_clicked()
{
    QString str = ui->te_write->toPlainText();
    tcpClient->write(str.toUtf8().data());
}

void Widget_client::on_btn_close_clicked()
{
    if(NULL!=tcpClient)
    {
        tcpClient->disconnectFromHost();
        tcpClient->close();
    }

}
