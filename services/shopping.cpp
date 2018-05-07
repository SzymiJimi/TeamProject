#include "shopping.h"
#include "model/sale.h"
#include <QDate>
#include "model/product.h"
#include "model/productsales.h"
#include <QDebug>

Shopping::Shopping()
{

}

void Shopping::buyProducts( Ui::MainWindow * window){

    if(window->purchasePrice->text().toDouble()>0){
    int rowCount = window->purchasedProductTable->rowCount();
    Sale sale;
    sale.setId((int)Sale::sales.size()+1);
    QDate date = QDate::currentDate();
    QString dateString = date.toString("dd.MM.yyyy");
    sale.setShippingDate(dateString);
    sale.setShippingPrice(window->purchasePrice->text());
    sale.setProductsQuantity(QString::number( window->purchasedProductTable->rowCount()));
    Sale::sales.push_back(sale);
    Sale::addToSaleTable(window, sale);
    Product product;
    ProductSales addingItem;
    QTableWidgetItem *itemFromTable;
    QString element;

    for(int i=0;i<rowCount;i++)
    {
        itemFromTable = window->purchasedProductTable->item(i, 5);
        element= itemFromTable->text();
        addingItem.setProductSaleId((int)ProductSales::productsSales.size());
        qDebug()<<"Product id z tabeli"<<element.toInt();
        addingItem.setProductId(element.toInt());
        addingItem.setSaleId(sale.getId());
        addingItem.setQuantity(window->purchasedProductTable->item(i, 2)->text().toFloat());
        ProductSales::productsSales.push_back(addingItem);
        product = product.findProductById(element.toInt());
        Product::deleteProductById(element.toInt());
        product.setQuantity(product.getQuantity()-window->purchasedProductTable->item(i, 2)->text().toFloat());
        Product::products.push_back(product);
        Product::products.sort();
        product.saveToFile(Product::products);

    }

    window->purchasedProductTable->setRowCount(0);
    window->purchasePrice->setText("0");
    }
    else
        window->returnMessage->setText("Nie wybrano produktów!");


}
