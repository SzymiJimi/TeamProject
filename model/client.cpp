#include "client.h"

Client::Client(){

}

Client::Client(int id, QString name, QString surname, QString pesel, QString nip, QString street, QString houseNr, QString postalCode, QString city )
{
    this->id=id;
    this->name=name;
    this->surname=surname;
    this->pesel=pesel;
    this->nip=nip;
    this->street=street;
    this->houseNr=houseNr;
    this->postalCode=postalCode;
    this->city=city;
}

void Client::setId(int id){
    this->id=id;
}

void Client::setName(QString name){
    this->name=name;
}

void Client::setSurname(QString surname){
    this->surname=surname;
}

void Client::setPesel(QString pesel){
    this->pesel=pesel;
}

void Client::setNip(QString nip){
    this->nip=nip;
}

void Client::setStreet(QString street){
    this->street=street;
}

void Client::setHouseNr(QString houseNr){
    this->houseNr=houseNr;
}

void Client::setPostalCode(QString postalCode){
    this->postalCode=postalCode;
}

void Client::setCity(QString city){
    this->city=city;
}


int Client::getId(){
    return this->id;
}

QString Client::getName(){
    return this->name;
}
QString Client::getSurname(){
    return this->surname;
}
QString Client::getPesel(){
    return this->pesel;
}
QString Client::getNip(){
    return this->nip;
}
QString Client::getStreet(){
    return this->street;
}
QString Client::getHouseNr(){
    return this->houseNr;
}
QString Client::getPostalCode(){
    return this->postalCode;
}
QString Client::getCity(){
    return this->city;
}
int clientIdTmp;

bool clientIdIsEqual(Client client){
    return ((client.getId()==clientIdTmp));
}

Client Client::findClientById(int clientId, std::list<Client> clients)
{
    clientIdTmp=clientId;
    std::list<Client>::iterator findIter = std::find_if(clients.begin(), clients.end(), clientIdIsEqual);
    qDebug()<<"Znaleziony produkt w findProductById: "<<(&findIter);
    if(findIter!=clients.end()){

        Client &client = *findIter;
        return client;
    }else{
        Client cli;
        cli.setId(-1);
        return cli;
    }
}


bool Client::deleteClientById(int clientId, std::list<Client> &clients){
    clientIdTmp=clientId;
    std::list<Client>::iterator findIter = std::find_if(clients.begin(), clients.end(), clientIdIsEqual);
    qDebug()<<"Znaleziony produkt w findProductById: "<<(&findIter);
    if(findIter!=clients.end()){

        clients.erase(findIter);
        return true;
    }else{
        return false;
    }
}

QString Client::getInfoAboutClientToInvoice(int idClient, std::list<Client> clients)
{
    Client client = client.findClientById(idClient, clients);
    QString information = client.getName() + " " +client.getSurname() + "<br>"
            +client.getCity() + ", ul. " + client.getStreet() +" "+ client.getHouseNr()+ "<br>"
            +"NIP: "+client.getNip();
    return information;
}

bool Client::operator <(const Client &other)
{
    return id  < other.id;
}


