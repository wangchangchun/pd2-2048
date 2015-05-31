#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"ui_play.h"

namespace Ui {
class widget;
}

class widget : public QWidget
{
    Q_OBJECT

public:
    explicit widget(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent* event);
    void up();
    void down();
    void right();
    void left();
    int box[16];
    int check[4];
    void paint();
    void start();
    void generate();
    int max;
    int last[16];
    bool change;
    bool ge;
    int point;
    int round;

    ~widget();

private slots:
    //void on_start_clicked();

    void on_pushButton_clicked();

    void on_start_clicked();

private:
    //Ui::widget *wui;
    Ui::Form *gui;

};

#endif // WIDGET_H
