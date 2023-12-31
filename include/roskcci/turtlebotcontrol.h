#ifndef TURTLEBOTCONTROL_H
#define TURTLEBOTCONTROL_H

#include "rosnode.h"
#include <QWidget>
#include <QPushButton>
#include <iostream>
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <QKeyEvent>

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
    ros::NodeHandle nh_;
    ros::Publisher cmd_vel_pub_;
    bool isFB = true;
    void move_where(int);
protected:
    void keyPressEvent(QKeyEvent *event) override;

signals:
    void KeyControlfront();
    void KeyControlback();
    void KeyControlleft();
    void KeyControlright();

private slots:
    void trackingMod();
    void move_Pub_Front();
    void move_Pub_Left();
    void move_Pub_Right();
    void move_Pub_Back();
};

#endif // TURTLEBOTCONTROL_H
