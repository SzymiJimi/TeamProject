#include "product.h"
#include <list>
#include <mainwindow.h>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QByteArray>
#include <QFileInfo>
#include <QTextCodec>


Product::Product(){

}

int Product::getId(){
    return this->id;
}

QString Product::getName(){
   return this->name;
}

QString Product::getBrand(){
    return this->brand;
}

float Product::getQuantity(){
    return this->quantity;
}

QString Product::getUnit(){
    return this->unit;
}

float Product::getPrice(){
    return this->price;
}

QString Product::getVAT(){
    return this->VAT;
}

QString Product::getExpirationDate(){
    return this->expirationDate;
}

QString Product::getAddDate(){
    return this->addDate;
}

void Product::setId(int id){
    this->id=id;
}

void Product::setName(QString name){
    this->name=name;
}

void Product::setBrand(QString brand){
    this->brand=brand;
}

void Product::setQuantity(float quantity){
    this->quantity=quantity;
}

void Product::setUnit(QString unit){
    this->unit=unit;
}

void Product::setPrice(float price){
    this->price=price;
}

void Product::setVAT(QString VAT){
    this->VAT=VAT;
}

void Product::setExpirationDate(QString expirationDate){
    this->expirationDate=expirationDate;
}

void Product::setAddDate(QString addDate){
    this->addDate=addDate;
}

std::list<Product> Product::loadFromFile(){
    QFileInfo check_file("G://products.txt");
    if(check_file.exists()&&check_file.isFile())
    {
        qDebug()<<"File exist...";
    }else
    {
        qDebug()<<"File not exist...";
    }

     QFile in("G://products.txt");
     in.open(QIODevice::ReadOnly | QIODevice::Text);
     QTextStream inFile(&in);
     inFile.setCodec(QTextCodec::codecForName("UTF-8"));
     std::list<Product> products;
     Product product;

     while(!inFile.atEnd())
     {
         int position;
         QString idFile=inFile.readLine();
         position=idFile.lastIndexOf(QChar('\n'));
         idFile=idFile.left(position);

         QString nameFile=inFile.readLine();
         position=nameFile.lastIndexOf(QChar('\n'));
         nameFile=nameFile.left(position);

         QString brandFile=inFile.readLine();
         position=brandFile.lastIndexOf(QChar('\n'));
         brandFile=brandFile.left(position);

         QString quantityFile=inFile.readLine();
         position=quantityFile.lastIndexOf(QChar('\n'));
         quantityFile=quantityFile.left(position);

         QString unitFile=inFile.readLine();
         position=unitFile.lastIndexOf(QChar('\n'));
         unitFile=unitFile.left(position);

         QString priceFile=inFile.readLine();
         position=priceFile.lastIndexOf(QChar('\n'));
         priceFile=priceFile.left(position);

         QString VATFile=inFile.readLine();
         position=VATFile.lastIndexOf(QChar('\n'));
         VATFile=VATFile.left(position);

         QString expirationDateFile=inFile.readLine();
         position=expirationDateFile.lastIndexOf(QChar('\n'));
         expirationDateFile=expirationDateFile.left(position);

         QString addDateFile=inFile.readLine();
         position=addDateFile.lastIndexOf(QChar('\n'));

         if(!(position==-1&&addDateFile.size()>0)){
            addDateFile=addDateFile.left(position);
         }

         product.setId(idFile.toInt());
         product.setName(nameFile);
         product.setBrand(brandFile);
         product.setQuantity(quantityFile.toFloat());
         product.setUnit(unitFile);
         product.setPrice(priceFile.toFloat());
         product.setVAT(VATFile);
         product.setExpirationDate(expirationDateFile);
         product.setAddDate(addDateFile);

         products.push_back(product);
     }
     in.close();
     return products;
}

void Product::saveToFile(std::list<Product> products){
    QFile caFile("G://products.txt");
    caFile.open(QIODevice::WriteOnly | QIODevice::Text);

    if(!caFile.isOpen()){
        qDebug() << "- Error, unable to open" << "outputFilename" << "for output";
    }
    QTextStream outStream(&caFile);
    std::list<Product>::iterator i;
    for(i=products.begin(); i!=products.end();i++){
        outStream <<QString::number(i->getId()).toUtf8() <<endl;
        outStream <<i->getBrand().toUtf8()<<endl;
        outStream <<QString::number(i->getQuantity()).toUtf8()<<endl;
        outStream <<i->getUnit().toUtf8()<<endl;
        outStream <<QString::number(i->getPrice()).toUtf8()<<endl;
        outStream <<i->getVAT().toUtf8()<<endl;
        outStream <<i->getExpirationDate().toUtf8()<<endl;
        outStream <<i->getAddDate().toUtf8()<<endl;
    }

    caFile.close();
}

void Product::addFromFileToTable(Ui::MainWindow * window){

        Product product;
        std::list<Product> products = product.loadFromFile();
        std::list<Product>::iterator i;
        qDebug()<<"Jestem w addToTable(product), rozmiar listy: "<<products.size();
         QString idString;
         QString quantityString;
         QString priceString;

        for(i=products.begin(); i!=products.end();i++){
            qDebug()<<"W petli";
            idString = QString::number(i->getId());
            quantityString= QString::number(i->getQuantity());
            priceString= QString::number(i->getPrice());

            window->productsTable->insertRow(window->productsTable->rowCount());
            window->productsTable->setItem(window->productsTable->rowCount()-1, 0, new QTableWidgetItem(idString));
            window->productsTable->setItem(window->productsTable->rowCount()-1, 1, new QTableWidgetItem(i->getName()));
            window->productsTable->setItem(window->productsTable->rowCount()-1, 2, new QTableWidgetItem(i->getBrand()));
            window->productsTable->setItem(window->productsTable->rowCount()-1, 3, new QTableWidgetItem(quantityString));
            window->productsTable->setItem(window->productsTable->rowCount()-1, 4, new QTableWidgetItem(i->getUnit()));
            window->productsTable->setItem(window->productsTable->rowCount()-1, 5, new QTableWidgetItem(priceString));
            window->productsTable->setItem(window->productsTable->rowCount()-1, 6, new QTableWidgetItem(i->getVAT()));
            window->productsTable->setItem(window->productsTable->rowCount()-1, 7, new QTableWidgetItem(i->getExpirationDate()));
            window->productsTable->setItem(window->productsTable->rowCount()-1, 8, new QTableWidgetItem(i->getAddDate()));
        }

}



