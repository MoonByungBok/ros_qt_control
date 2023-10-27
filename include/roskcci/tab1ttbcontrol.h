#ifndef __TAB1TTBCONTROL_H
#define __TAB1TTBCONTROL_H

#include "rosnode.h"
#include <QWidget>
#include <QButtonGroup>
#include <QPushButton>
#include <iostream>
#include <array>


namespace Ui {
class Tab1TTBControl;
}

class Tab1TTBControl : public QWidget
{
    Q_OBJECT

public:
    explicit Tab1TTBControl(int argc, char **argv, QWidget *parent = nullptr);
    ~Tab1TTBControl();

private:
    Ui::Tab1TTBControl *ui;
    RosNode *prosNode;
    QButtonGroup *bg;
    QWidget *widget;


private slots:
    void goal_Pub();
    void goal_PubSlot(double, double, double, double);
    void goal_Pub_Front();
    void goal_Pub_Living();
    void goal_Pub_Myroom();
    void goal_Pub_Kitchen();
    void set_Pub();
    void DebugConsole(QString);
    void slotLdsReceive(float *);

};

#endif // TAB1DEVCONTROL_H
