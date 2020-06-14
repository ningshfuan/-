#include "mywindow.h"
#include "mybutton.h"
MyWindow::MyWindow(QWidget *parent) : QMainWindow(parent)
{
    this->setFixedSize(800,600);
    MyButton *back_btn = new MyButton(":/start.jpeg");
    back_btn->setParent(this);
    back_btn->move(40,40);
    connect(back_btn,&MyButton::clicked,this,[=](){
        emit chooseBack();
    });
}
