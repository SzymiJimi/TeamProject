#include "invoice.h"
#include <list>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QByteArray>
#include <QFileInfo>
#include <QTextCodec>


Invoice::Invoice(){

}

int Invoice::getId(){
    return this->id;
}

int Invoice::getPurchaseNr(){
    return this->purchaseNr;
}

QString Invoice::getPurchaseDate(){
    return this->purchaseDate;
}

QString Invoice::getPurchaseValue(){
    return this->purchaseValue;
}

int Invoice::getProductsAmount(){
    return this->productsAmount;
}

void Invoice::setId(int id){
    this->id=id;
}

void Invoice::setPurchaseNr(int purchaseNr){
    this->purchaseNr=purchaseNr;
}

void Invoice::setPurchaseDate(QString purchaseDate){
    this->purchaseDate=purchaseDate;
}

void Invoice::setPurchaseValue(QString purchaseValue){
    this->purchaseValue=purchaseValue;
}

void Invoice::setProductsAmount(int productsAmount){
    this->productsAmount=productsAmount;
}


std::list<Invoice> Invoice::loadFromFile(){
    QFileInfo check_file("D://Wojtek//Studia//Programowanie//C++//qt//TeamProject-master//files//invoices.txt");
    if(check_file.exists()&&check_file.isFile())
    {
        qDebug()<<"File exist...";
    }else
    {
        qDebug()<<"File not exist...";
    }

     QFile in("D://Wojtek//Studia//Programowanie//C++//qt//TeamProject-master//files//invoices.txt");
     in.open(QIODevice::ReadOnly | QIODevice::Text);
     QTextStream inFile(&in);
     inFile.setCodec(QTextCodec::codecForName("UTF-8"));
     std::list<Invoice> invoices;
     Invoice invoice;

     while(!inFile.atEnd())
     {
         int position;
         QString idFile=inFile.readLine();
         position=idFile.lastIndexOf(QChar('\n'));
         idFile=idFile.left(position);

         QString purchaseNrFile=inFile.readLine();
         position=purchaseNrFile.lastIndexOf(QChar('\n'));
         purchaseNrFile=purchaseNrFile.left(position);

         QString purchaseDateFile=inFile.readLine();
         position=purchaseDateFile.lastIndexOf(QChar('\n'));
         purchaseDateFile=purchaseDateFile.left(position);

         QString purchaseValueFile=inFile.readLine();
         position=purchaseValueFile.lastIndexOf(QChar('\n'));
         purchaseValueFile=purchaseValueFile.left(position);

         QString productsAmountFile=inFile.readLine();
         position=productsAmountFile.lastIndexOf(QChar('\n'));

         if(!(position==-1&&productsAmountFile.size()>0)){
            productsAmountFile=productsAmountFile.left(position);
         }

         invoice.setId(idFile.toInt());
         invoice.setPurchaseNr(purchaseNrFile.toInt());
         invoice.setPurchaseDate(purchaseDateFile);
         invoice.setPurchaseValue(purchaseValueFile);
         invoice.setProductsAmount(productsAmountFile.toInt());

         invoices.push_back(invoice);
     }
     in.close();
     return invoices;
}

void Invoice::saveToFile(std::list<Invoice> invoices){

    QFile caFile("D://Wojtek//Studia//Programowanie//C++//qt//TeamProject-master//files//invoices.txt");
    caFile.open(QIODevice::WriteOnly | QIODevice::Text);

    if(!caFile.isOpen()){
        qDebug() << "- Error, unable to open" << "outputFilename" << "for output";
    }
    QTextStream outStream(&caFile);
    std::list<Invoice>::iterator i;
    for(i=invoices.begin(); i!=invoices.end();i++){
        outStream <<QString::number(i->getId()).toUtf8()<<endl;
        outStream <<QString::number(i->getPurchaseNr()).toUtf8()<<endl;
        outStream <<i->getPurchaseDate().toUtf8()<<endl;
        outStream <<i->getPurchaseValue().toUtf8()<<endl;
        outStream <<QString::number(i->getProductsAmount()).toUtf8()<<endl;
    }

    caFile.close();
}
