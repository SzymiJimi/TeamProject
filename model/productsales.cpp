#include "productsales.h"
#include <list>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QByteArray>
#include <QFileInfo>
#include <QTextCodec>

std::list<ProductSales> ProductSales::productsSales;

ProductSales::ProductSales(){

}

int ProductSales::getProductSaleId(){
    return this->productSaleId;
}

int ProductSales::getProductId(){
    return this->productId;
}

int ProductSales::getSaleId(){
    return this->saleId;
}


void ProductSales::setProductSaleId(int productSaleId){
    this->productSaleId=productSaleId;
}

void ProductSales::setProductId(int productId){
    this->productId=productId;
}

void ProductSales::setSaleId(int saleId){
    this->saleId=saleId;
}

void ProductSales::loadFromFile(){
    QFileInfo check_file("G://productSales.txt");
    if(check_file.exists()&&check_file.isFile())
    {
        qDebug()<<"File exist...";
    }else
    {
        qDebug()<<"File not exist...";
    }

     QFile in("G://productSales.txt");
     in.open(QIODevice::ReadOnly | QIODevice::Text);
     QTextStream inFile(&in);
     inFile.setCodec(QTextCodec::codecForName("UTF-8"));
     ProductSales productSales;

     while(!inFile.atEnd())
     {
         int position;
         QString productSaleIdFile=inFile.readLine();
         position=productSaleIdFile.lastIndexOf(QChar('\n'));
         productSaleIdFile=productSaleIdFile.left(position);

         QString productIdFile=inFile.readLine();
         position=productIdFile.lastIndexOf(QChar('\n'));
         productIdFile=productIdFile.left(position);

         QString saleIdFile=inFile.readLine();
         position=saleIdFile.lastIndexOf(QChar('\n'));

         if(!(position==-1&&saleIdFile.size()>0)){
            saleIdFile=saleIdFile.left(position);
         }

         productSales.setProductSaleId(productSaleIdFile.toInt());
         productSales.setProductId(productIdFile.toInt());
         productSales.setSaleId(saleIdFile.toInt());

         productsSales.push_back(productSales);
     }
     in.close();
}

void ProductSales::saveToFile(){
    QFile caFile("G://productSales.txt");
    caFile.open(QIODevice::WriteOnly | QIODevice::Text);

    if(!caFile.isOpen()){
        qDebug() << "- Error, unable to open" << "outputFilename" << "for output";
    }
    QTextStream outStream(&caFile);
    outStream.setCodec(QTextCodec::codecForName("UTF-8"));

    std::list<ProductSales>::iterator i;
    for(i=productsSales.begin(); i!=productsSales.end();i++){
        outStream <<QString::number(i->getProductSaleId())<<endl;
        outStream <<QString::number(i->getProductId())<<endl;
        outStream <<QString::number(i->getSaleId())<<endl;
    }

    caFile.close();
}


