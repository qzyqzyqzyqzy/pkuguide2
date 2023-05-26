#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H
#include<QAction>
#include<QMenu>
#include<QMenuBar>
#include<QStackedWidget>
#include<QToolButton>
#include<QLabel>
#include <QFont>
#include<QComboBox>
#include <QMainWindow>
#include"widget_visitorpage.h"
namespace Ui {
class MyMainWindow;
}

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();
    QAction *action_Back;
    QAction *action_Exit;
    QAction *action_Help;
    QWidget *Widget_central;
    QStackedWidget *StackedWidget_mainfunctionpage;
    QWidget *Widget_startpage;
    QWidget *Widget_guidepage;
    QToolButton *button_guide;
    QToolButton *button_visitor;
    QLabel *label_startpageimg;
    QComboBox *box_start;
    QComboBox *box_end;
    QToolButton *button_startguide;
    widget_visitorpage *Widget_visitorpage;
private:
    Ui::MyMainWindow *ui;
private slots:
    void actionBack();
    void actionExit();
    void actionHelp();
    void visitorskip();
    void guideskip();
};

#endif // MYMAINWINDOW_H
