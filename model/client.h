#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <list>
#include <QDebug>

class Client
{
private:
    int id;
    QString name;
    QString surname;
    QString pesel;
    QString nip;
    QString street;
    QString houseNr;
    QString postalCode;
    QString city;

public:
    Client();
    Client(int id, QString name, QString surname, QString pesel, QString nip, QString street, QString houseNr, QString postalCode, QString city);
    void setId(int id);
    void setName(QString name);
    void setSurname(QString surname);
    void setPesel(QString pesel);
    void setNip(QString nip);
    void setStreet(QString street);
    void setHouseNr(QString houseNr);
    void setPostalCode(QString postalCode);
    void setCity(QString city);

    int getId();
    QString getName();
    QString getSurname();
    QString getPesel();
    QString getNip();
    QString getStreet();
    QString getHouseNr();
    QString getPostalCode();
    QString getCity();

    std::list<Client> loadClientsFromFile();
    void saveClientsToFile(std::list<Client> clients);
    Client findClientById(int clientId, std::list<Client> clients);
    static bool deleteClientById(int clientId, std::list<Client> &clients);
    static QString getInfoAboutClientToInvoice(int clientId, std::list<Client> clients);
    bool operator <(const Client &other);

};

#endif // CLIENT_H
