#ifndef WIDGET_CLIENT_H
#define WIDGET_CLIENT_H

#include <QWidget>
#include<QTcpSocket>

namespace Ui {
class Widget_client;
}

class Widget_client : public QWidget
{
    Q_OBJECT

public:
    explicit Widget_client(QWidget *parent = nullptr);
    ~Widget_client();

private slots:
    void on_btn_connect_clicked();

    void on_btn_send_clicked();

    void on_btn_close_clicked();

private:
    Ui::Widget_client *ui;
    QTcpSocket *tcpClient;
};

#endif // WIDGET_CLIENT_H
