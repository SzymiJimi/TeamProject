#include "client.h"

Client::Client(QString name, QString surname, QString pesel, QString nip, QString street, QString houseNr, QString postalCode, QString city )
{
    this->name=name;
    this->surname=surname;
    this->pesel=pesel;
    this->nip=nip;
    this->street=street;
    this->houseNr=houseNr;
    this->postalCode=postalCode;
    this->city=city;
}
