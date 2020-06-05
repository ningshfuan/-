#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <QPushButton>
#include <QDebug>
#include "mybutton.h"
#include "mywindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setFixedSize(800,600);
    ui->setupUi(this);
    MyButton *btn = new MyButton(":/start.png");
    btn->setParent(this);
    btn->move(40,40);
    MyWindow *scene = new MyWindow;
    connect(btn,&QPushButton::clicked,this,[=](){
        this->close();
        scene->show();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*){
    QPainter painter(this);
    QPixmap pixmap(":/face.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
}
