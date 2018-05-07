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

void AddClient::setFormForEdit(Client client)
{
    QWidget::setWindowTitle("Edytuj Klienta");
    ui->label_9->setText("Wprowadź dane do edycji");
    ui->name->setText(client.getName());
    ui->surname->setText(client.getSurname());
    ui->pesel->setText(client.getPesel());
    ui->nip->setText(client.getNip());
    ui->street->setText(client.getStreet());
    ui->houseNr->setText(client.getHouseNr());
    ui->postalCode->setText(client.getPostalCode());
    ui->city->setText(client.getCity());
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

//void AddClient::on_buttonBox_clicked(QAbstractButton *button)
//{

//}
