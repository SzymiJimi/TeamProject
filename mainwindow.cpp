#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "dialog/addclient.h"
#include "model/client.h"
#include <QDebug>
#include "services/savefile.h"
#include "model/product.h"
#include "model/sale.h"
#include "dialog/finddialog.h"
#include <iomanip>
#include "services/shopping.h"
#include "model/productsales.h"
#include "dialog/addproduct.h"
#include <services/pdfcreator.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    addClientsFromFileToTable();
    Product::addFromFileToTable(ui);
    Sale::addFromFileToTable(ui);
    ProductSales productSales;
    productSales.loadFromFile();
}

MainWindow::~MainWindow()
{
    SaveFile save;
    save.saveClientsToFile(this->clients);
    Product product;
    product.saveToFile(Product::products);
    Sale sale;
    sale.saveToFile(Sale::sales);
    ProductSales productSales;
    productSales.saveToFile();
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

    MainWindow::clients= saveFile.loadClientsFromFile();
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

    int size = (int) this->clients.size();
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

void MainWindow::on_pushButton_6_clicked()
{
    FindDialog findProduct;
    findProduct.setModal(true);
    if(findProduct.exec()==QDialog::Accepted){
        qDebug()<<"Nacisnoles ok!";
//        int* id = findProduct.getProductId();


    }
}

void MainWindow::on_addPurchasedItem_clicked()
{
    Product tmpProd;
    QString productCodeString = ui->productCodeField->text();
    int productCode=productCodeString.toInt();
    Product product= tmpProd.findProductById(productCode);
    if(product.getId()>0)
    {
        double amount = ui->productsAmount->value();
        if(amount>0){
        double cost=(round((amount * product.getPrice())*100))/100;
        QString costString = QString::number(cost);
        QString priceString = QString::number(product.getPrice());
        if(amount>product.getQuantity()){
            ui->returnMessage->setText("Za duża ilość(max:"+QString::number(product.getQuantity())+")");
        }else{
        double purchasePrice= ui->purchasePrice->text().toDouble();
        qDebug()<<"Aktualna cena zakupów:"<<purchasePrice;
        purchasePrice=purchasePrice+cost;
        purchasePrice = (round(purchasePrice*100))/100;
        ui->purchasePrice->setText(QString::number(purchasePrice));
        ui->returnMessage->setText("Znaleziono produkt!");
        ui->purchasedProductTable->insertRow(ui->purchasedProductTable->rowCount());
        ui->purchasedProductTable->setItem(ui->purchasedProductTable->rowCount()-1, 0, new QTableWidgetItem(product.getName()));
        ui->purchasedProductTable->setItem(ui->purchasedProductTable->rowCount()-1, 1, new QTableWidgetItem(priceString));
        ui->purchasedProductTable->setItem(ui->purchasedProductTable->rowCount()-1, 2, new QTableWidgetItem(QString::number(amount)));
        ui->purchasedProductTable->setItem(ui->purchasedProductTable->rowCount()-1, 3, new QTableWidgetItem(product.getUnit()));
        ui->purchasedProductTable->setItem(ui->purchasedProductTable->rowCount()-1, 4, new QTableWidgetItem(costString));
        ui->purchasedProductTable->setItem(ui->purchasedProductTable->rowCount()-1, 5, new QTableWidgetItem(QString::number(productCode)));
          }
        }else{
            ui->returnMessage->setText("Nie podałeś ilości...");
        }

    }else{
        ui->returnMessage->setText("Nie znaleziono produktu...");
    }
}

void MainWindow::on_finishShopping_clicked()
{
     Shopping shopping;
     shopping.buyProducts(ui);
}

void MainWindow::on_addProductButton_clicked()
{
    AddProduct addProduct;
    addProduct.setModal(true);
    if(addProduct.exec()==QDialog::Accepted){
        qDebug()<<"Okno dialogowe dodania produktu!"<< endl;
        Product* product = addProduct.getProductFromFrom();
        qDebug() <<"Jednostka: " << product->getQuantity();
        Product::products.push_back(*product);
        QString id = QString::number(product->getId());
        QString quantity = QString::number(product->getQuantity());
        QString price = QString::number(product->getPrice());

        ui->productsTable->insertRow(ui->productsTable->rowCount());
        ui->productsTable->setItem(ui->productsTable->rowCount()-1, 0, new QTableWidgetItem(id));
        ui->productsTable->setItem(ui->productsTable->rowCount()-1, 1, new QTableWidgetItem(product->getName()));
        ui->productsTable->setItem(ui->productsTable->rowCount()-1, 2, new QTableWidgetItem(product->getBrand()));
        ui->productsTable->setItem(ui->productsTable->rowCount()-1, 3, new QTableWidgetItem(quantity));
        ui->productsTable->setItem(ui->productsTable->rowCount()-1, 4, new QTableWidgetItem(product->getUnit()));
        ui->productsTable->setItem(ui->productsTable->rowCount()-1, 5, new QTableWidgetItem(price));
        ui->productsTable->setItem(ui->productsTable->rowCount()-1, 6, new QTableWidgetItem(product->getVAT()));
        ui->productsTable->setItem(ui->productsTable->rowCount()-1, 7, new QTableWidgetItem(product->getExpirationDate()));
        ui->productsTable->setItem(ui->productsTable->rowCount()-1, 8, new QTableWidgetItem(product->getAddDate()));




        delete product;


    }
}

void MainWindow::on_productsTable_cellClicked(int row, int column)
{
    list<Product>::iterator it=Product::products.begin();
    Product product;
    int counter = 0;
    for (; it != Product::products.end(); it++){
        product = *it;
        if(counter==row){
            break;
        }
        counter++;

    }
    //Product::products.erase(it);
    qDebug() << product.getId();
    AddProduct addProduct;
    addProduct.setModal(true);
    addProduct.setFormForEdit(product);
    if(addProduct.exec()==QDialog::Accepted){
        qDebug()<<"Okno dialogowe dodania produktu!"<< endl;
//        Product* updatedProduct = addProduct.getProductFromFrom();
//        Product::products.insert(it, *updatedProduct);
//        *it++;
//        Product::products.erase(it);
//To nie działa
    }



}

void MainWindow::on_receiptButton_clicked()
{
    int idTmp=ui->shoppingTable->currentRow();
    Sale sale=Sale::findSaleById(idTmp);
    idTmp=sale.getId();
    std::list<ProductSales> concreteSales=ProductSales::findProductSalesBySaleId(idTmp);

    std::list<ProductSales>::iterator it=concreteSales.begin();

    QString content="";
    Product product;
    for (; it != concreteSales.end(); it++){
        product=product.findProductById(it->getProductId());
        QString idQString = QString::number(product.getId());
        content+= idQString + "   " + product.getName() +"<br>";
        qDebug() << "Siup " << content;

    }
    content+="<br>- - - - - - - - - - - - - - - - - - - - - - -<br>RAZEM:   ";
    content += sale.getShippingPrice();
    PDFCreator::printReceipt(content);
}

void MainWindow::on_pushButton_10_clicked()
{
    InvoiceDialog invoiceDialog;
    invoiceDialog.setModal(true);
    invoiceDialog.addClientsFromFileToTable();
    int id=-1;
    if(invoiceDialog.exec()==QDialog::Accepted){
        id=invoiceDialog.getSelectedRow();
    }
    qDebug() << "ZAZNACZONE TO " << id;
}
