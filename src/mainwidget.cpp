#include "../include/roskcci/mainwidget.h"

#include "ui_mainwidget.h"

#include <QDebug>
#include <typeinfo>
#include <iostream>
MainWidget::MainWidget(int argc, char **argv, QWidget *parent)
    : QWidget(parent), ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    setWindowTitle("KCCISTC-AIOT ROS");

    ui->tabWidget->setCurrentIndex(0);

    pTab1TTBControl = new Tab1TTBControl(argc, argv, ui->pTab1);
    ui->pTab1->setLayout(pTab1TTBControl->layout());

    pTab2SocketClient = new Tab2SocketClient(argc, argv, ui->pTab2);
    ui->pTab2->setLayout(pTab2SocketClient->layout());

    connect(pTab2SocketClient,SIGNAL(goGoalSig(double, double, double, double)),pTab1TTBControl,SLOT(goal_PubSlot(double, double, double, double)));
}

MainWidget::~MainWidget()
{
    delete ui;
}
