#include "finddialog.h"
#include "ui_finddialog.h"
#include "model/product.h"
#include <list>
#include <QDebug>

int prodId;

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

void FindDialog::getProductId(){

    QString idString = ui->productId->text();
    prodId=idString.toInt();
}

bool productIdIsEqual(Product product){
    return ((product.getId()==prodId));
}

Product FindDialog::findProductById(){
    std::list<Product> productList= Product::products;
    std::list<Product>::iterator findIter = std::find_if(Product::products.begin(), Product::products.end(), productIdIsEqual);
    Product &product = *findIter;
//        Product product;
    return product;

//    return product;
}

void FindDialog::on_findButton_clicked()
{
    getProductId();
    Product product= findProductById();
    QString idString = QString::number(product.getId());
    QString quantityString = QString::number(product.getQuantity());
    QString priceString = QString::number(product.getPrice());

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
