#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);





    //去掉窗口标题栏
    this->setWindowFlag(Qt::FramelessWindowHint);
    //禁止窗口改变尺寸大小
    this->setFixedSize(this->width(),this->height());

    ui->pushButton_closew->setStyleSheet("background-color:rgb(255,255,255,70);color: rgb(255, 255, 255);");

}

AboutDialog::~AboutDialog()
{
    delete ui;
}





void AboutDialog::paintEvent(QPaintEvent *event)
{
    QPainter qPainter(this);
    //调用drawpixmap（）函数进行绘制
    qPainter.drawPixmap(0,0,width(),height(),QPixmap(":/new/prefix1/images/Mbg.jpg"));
}
void AboutDialog::on_pushButton_closew_clicked()
{
    this->close();
}
