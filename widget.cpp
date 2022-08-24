#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    /*if (diff>=500){
        ui->pbCoffee->setEnabled(false);
        ui->pbMilk->setEnabled(false);
        ui->pbMango->setEnabled(false);
    }*/
    ui->pbCoffee->setEnabled(false);
    ui->pbMango->setEnabled(false);
    ui->pbMilk->setEnabled(false);
    //ui->pbCoffee(500)->isEnabled(true);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);
    if(money >= 500){
        ui->pbCoffee->setEnabled(true);
        ui->pbMango->setEnabled(true);
        ui->pbMilk->setEnabled(true);
    }
    else if(money >= 300){
        ui->pbMango->setEnabled(true);
        ui->pbCoffee->setEnabled(true);
    }
    else if(money >= 100){
        ui->pbCoffee->setEnabled(true);
    }
    if(money < 100){
        ui->pbCoffee->setEnabled(false);
        ui->pbMango->setEnabled(false);
        ui->pbMilk->setEnabled(false);
    }
    else if(money < 300){
        ui->pbMango->setEnabled(false);
        ui->pbMilk->setEnabled(false);
    }
    else if(money < 500){
        ui->pbMilk->setEnabled(false);
    }

}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbMango_clicked()
{
    changeMoney(-300);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-500);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox msgBox;
    QString message;

    ch500 = (money / 100) / 5;
    ch100 = (money / 100) % 5;
    ch50 = (money % 100) / 50;
    ch10 = ((money % 100) % 50)/10;

    message = QString(" 500 : %1 \n 100 : %2\n 50 : %3\n 10 : %4").arg(ch500).arg(ch100).arg(ch50).arg(ch10);

    msgBox.information(this, "!!change!!", message);
    changeMoney(money=0);
}
