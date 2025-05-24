#include "tableview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Tableview w; //Double check, to ensure GUI Displays
    w.show();
    return a.exec();
}
