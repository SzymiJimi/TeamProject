#include "finddialog.h"
#include "ui_finddialog.h"
#include "model/product.h"
#include <list>
#include <QDebug>


FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDialog)
{
    ui->setupUi(this);
}

FindDialog::~FindDialog()
{
    delete ui;
}

int FindDialog::getSelected()
{
    return ui->foundProductTable->currentRow();
}

int FindDialog::getProductId(){

    QString idString = ui->productId->text();
    int prodId=idString.toInt();
    return prodId;
}


void FindDialog::on_findButton_clicked()
{
    int productId = getProductId();
    Product tmp;
    Product product= tmp.findProductById(productId);
    QString quantityString = QString::number(product.getQuantity());
    QString priceString = QString::number(product.getPrice(),'f',2);
    ui->foundProductTable->setRowCount(0);
    ui->foundProductTable->insertRow(ui->foundProductTable->rowCount());
    ui->foundProductTable->setItem(ui->foundProductTable->rowCount()-1,0, new QTableWidgetItem(product.getName()));
    ui->foundProductTable->setItem(ui->foundProductTable->rowCount()-1,1, new QTableWidgetItem(product.getBrand()));
    ui->foundProductTable->setItem(ui->foundProductTable->rowCount()-1,2, new QTableWidgetItem(priceString));
    ui->foundProductTable->setItem(ui->foundProductTable->rowCount()-1,3, new QTableWidgetItem(product.getUnit()));
    ui->foundProductTable->setItem(ui->foundProductTable->rowCount()-1,4, new QTableWidgetItem(quantityString));
    ui->foundProductTable->setItem(ui->foundProductTable->rowCount()-1,5, new QTableWidgetItem(product.getVAT()));
    ui->foundProductTable->setItem(ui->foundProductTable->rowCount()-1,6, new QTableWidgetItem(product.getExpirationDate()));
    ui->foundProductTable->setItem(ui->foundProductTable->rowCount()-1,7, new QTableWidgetItem(product.getAddDate()));

    qDebug()<<"Nazwa znalezionego produktu: "<<product.getName();

}

void FindDialog::on_findByNameButton_clicked()
{
    ui->foundProductTable->setRowCount(0);
    QString name = ui->productNameSearch->text();
    std::list <Product> products = Product::findProductsByName(name);
    std::list <Product>::iterator it;
    for(it=products.begin(); it!=products.end();it++){
        ui->foundProductTable->insertRow(ui->foundProductTable->rowCount());
        ui->foundProductTable->setItem(ui->foundProductTable->rowCount()-1,0, new QTableWidgetItem(it->getName()));
        ui->foundProductTable->setItem(ui->foundProductTable->rowCount()-1,1, new QTableWidgetItem(it->getBrand()));
        ui->foundProductTable->setItem(ui->foundProductTable->rowCount()-1,2, new QTableWidgetItem(QString::number(it->getPrice(),'f',2)));
        ui->foundProductTable->setItem(ui->foundProductTable->rowCount()-1,3, new QTableWidgetItem(it->getUnit()));
        ui->foundProductTable->setItem(ui->foundProductTable->rowCount()-1,4, new QTableWidgetItem(QString::number(it->getQuantity(),'f',2)));
        ui->foundProductTable->setItem(ui->foundProductTable->rowCount()-1,5, new QTableWidgetItem(it->getVAT()));
        ui->foundProductTable->setItem(ui->foundProductTable->rowCount()-1,6, new QTableWidgetItem(it->getExpirationDate()));
        ui->foundProductTable->setItem(ui->foundProductTable->rowCount()-1,7, new QTableWidgetItem(it->getAddDate()));
    }
}
