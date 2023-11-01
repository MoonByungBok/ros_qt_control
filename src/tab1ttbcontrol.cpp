#include "../include/roskcci/tab1ttbcontrol.h"
#include "ui_tab1ttbcontrol.h"

Tab1TTBControl::Tab1TTBControl(int argc, char **argv, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tab1TTBControl)
{
    ui->setupUi(this);
    prosNode = new RosNode(argc, argv);
    prosNode->pLcamView = ui->pLcamView;
    prosNode->start();

    connect(ui->pPButtonGO,SIGNAL(clicked()),this,SLOT(goal_Pub()));
    connect(ui->pPBFront,SIGNAL(clicked()),this,SLOT(goal_Pub_Front()));
    connect(ui->pPBLiving,SIGNAL(clicked()),this,SLOT(goal_Pub_Living()));
    connect(ui->pPBMyroom,SIGNAL(clicked()),this,SLOT(goal_Pub_Myroom()));
    connect(ui->pPBKitchen,SIGNAL(clicked()),this,SLOT(goal_Pub_Kitchen()));
    connect(prosNode,SIGNAL(sigLdsReceive(float *)),this,SLOT(slotLdsReceive(float *)));
    connect(prosNode, SIGNAL(rosShutdown()), this, SLOT(close()));
}

Tab1TTBControl::~Tab1TTBControl()
{
    delete ui;
}
void Tab1TTBControl::goal_Pub()
{
   prosNode->go_goal("map",ui->pDSBox_X->value(),ui->pDSBox_Y->value(),ui->pDSBox_Z->value(),ui->pDSBox_W->value());
}

void Tab1TTBControl::goal_PubSlot(double x, double y, double z, double w)
{
   prosNode->go_goal("map",x,y,z,w);
}
void Tab1TTBControl::goal_Pub_Front()
{
   prosNode->go_goal("map",0.83, 2.92, 0.0, 0.72);
}

void Tab1TTBControl::goal_Pub_Living()
{
   prosNode->go_goal("map",0.077, 0.19, 0.0, 0.79);
}

void Tab1TTBControl::goal_Pub_Myroom()
{
   prosNode->go_goal("map",4.96, 6.366, 0.0, 0.62);
}

void Tab1TTBControl::goal_Pub_Kitchen()
{
   prosNode->go_goal("map",7.78, 1.05, 0.0, 0.59);
}

void Tab1TTBControl::set_Pub()
{
   prosNode->set_goal("map",0.83, 2.92, 0.0, 0.72);
}

void Tab1TTBControl::DebugConsole(QString)
{

}
void Tab1TTBControl::slotLdsReceive(float * pscanData)
{
//    qDebug() << "pscanData[0] : " << pscanData[0];
    ui->lcdNumber_1->display(pscanData[0]);
    ui->lcdNumber_2->display(pscanData[1]);
    ui->lcdNumber_3->display(pscanData[2]);
    ui->lcdNumber_4->display(pscanData[3]);
}
