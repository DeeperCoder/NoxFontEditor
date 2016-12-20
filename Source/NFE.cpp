#include "nfe_mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    NFE_MainWindow w;
    w.show();

    return a.exec();
}
