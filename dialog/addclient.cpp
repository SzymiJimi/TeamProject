#include "addclient.h"
#include "ui_addclient.h"
#include "./model/client.h"
#include "mainwindow.h"
#include <QDebug>

AddClient::AddClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClient)
{
    ui->setupUi(this);
}

AddClient::~AddClient()
{
    delete ui;
}

Client* AddClient::getValues(){
    QString name= ui->name->text();
    QString surname=ui->surname->text();
    QString pesel= ui->pesel->text();
    QString nip= ui->nip->text();
    QString street= ui->street->text();
    QString houseNr= ui->houseNr->text();
    QString postalCode= ui->postalCode->text();
    QString city= ui->city->text();
    return new Client(0, name,surname,pesel,nip, street,houseNr, postalCode, city);
}

void AddClient::on_buttonBox_clicked(QAbstractButton *button)
{

}
