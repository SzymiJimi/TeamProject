#ifndef SALE_H
#define SALE_H

#include <QObject>
#include <mainwindow.h>



class Sale
{

public:
    Sale();
    int getId();
    QString getShippingDate();
    QString getShippingPrice();
    QString getProductsQuantity();

    void setId(int id);
    void setShippingDate(QString shippingDate);
    void setShippingPrice(QString shippingPrice);
    void setProductsQuantity(QString productsQuantity);

    std::list<Sale> loadFromFile();
    void saveToFile(std::list<Sale> clients);
    static void addFromFileToTable(Ui::MainWindow * window);
    static void addToSaleTable(Ui::MainWindow *window, Sale sale);
    static Sale findSaleById(int id);

    static std::list<Sale> sales;

signals:


public slots:

private:
    int id;
    QString shippingDate;
    QString shippingPrice;
    QString productsQuantity;


};

#endif // SALE_H
