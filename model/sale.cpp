#include "sale.h"
#include <list>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QByteArray>
#include <QFileInfo>
#include <QTextCodec>

std::list<Sale> Sale::sales;

Sale::Sale(){

}

int Sale::getId(){
    return this->id;
}

QString Sale::getShippingDate(){
    return this->shippingDate;
}

QString Sale::getShippingPrice(){
    return this->shippingPrice;
}

QString Sale::getProductsQuantity(){
    return this->productsQuantity;
}


void Sale::setId(int id){
    this->id=id;
}

void Sale::setShippingDate(QString shippingDate){
    this->shippingDate=shippingDate;
}

void Sale::setShippingPrice(QString shippingPrice){
    this->shippingPrice=shippingPrice;
}

void Sale::setProductsQuantity(QString productsQuantity){
    this->productsQuantity=productsQuantity;
}


std::list<Sale> Sale::loadFromFile(){
    QFileInfo check_file("D://Wojtek//Studia//Programowanie//C++//qt//TeamProject-master//files//sales.txt");
    if(check_file.exists()&&check_file.isFile())
    {
        qDebug()<<"File exist...";
    }else
    {
        qDebug()<<"File not exist...";
    }

     QFile in("D://Wojtek//Studia//Programowanie//C++//qt//TeamProject-master//files//sales.txt");
     in.open(QIODevice::ReadOnly | QIODevice::Text);
     QTextStream inFile(&in);
     inFile.setCodec(QTextCodec::codecForName("UTF-8"));
     std::list<Sale> sales;
     Sale sale;

     while(!inFile.atEnd())
     {
         int position;
         QString idFile=inFile.readLine();
         position=idFile.lastIndexOf(QChar('\n'));
         idFile=idFile.left(position);

         QString shippingDateFile=inFile.readLine();
         position=shippingDateFile.lastIndexOf(QChar('\n'));
         shippingDateFile=shippingDateFile.left(position);

         QString shippingPriceFile=inFile.readLine();
         position=shippingPriceFile.lastIndexOf(QChar('\n'));
         shippingPriceFile=shippingPriceFile.left(position);


         QString quantityFile=inFile.readLine();
         position=quantityFile.lastIndexOf(QChar('\n'));

         if(!(position==-1&&quantityFile.size()>0)){
            quantityFile=quantityFile.left(position);
         }

         sale.setId(idFile.toInt());
         sale.setShippingDate(shippingDateFile);
         sale.setShippingPrice(shippingPriceFile);
         sale.setProductsQuantity(quantityFile);

         sales.push_back(sale);
     }
     in.close();
     return sales;
}

void Sale::saveToFile(std::list<Sale> sales){

    QFile caFile("D://Wojtek//Studia//Programowanie//C++//qt//TeamProject-master//files//sales.txt");
    caFile.open(QIODevice::WriteOnly | QIODevice::Text);

    if(!caFile.isOpen()){
        qDebug() << "- Error, unable to open" << "outputFilename" << "for output";
    }
    QTextStream outStream(&caFile);
    outStream.setCodec(QTextCodec::codecForName("UTF-8"));
    std::list<Sale>::iterator i;
    for(i=sales.begin(); i!=sales.end();i++){
        outStream <<QString::number(i->getId())<<endl;
        outStream <<i->getShippingDate()<<endl;
        outStream <<i->getShippingPrice()<<endl;
        outStream <<i->getProductsQuantity()<<endl;
    }

    caFile.close();
}

void Sale::addToSaleTable(Ui::MainWindow *window, Sale sale)
{
    QString idString;
    idString = QString::number(sale.getId());
    window->shoppingTable->insertRow(window->shoppingTable->rowCount());
    window->shoppingTable->setItem(window->shoppingTable->rowCount()-1, 0, new QTableWidgetItem(idString));
    window->shoppingTable->setItem(window->shoppingTable->rowCount()-1, 1, new QTableWidgetItem(sale.getShippingDate()));
    window->shoppingTable->setItem(window->shoppingTable->rowCount()-1, 2, new QTableWidgetItem(sale.getShippingPrice()));
    window->shoppingTable->setItem(window->shoppingTable->rowCount()-1, 3, new QTableWidgetItem(sale.getProductsQuantity()));

}

Sale Sale::findSaleById(int id)
{
    std::list<Sale>::iterator it=sales.begin();
    Sale sale;
    int counter=0;
    for (; it != Sale::sales.end(); it++){
        sale = *it;
        if(counter==id){
            break;
        }
        counter++;
    }
    return sale;
}

void Sale::addFromFileToTable(Ui::MainWindow * window){

        Sale sale;
        sales = sale.loadFromFile();
        std::list<Sale>::iterator i;
        qDebug()<<"Jestem w addToTable(product), rozmiar listy: "<<sales.size();


        for(i=sales.begin(); i!=sales.end();i++){
            qDebug()<<"W petli";
            addToSaleTable( window,  *i);
        }

}
