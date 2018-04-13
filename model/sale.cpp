#include "sale.h"

Sale::Sale(QObject *parent) : QObject(parent)
{

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

