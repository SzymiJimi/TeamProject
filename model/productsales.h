#ifndef PRODUCTSALES_H
#define PRODUCTSALES_H

#include <QObject>
#include <list>

class ProductSales
{
public:
    ProductSales();
    int getProductSaleId();
    int getProductId();
    int getSaleId();

    void setProductSaleId(int productSaleId);
    void setProductId(int productId);
    void setSaleId(int saleId);

    std::list<ProductSales> loadFromFile();
    void saveToFile(std::list<ProductSales> productsSales);

signals:

public slots:

private:
    int productSaleId;
    int productId;
    int saleId;
};

#endif // PRODUCTSALES_H
