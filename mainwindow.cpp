#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "dialog/addclient.h"
#include "model/client.h"
#include <QDebug>
#include "services/savefile.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    addClientsFromFileToTable();
}

MainWindow::~MainWindow()
{
    SaveFile save;
    save.saveClientsToFile(this->clients);
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_label_linkActivated(const QString &link)
{

}

void MainWindow::on_pushButton_2_clicked()
{
        ui->tabWidget->setCurrentIndex(2);

}

void MainWindow::on_showClientsButton_clicked()
{
    ui->tabWidget->setCurrentIndex(4);
}


void MainWindow::on_addClientButton_clicked()
{
        AddClient addClient;
        addClient.setModal(true);
        if(addClient.exec()==QDialog::Accepted){
            qDebug()<<"Nacisnoles ok!";
            Client* client = addClient.getValues();
            addClientToTable(client);

        }
}

void MainWindow::addClientsFromFileToTable(){
//    ui->ClientsTable->insertRow(ui->ClientsTable->rowCount());
    SaveFile saveFile;

    this->clients= saveFile.loadClientsFromFile();
    list<Client>::iterator i;
    qDebug()<<"Jestem w addClientsFromFileToTable, rozmiar listy: "<<this->clients.size();
     QString idString;
    for(i=clients.begin(); i!=clients.end();i++){
        qDebug()<<"W petli";
        idString = QString::number(i->getId());
        ui->ClientsTable->insertRow(ui->ClientsTable->rowCount());
        ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 0, new QTableWidgetItem(idString));
        ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 1, new QTableWidgetItem(i->getName()));
        ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 2, new QTableWidgetItem(i->getSurname()));
        ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 3, new QTableWidgetItem(i->getPesel()));
        ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 4, new QTableWidgetItem(i->getNip()));
        ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 5, new QTableWidgetItem(i->getStreet()));
        ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 6, new QTableWidgetItem(i->getHouseNr()));
        ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 7, new QTableWidgetItem(i->getPostalCode()));
        ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 8, new QTableWidgetItem(i->getCity()));
    }
}

void MainWindow::addClientToTable(Client* client){

    int size = this->clients.size();
    client->setId(size+1);
    this->clients.push_back(*client);
    SaveFile saveFile;
    saveFile.saveToFile();
    ui->ClientsTable->insertRow(ui->ClientsTable->rowCount());
    QString idString = QString::number(client->getId());
   ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 0, new QTableWidgetItem(idString));
   ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 1, new QTableWidgetItem(client->getName()));
   ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 2, new QTableWidgetItem(client->getSurname()));
   ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 3, new QTableWidgetItem(client->getPesel()));
   ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 4, new QTableWidgetItem(client->getNip()));
   ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 5, new QTableWidgetItem(client->getStreet()));
   ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 6, new QTableWidgetItem(client->getHouseNr()));
   ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 7, new QTableWidgetItem(client->getPostalCode()));
   ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 8, new QTableWidgetItem(client->getCity()));
}
