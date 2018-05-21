#include "producttosaledialog.h"
#include "ui_producttosaledialog.h"

ProductToSaleDialog::ProductToSaleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProductToSaleDialog)
{
    ui->setupUi(this);
}

void ProductToSaleDialog::addProductsToTable(){

    Product product;

    std::list<Product>::iterator i;
    qDebug()<<"Jestem w addToTable(product), rozmiar listy: "<< Product::products.size();
    QString idString;
    QString quantityString;
    QString priceString;

    for(i=Product::products.begin(); i!=Product::products.end();i++){
        qDebug()<<"W petli";
        idString = QString::number(i->getId());
        quantityString= QString::number(i->getQuantity());
        priceString= QString::number(i->getPrice(),'f',2);

        ui->productToSaleTable->insertRow(ui->productToSaleTable->rowCount());
        ui->productToSaleTable->setItem(ui->productToSaleTable->rowCount()-1, 0, new QTableWidgetItem(idString));
        ui->productToSaleTable->setItem(ui->productToSaleTable->rowCount()-1, 1, new QTableWidgetItem(i->getName()));
        ui->productToSaleTable->setItem(ui->productToSaleTable->rowCount()-1, 2, new QTableWidgetItem(i->getBrand()));
        ui->productToSaleTable->setItem(ui->productToSaleTable->rowCount()-1, 3, new QTableWidgetItem(priceString));
        ui->productToSaleTable->setItem(ui->productToSaleTable->rowCount()-1, 4, new QTableWidgetItem(i->getUnit()));
        ui->productToSaleTable->setItem(ui->productToSaleTable->rowCount()-1, 5, new QTableWidgetItem(quantityString));
        ui->productToSaleTable->setItem(ui->productToSaleTable->rowCount()-1, 6, new QTableWidgetItem(i->getVAT()));
        ui->productToSaleTable->setItem(ui->productToSaleTable->rowCount()-1, 7, new QTableWidgetItem(i->getExpirationDate()));
        ui->productToSaleTable->setItem(ui->productToSaleTable->rowCount()-1, 8, new QTableWidgetItem(i->getAddDate()));
    }

}

int ProductToSaleDialog::getSelectedRow()
{
    return ui->productToSaleTable->currentRow();
}

QString ProductToSaleDialog::getIdQStringFromTable(int row)
{
    return ui->productToSaleTable->item(row,0)->text();
}

ProductToSaleDialog::~ProductToSaleDialog()
{
    delete ui;
}
