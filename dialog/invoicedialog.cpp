#include "invoicedialog.h"
#include "ui_invoicedialog.h"
#include <QDebug>

InvoiceDialog::InvoiceDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InvoiceDialog)
{
    ui->setupUi(this);
}

void InvoiceDialog::addClientsFromFileToTable()
{
    SaveFile saveFile;

    std::list<Client> clients= saveFile.loadClientsFromFile();
    std::list<Client>::iterator i;
     QString idString;
    for(i=clients.begin(); i!=clients.end();i++){
        qDebug()<<"W petli";
        idString = QString::number(i->getId());
        ui->ClientsTableForInvoice->insertRow(ui->ClientsTableForInvoice->rowCount());
        ui->ClientsTableForInvoice->setItem(ui->ClientsTableForInvoice->rowCount()-1, 0, new QTableWidgetItem(idString));
        ui->ClientsTableForInvoice->setItem(ui->ClientsTableForInvoice->rowCount()-1, 1, new QTableWidgetItem(i->getName()));
        ui->ClientsTableForInvoice->setItem(ui->ClientsTableForInvoice->rowCount()-1, 2, new QTableWidgetItem(i->getSurname()));
        ui->ClientsTableForInvoice->setItem(ui->ClientsTableForInvoice->rowCount()-1, 3, new QTableWidgetItem(i->getPesel()));
        ui->ClientsTableForInvoice->setItem(ui->ClientsTableForInvoice->rowCount()-1, 4, new QTableWidgetItem(i->getNip()));
        ui->ClientsTableForInvoice->setItem(ui->ClientsTableForInvoice->rowCount()-1, 5, new QTableWidgetItem(i->getStreet()));
        ui->ClientsTableForInvoice->setItem(ui->ClientsTableForInvoice->rowCount()-1, 6, new QTableWidgetItem(i->getHouseNr()));
        ui->ClientsTableForInvoice->setItem(ui->ClientsTableForInvoice->rowCount()-1, 7, new QTableWidgetItem(i->getPostalCode()));
        ui->ClientsTableForInvoice->setItem(ui->ClientsTableForInvoice->rowCount()-1, 8, new QTableWidgetItem(i->getCity()));
    }
}

int InvoiceDialog::getSelectedRow()
{
    int id = ui->ClientsTableForInvoice->currentRow();
    if(id>=0){
        return id;
    }
    else
        return -1;
}

int InvoiceDialog::getIdFromTable(int row)
{
    QString idString =  ui->ClientsTableForInvoice->item(row,0)->text();
    return idString.toInt();
}

InvoiceDialog::~InvoiceDialog()
{
    delete ui;
}
