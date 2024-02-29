
#include "updrxworker.h"

UPDRxWorker::UPDRxWorker(QObject *parent) : QObject(parent)
{
    upd_socket.bind(QHostAddress::AnyIPv4, 45454);

    connect(&upd_socket, &QUdpSocket::readyRead, this, &UPDRxWorker::readingpending_Datagrams);
}

void UPDRxWorker::readingpending_Datagrams()
{
    while (upd_socket.hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(upd_socket.pendingDatagramSize());

        upd_socket.readDatagram(datagram.data(), datagram.size());

        emit data_recieved(datagram);
    }
}

