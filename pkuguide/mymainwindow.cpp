#include "mymainwindow.h"
#include "ui_mymainwindow.h"
QString path="C:/Users/86139/Desktop/pkuguide3/img/";
MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(tr("PKU GUIDE"));
    this->setMinimumSize(QSize(1618, 1000));
    this->setMaximumSize(QSize(1618, 1000));
    action_Back=new QAction(tr("Back"),this);
    action_Exit=new QAction(tr("Exit"),this);
    action_Help=new QAction(tr("Help"),this);
    action_Back->setObjectName(QStringLiteral("action_Back"));
    action_Exit->setObjectName(QStringLiteral("action_Exit"));
    action_Help->setObjectName(QStringLiteral("action_Help"));
    QMenu *menu=new QMenu(tr("Menu"),this);
    QMenuBar *menuBar = new QMenuBar(this);
    this->setMenuBar(menuBar);
    menuBar->setStyleSheet("QMenuBar::icon { visibility: hidden; }");
    menuBar->addMenu(menu);
    menu->setTearOffEnabled(false);
    menu->setStyleSheet("QMenu::icon { width: 0px; }");
    menu->addAction(action_Back);
    menu->addAction(action_Exit);
    menu->addAction(action_Help);
    connect(action_Back,SIGNAL(triggered(bool)),this,SLOT(actionBack()));
    connect(action_Exit,SIGNAL(triggered(bool)),this,SLOT(actionExit()));
    connect(action_Help,SIGNAL(triggered(bool)),this,SLOT(actionHelp()));
    StackedWidget_mainfunctionpage=new QStackedWidget(ui->centralWidget);
    this->setCentralWidget(ui->centralWidget);
    Widget_startpage=new QWidget();
    Widget_startpage->setGeometry(QRect(0,0,1618,983));
    StackedWidget_mainfunctionpage->addWidget(Widget_startpage);
    StackedWidget_mainfunctionpage->setObjectName(QStringLiteral("StackedWidget_mainfunctionpage"));
    StackedWidget_mainfunctionpage->setGeometry(QRect(0, 0, 1618, 983));
    StackedWidget_mainfunctionpage->setMaximumSize(1618,983);
    StackedWidget_mainfunctionpage->setMinimumSize(1618,983);
    button_guide=new QToolButton(Widget_startpage) ;
    connect(button_guide,SIGNAL(clicked(bool)),this,SLOT(guideskip()));
    button_visitor=new QToolButton(Widget_startpage);
    connect(button_visitor,SIGNAL(clicked(bool)),this,SLOT(visitorskip()));
    label_startpageimg=new QLabel(Widget_startpage);
    button_guide->raise();
    button_visitor->raise();
    Widget_startpage->setObjectName(QStringLiteral("Widget_startpage"));
    button_guide->setObjectName(QStringLiteral("button_guide"));
    button_guide->setText(tr("Guide Mode"));
    button_guide->setGeometry(QRect(370, 800, 400, 200));
    QFont font;//设置字体
    font.setFamily(QStringLiteral("Kristen ITC"));
    font.setPointSize(28);
    font.setBold(true);
    font.setWeight(75);
    button_guide->setFont(font);
    button_guide->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 0)"));//透明背景
    button_visitor->setObjectName(QStringLiteral("button_visitor"));
    button_visitor->setText(tr("Visitor Mode"));
    button_visitor->setGeometry(QRect(850, 800, 400, 200));
    button_visitor->setFont(font);
    button_visitor->setStyleSheet(QStringLiteral("background-color: rbga(0,0,0,0);"));
    label_startpageimg->setObjectName(QStringLiteral("label_startpageimg"));
    label_startpageimg->setGeometry(QRect(0, 0, 1618, 983));
    label_startpageimg->setStyleSheet(QStringLiteral("background-color: transparent; border: 1px solid black;"));
    label_startpageimg->setPixmap(QPixmap(QString(path+"westgate.jpg")));
    label_startpageimg->setScaledContents(true);
    Widget_guidepage=new QWidget();
    StackedWidget_mainfunctionpage->addWidget(Widget_guidepage);
    Widget_guidepage->setObjectName(QStringLiteral("Widget_guidepage"));
    box_start = new QComboBox(Widget_guidepage);
    box_start->setObjectName(QStringLiteral("box_start"));
    box_start->setGeometry(QRect(300, 100, 400, 40));
    box_start->setStyleSheet(QStringLiteral("font: 75 16pt \"Kristen ITC\";"));
    box_end = new QComboBox(Widget_guidepage);
    box_end->setObjectName(QStringLiteral("box_end"));
    box_end->setGeometry(QRect(300, 200, 400, 40));
    box_end->setStyleSheet(QStringLiteral("font: 75 16pt \"Kristen ITC\";"));
    box_start->clear();
    box_start->insertItems(0, QStringList()
             << QApplication::translate("MyMainWindow", "teachingbuilding", Q_NULLPTR)
             << QApplication::translate("MyMainWindow", "canteen", Q_NULLPTR)
            );
    box_end->clear();
    box_end->insertItems(0, QStringList()
             << QApplication::translate("MyMainWindow", "teachingbuilding", Q_NULLPTR)
             << QApplication::translate("MyMainWindow", "canteen", Q_NULLPTR)
            );
    QLabel *label_startpoint = new QLabel(Widget_guidepage);
    label_startpoint->setText(tr("Start from"));
    label_startpoint->setObjectName(QStringLiteral("label_startpoint"));
    label_startpoint->setGeometry(QRect(80, 100, 200, 40));
    label_startpoint->setStyleSheet(QStringLiteral("font: 75 16pt \"Kristen ITC\";"));
    label_startpoint->setScaledContents(true);
    QLabel *label_endpoint = new QLabel(Widget_guidepage);
    label_endpoint->setText(tr("End   at"));
    label_endpoint->setObjectName(QStringLiteral("endpoint"));
    label_endpoint->setGeometry(QRect(80, 200, 200, 40));
    label_endpoint->setStyleSheet(QStringLiteral("font: 75 16pt \"Kristen ITC\";"));
    label_endpoint->setTextFormat(Qt::AutoText);
    label_endpoint->setScaledContents(true);
    QLabel *label_guidepageimg = new QLabel(Widget_guidepage);
    label_guidepageimg->lower();
    label_guidepageimg->setObjectName(QStringLiteral("guidepageimg"));
    label_guidepageimg->setGeometry(QRect(0, 0, 1618, 1800));
    label_guidepageimg->setPixmap(QPixmap((path+"guidepageimg.jpg")));
    label_guidepageimg->setScaledContents(true);
    button_startguide = new QToolButton(Widget_guidepage);
    button_startguide->setObjectName(QStringLiteral("startguide"));
    button_startguide->setText(tr("Start"));
    button_startguide->setGeometry(QRect(700, 80, 400, 200));
    button_startguide->setStyleSheet(QStringLiteral("background-color: rgba(0, 0, 0, 0);font: 75 16pt \"Kristen ITC\";"));
    Widget_visitorpage=new widget_visitorpage();
    StackedWidget_mainfunctionpage->addWidget(Widget_visitorpage);

}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}
void MyMainWindow::actionExit()
{
    this->close();
}
void MyMainWindow::actionBack()
{
    this->StackedWidget_mainfunctionpage->setCurrentIndex(0);

}
void MyMainWindow::actionHelp()
{

}
void MyMainWindow::visitorskip()
{
    this->StackedWidget_mainfunctionpage->setCurrentIndex(2);
}
void MyMainWindow::guideskip()
{
    this->StackedWidget_mainfunctionpage->setCurrentIndex(1);
}
