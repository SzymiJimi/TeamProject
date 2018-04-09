#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "dialog/addclient.h"
#include "model/client.h"
#include <QDebug>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)


{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
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

void MainWindow::addClientToTable(Client* client){
   ui->ClientsTable->insertRow(ui->ClientsTable->rowCount());
   ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 0, new QTableWidgetItem(client->name));
   ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 1, new QTableWidgetItem(client->surname));
   ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 2, new QTableWidgetItem(client->pesel));
   ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 3, new QTableWidgetItem(client->nip));
   ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 4, new QTableWidgetItem(client->street));
   ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 5, new QTableWidgetItem(client->houseNr));
   ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 6, new QTableWidgetItem(client->postalCode));
   ui->ClientsTable->setItem(ui->ClientsTable->rowCount()-1, 7, new QTableWidgetItem(client->city));
}
