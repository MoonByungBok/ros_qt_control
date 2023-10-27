#ifndef __QTMAIN_H
#define __QTMAIN_H

#include <QWidget>
#include "tab1ttbcontrol.h"
#include "tab2socketclient.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(int argc, char **argv, QWidget *parent = nullptr);
    ~MainWidget();
private:
    Ui::MainWidget* ui;
    Tab1TTBControl* pTab1TTBControl;
    Tab2SocketClient* pTab2SocketClient;

};
#endif // MAINWIDGET_H
