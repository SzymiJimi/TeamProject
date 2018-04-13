#include "productsales.h"

ProductSales::ProductSales(QObject *parent) : QObject(parent)
{

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
