
#include "mainwindow.h"
#include "updrxworker.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    UPDRxWorker worker;
    QObject::connect(&worker, &UPDRxWorker::data_recieved, &w, &MainWindow::recieve_data);

    w.show();
    return a.exec();
}
