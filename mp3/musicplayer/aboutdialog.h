#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>






#include<QPainter>








namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = nullptr);
    ~AboutDialog();








public:
    //处理窗口重绘，实现背景图片
    void paintEvent(QPaintEvent *event);










private slots:
    void on_pushButton_closew_clicked();

private:
    Ui::AboutDialog *ui;
};

#endif // ABOUTDIALOG_H
