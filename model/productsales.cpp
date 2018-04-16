#include "productsales.h"
#include <list>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QByteArray>
#include <QFileInfo>


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

std::list<ProductSales> ProductSales::loadFromFile(){
    QFileInfo check_file("G://productSales.txt");
    if(check_file.exists()&&check_file.isFile())
    {
        qDebug()<<"File exist...";
    }else
    {
        qDebug()<<"File not exist...";
    }

     QFile inFile("G://productSales.txt");
     inFile.open(QIODevice::ReadOnly | QIODevice::Text);
     std::list<ProductSales> productsSales;
     ProductSales productSales;

     while(!inFile.atEnd())
     {
         int position;
         QByteArray productSaleIdFile=inFile.readLine();
         position=productSaleIdFile.lastIndexOf(QChar('\n'));
         productSaleIdFile=productSaleIdFile.left(position);

         QByteArray productIdFile=inFile.readLine();
         position=productIdFile.lastIndexOf(QChar('\n'));
         productIdFile=productIdFile.left(position);

         QByteArray saleIdFile=inFile.readLine();
         position=saleIdFile.lastIndexOf(QChar('\n'));

         if(!(position==-1&&saleIdFile.size()>0)){
            saleIdFile=saleIdFile.left(position);
         }

         productSales.setProductSaleId(productSaleIdFile.toInt());
         productSales.setProductId(productIdFile.toInt());
         productSales.setSaleId(saleIdFile.toInt());


         productsSales.push_back(productSales);
     }
     inFile.close();
     return productsSales;
}

void ProductSales::saveToFile(std::list<ProductSales> productsSales){
    QFile caFile("G://productSales.txt");
    caFile.open(QIODevice::WriteOnly | QIODevice::Text);

    if(!caFile.isOpen()){
        qDebug() << "- Error, unable to open" << "outputFilename" << "for output";
    }
    QTextStream outStream(&caFile);
    std::list<ProductSales>::iterator i;
    for(i=productsSales.begin(); i!=productsSales.end();i++){
        outStream <<i->getProductSaleId()<<endl;
        outStream <<i->getProductId()<<endl;
        outStream <<i->getSaleId()<<endl;
    }

    caFile.close();
}
