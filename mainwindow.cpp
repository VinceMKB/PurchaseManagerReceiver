
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStringListModel>
#include <QDomDocument>
#include <QDomElement>
#include <QDomNode>
#include <QDomNodeList>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initialize the QStringListModel
    mw_listmodel = new QStringListModel(this);

    //Attach the model to the listviewXML
    ui->listviewXML->setModel(mw_listmodel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::recieve_data(const QByteArray &data)
{
    // Verify if the received data can be parsed as XML
    QDomDocument doc;
    if (!doc.setContent(data)) {
        // Handle error and return
        return;
    }

    // Convert the QByteArray to QString
    QString xmlString = QString::fromUtf8(data);

    // Create a QStringList containing the XML string
    QStringList xmlDataList;
    xmlDataList << xmlString;

    // Update the list model
    mw_listmodel->setStringList(xmlDataList);
}


