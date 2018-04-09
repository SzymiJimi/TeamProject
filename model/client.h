#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>

class Client
{
public:
    Client();
    Client(QString name, QString surname, QString pesel, QString nip, QString street, QString houseNr, QString postalCode, QString city);
    QString name;
    QString surname;
    QString pesel;
    QString nip;
    QString street;
    QString houseNr;
    QString postalCode;
    QString city;
};

#endif // CLIENT_H
