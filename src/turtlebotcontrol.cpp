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

    connect(prosNode, SIGNAL(rosShutdown()), this, SLOT(close()));
}

TurtlebotControl::~TurtlebotControl()
{
    delete ui;
}
