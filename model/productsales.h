#ifndef PRODUCTSALES_H
#define PRODUCTSALES_H

#include <QObject>

class ProductSales : public QObject
{
    Q_OBJECT
public:
    explicit ProductSales(QObject *parent = nullptr);

    int getProductSaleId();
    int getProductId();
    int getSaleId();

    void setProductSaleId(int productSaleId);
    void setProductId(int productId);
    void setSaleId(int saleId);

signals:

public slots:

private:
    int productSaleId;
    int productId;
    int saleId;
};

#endif // PRODUCTSALES_H
