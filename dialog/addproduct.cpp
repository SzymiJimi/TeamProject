#include "addproduct.h"
#include "ui_addproduct.h"
#include <list>
#include <iomanip>
#include <iostream>

AddProduct::AddProduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddProduct)
{
    ui->setupUi(this);
}

AddProduct::~AddProduct()
{
    delete ui;
}

Product *AddProduct::getProductFromFrom()
{
    Product *product = new Product();
    if(Product::products.empty()){
        product->setId(1);
    }
    else{
        std::list<Product>::reverse_iterator it=Product::products.rbegin();
        Product last=*it;
        product->setId(last.getId()+1);
    }
    product->setName(ui->name->text());
    product->setBrand(ui->brand->text());
    QString quantity = ui->quantity->text();
    product->setQuantity(quantity.toFloat());
    product->setUnit(ui->unit->text());
    QString price = ui->price->text();
    product->setPrice(price.toFloat());
    product->setVAT(ui->VAT->text());
    product->setExpirationDate(ui->expirationDate->text());
    QDateTime t = QDateTime::currentDateTime ();
    QString s = t.toString("dd.MM.yyyy");
    product->setAddDate(s);

    return product;
}

void AddProduct::setFormForEdit(Product product)
{
    QWidget::setWindowTitle("Edytuj produkt");
    ui->label_9->setText("Wprowadź dane do edycji");
    ui->name->setText(product.getName());
    ui->brand->setText(product.getBrand());
    QString quantity = QString::number(product.getQuantity());
    QString price = QString::number(product.getPrice());
    ui->quantity->setText(quantity);
    ui->unit->setText(product.getUnit());
    ui->price->setText(price);
    ui->VAT->setText(product.getVAT());
    ui->expirationDate->setText(product.getExpirationDate());
}
