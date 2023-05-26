#include "widget_visitorpage.h"
#include"movelabel.h"
#include"location_direction.h"
#include<QMap>
#include<QDebug>
#include<QStringList>
extern QString path;
extern QMap<location_direction,int> map;
extern location_direction nowlocation_direction;
widget_visitorpage::widget_visitorpage(QWidget *parent) : QWidget(parent)
{
     StackedWidget_visitorview=new QStackedWidget(this);
     StackedWidget_visitorview->setGeometry(0,0,1618,983);
     StackedWidget_visitorview->setObjectName(QStringLiteral("StackedWidget_visitor"));
     QWidget *page0=new QWidget();
     StackedWidget_visitorview->addWidget(page0);
     button_left = new QToolButton(this);
     button_left->setText(tr("Left"));
     button_left->setObjectName(QStringLiteral("button_left"));
     button_left->setGeometry(QRect(200, 750, 300, 150));
     button_left->setStyleSheet(QStringLiteral(""));
     button_ahead = new QToolButton(this);
     button_ahead->setText(tr("Ahead"));
     button_ahead->setObjectName(QStringLiteral("button_ahead"));
     button_ahead->setGeometry(QRect(500, 750, 300, 150));
     button_right = new QToolButton(this);
     button_right->setText(tr("Right"));
     button_right->setObjectName(QStringLiteral("button_right"));
     button_right->setGeometry(QRect(800, 750, 300, 150));
     QFont font;//设置字体
     font.setFamily(QStringLiteral("Kristen ITC"));
     font.setPointSize(28);
     font.setBold(true);
     font.setWeight(75);
     button_ahead->setFont(font);
     button_left->setFont(font);
     button_right->setFont(font);
     QWidget *page1=new QWidget(StackedWidget_visitorview);
     StackedWidget_visitorview->addWidget(page1);
     QWidget *page2=new QWidget(StackedWidget_visitorview);
     StackedWidget_visitorview->addWidget(page2);
     QWidget *page3=new QWidget(StackedWidget_visitorview);
     StackedWidget_visitorview->addWidget(page3);
     QWidget *page4=new QWidget(StackedWidget_visitorview);
     StackedWidget_visitorview->addWidget(page4);
     QWidget *page5=new QWidget(StackedWidget_visitorview);
     StackedWidget_visitorview->addWidget(page5);
     QWidget *page6=new QWidget(StackedWidget_visitorview);
     StackedWidget_visitorview->addWidget(page6);
     QLabel *img0_0_0_1=new QLabel(page0);
     img0_0_0_1->setObjectName(QStringLiteral("img0_0_0_1"));
     img0_0_0_1->setGeometry(QRect(0, 0, 1618, 983));
     img0_0_0_1->setPixmap(QPixmap(QString(path+"ahead.BMP")));
     img0_0_0_1->setScaledContents(true);

     QLabel *img0_0_1_0=new QLabel(page1);

     QLabel *img0_0_i1_0=new QLabel(page2);
     img0_0_i1_0->setObjectName(QStringLiteral("img0_0_i1_0"));
     img0_0_i1_0->setGeometry(QRect(0, 0, 1618, 983));
     img0_0_i1_0->setPixmap(QPixmap(QString(path+"/left.BMP")));
     img0_0_i1_0->setScaledContents(true);
     QLabel *img0_1_0_1=new QLabel(page3);
     connect(button_left,SIGNAL(clicked(bool)),this,SLOT(Left()));
}
void widget_visitorpage::Left()
{
    int xx,yy;
    xx=-nowlocation_direction.dy;
    yy=nowlocation_direction.dx;
    nowlocation_direction.dx=xx;
    nowlocation_direction.dy=yy;
    QStringList imageFiles;
    imageFiles <<path+"ahead.BMP"<<path+"2.BMP" << path+"1.BMP"<<path+"left.BMP";
    movelabel *l=new movelabel(imageFiles,nowlocation_direction, this);
    connect(l,&movelabel::movefinished,this,&widget_visitorpage::shiftaftermove);
    l->setAttribute(Qt::WA_DeleteOnClose);
    l->setWindowFlags(Qt::WindowStaysOnTopHint);
    l->show();




}
void widget_visitorpage::shiftaftermove(const location_direction &b)
{
    this->StackedWidget_visitorview->setCurrentIndex(map[b]);
}

void widget_visitorpage::Right()
{
    int xx,yy;
    xx=nowlocation_direction.dy;
    yy=-nowlocation_direction.dx;
    qDebug()<<nowlocation_direction.dx<<nowlocation_direction.dy<<"rrrrr"<<xx<<yy;
    nowlocation_direction.dx=xx;
    nowlocation_direction.dy=yy;
    this->StackedWidget_visitorview->setCurrentIndex(map[nowlocation_direction]);
}
void widget_visitorpage::Ahead()
{

}
