#include "sale.h"
#include <list>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QByteArray>
#include <QFileInfo>



Sale::Sale(){

}

int Sale::getId(){
    return this->id;
}

QString Sale::getName(){
    return this->name;
}

QString Sale::getQuantity(){
    return this->quantity;
}

QString Sale::getUnit(){
    return this->unit;
}

QString Sale::getPrice(){
    return this->price;
}


void Sale::setId(int id){
    this->id=id;
}

void Sale::setName(QString name){
    this->name=name;
}

void Sale::setQuantity(QString quantity){
    this->quantity=quantity;
}

void Sale::setUnit(QString unit){
    this->unit=unit;
}

void Sale::setPrice(QString price){
    this->price=price;
}

std::list<Sale> Sale::loadFromFile(){
    QFileInfo check_file("G://sales.txt");
    if(check_file.exists()&&check_file.isFile())
    {
        qDebug()<<"File exist...";
    }else
    {
        qDebug()<<"File not exist...";
    }

     QFile inFile("G://sales.txt");
     inFile.open(QIODevice::ReadOnly | QIODevice::Text);
     std::list<Sale> sales;
     Sale sale;

     while(!inFile.atEnd())
     {
         int position;
         QByteArray idFile=inFile.readLine();
         position=idFile.lastIndexOf(QChar('\n'));
         idFile=idFile.left(position);

         QByteArray nameFile=inFile.readLine();
         position=nameFile.lastIndexOf(QChar('\n'));
         nameFile=nameFile.left(position);

         QByteArray quantityFile=inFile.readLine();
         position=quantityFile.lastIndexOf(QChar('\n'));
         quantityFile=quantityFile.left(position);

         QByteArray unitFile=inFile.readLine();
         position=unitFile.lastIndexOf(QChar('\n'));
         unitFile=unitFile.left(position);


         QByteArray priceFile=inFile.readLine();
         position=priceFile.lastIndexOf(QChar('\n'));

         if(!(position==-1&&priceFile.size()>0)){
            priceFile=priceFile.left(position);
         }

         sale.setId(idFile.toInt());
         sale.setName(nameFile);
         sale.setQuantity(quantityFile);
         sale.setUnit(unitFile);
         sale.setPrice(priceFile);

         sales.push_back(sale);
     }
     inFile.close();
     return sales;
}

void Sale::saveToFile(std::list<Sale> sales){

    QFile caFile("G://sales.txt");
    caFile.open(QIODevice::WriteOnly | QIODevice::Text);

    if(!caFile.isOpen()){
        qDebug() << "- Error, unable to open" << "outputFilename" << "for output";
    }
    QTextStream outStream(&caFile);
    std::list<Sale>::iterator i;
    for(i=sales.begin(); i!=sales.end();i++){
        outStream <<i->getId()<<endl;
        outStream <<i->getName()<<endl;
        outStream <<i->getQuantity()<<endl;
        outStream <<i->getUnit()<<endl;
        outStream <<i->getPrice()<<endl;
    }

    caFile.close();
}
