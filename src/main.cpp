#include <QApplication>
#include "../include/roskcci/mainwidget.h"

/*****************************************************************************
** Main
*****************************************************************************/

int main(int argc, char **argv) {
  QApplication a(argc, argv);
  MainWidget w(argc, argv);
  w.show();
  return a.exec();
}
