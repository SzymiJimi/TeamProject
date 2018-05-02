#ifndef PRODUCTSALES_H
#define PRODUCTSALES_H

#include <QObject>
#include <list>
#include <mainwindow.h>

class ProductSales
{
public:
    ProductSales();
    int getProductSaleId();
    int getProductId();
    int getSaleId();
    float getQuantity();

    void setProductSaleId(int productSaleId);
    void setProductId(int productId);
    void setSaleId(int saleId);
    void setQuantity(float quantity);

    void loadFromFile();
    void saveToFile();
    static std::list<ProductSales> findProductSalesBySaleId(int id);
//    static void addFromFileToTable(Ui::MainWindow * window);

    static std::list<ProductSales> productsSales;

signals:

public slots:

private:
    int productSaleId;
    int productId;
    int saleId;
    float quantity;
};

#endif // PRODUCTSALES_H
