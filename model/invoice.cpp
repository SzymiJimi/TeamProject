#include "invoice.h"

Invoice::Invoice(QObject *parent) : QObject(parent)
{

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
