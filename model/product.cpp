#include "product.h"

Product::Product(QObject *parent) : QObject(parent)
{

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

