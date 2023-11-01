#include "../include/roskcci/turtlebotcontrol.h"
#include "ui_turtlebotcontrol.h"

TurtlebotControl::TurtlebotControl(int argc, char **argv, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TurtlebotControl)
{
    ui->setupUi(this);
    prosNode = new RosNode(argc, argv);
    prosNode->pLcamView = ui->pLcamView;
    prosNode->start();

    ros::init(argc, argv, "robot_driver");
    ros::NodeHandle nh;
    isFB = true;
    nh_ = nh;
    cmd_vel_pub_ = nh_.advertise<geometry_msgs::Twist>("/cmd_vel", 1);


    connect(ui->pPBtracking, SIGNAL(clicked()), this, SLOT(trackingMod()));
    connect(ui->pPBfront,SIGNAL(clicked()),this,SLOT(move_Pub_Front()));
    connect(ui->pPBback,SIGNAL(clicked()),this,SLOT(move_Pub_Back()));
    connect(ui->pPBleft,SIGNAL(clicked()),this,SLOT(move_Pub_Left()));
    connect(ui->pPBright,SIGNAL(clicked()),this,SLOT(move_Pub_Right()));

    connect(this,SIGNAL(KeyControlfront()),this,SLOT(move_Pub_Front()));
    connect(this,SIGNAL(KeyControlback()),this,SLOT(move_Pub_Back()));
    connect(this,SIGNAL(KeyControlleft()),this,SLOT(move_Pub_Left()));
    connect(this,SIGNAL(KeyControlright()),this,SLOT(move_Pub_Right()));

    connect(prosNode, SIGNAL(rosShutdown()), this, SLOT(close()));    
}

TurtlebotControl::~TurtlebotControl()
{
    delete ui;
}

void TurtlebotControl::trackingMod()
{
    setFocus(); // 포커스 설정
}

void TurtlebotControl::move_Pub_Front()
{
    isFB = true;
    move_where(1);
}
void TurtlebotControl::move_Pub_Left()
{
    move_where(2);
}
void TurtlebotControl::move_Pub_Right()
{
    move_where(3);
}
void TurtlebotControl::move_Pub_Back()
{
    isFB = false;
    move_where(4);
}

void TurtlebotControl::move_where(int strMove)
{
    geometry_msgs::Twist base_cmd;
    if(nh_.ok())
    {
        if(strMove!=1 && strMove!=2 && strMove!=3 && strMove!=4)
        {
             qDebug() << "unknown command: " << strMove << "\n";
        }
        base_cmd.linear.x = base_cmd.linear.y = base_cmd.angular.z = 0;
        if(strMove==1){
            base_cmd.linear.x = 0.25;
        }
        else if(strMove==2){
            base_cmd.angular.z = 0.75;
            if(isFB == true)
                base_cmd.linear.x = 0.25;
            else {
                base_cmd.linear.x = -0.25;
            }
            //base_cmd.linear.x = 0.25;
        }
        else if(strMove==3){
            base_cmd.angular.z = -0.75;
            if(isFB == true)
                base_cmd.linear.x = 0.25;
            else
                base_cmd.linear.x = -0.25;
            //base_cmd.linear.x = 0.25;
        }
        else if(strMove==4){
            base_cmd.linear.x = -0.25;
        }
    }
    cmd_vel_pub_.publish(base_cmd); // base_cmd를 퍼블리시
}

void TurtlebotControl::keyPressEvent(QKeyEvent *event)
{
    if(ui->pPBtracking->isChecked())
    {
        if(event->key() == Qt::Key_Up)
        {
            emit KeyControlfront();
        }
        else if(event->key() == Qt::Key_Down)
        {
            emit KeyControlback();
        }
        else if(event->key() == Qt::Key_Left)
        {
            emit KeyControlleft();
        }
        else if(event->key() == Qt::Key_Right)
        {
            emit KeyControlright();
        }
    }
}

