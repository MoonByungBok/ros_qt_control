#ifndef TURTLEBOTCONTROL_H
#define TURTLEBOTCONTROL_H

#include "rosnode.h"
#include <QWidget>
#include <QButtonGroup>
#include <QPushButton>
#include <iostream>

namespace Ui {
class TurtlebotControl;
}

class TurtlebotControl : public QWidget
{
    Q_OBJECT

public:
    explicit TurtlebotControl(int argc, char **argv, QWidget *parent = nullptr);
    ~TurtlebotControl();

private:
    Ui::TurtlebotControl *ui;
    RosNode *prosNode;
    QWidget *widget;
};

#endif // TURTLEBOTCONTROL_H
