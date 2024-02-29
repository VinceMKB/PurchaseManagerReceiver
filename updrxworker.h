
#ifndef UPDRXWORKER_H
#define UPDRXWORKER_H


#include <QObject>
#include <QUdpSocket>


class UPDRxWorker : public QObject
{
    Q_OBJECT
public:
    explicit UPDRxWorker(QObject *parent = nullptr);

private:
    QUdpSocket upd_socket;

public slots:
    void readingpending_Datagrams();

signals:
    void data_recieved(const QByteArray &data);
};

#endif // UPDRXWORKER_H
