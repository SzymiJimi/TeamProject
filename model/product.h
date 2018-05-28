#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>
#include <list>
#include <mainwindow.h>

class Product
{

private:
    int id;
    QString name;
    QString brand;
    float quantity;
    QString unit;
    float price;
    QString VAT;
    QString expirationDate;
    QString addDate;
    float nettoPrice;

public:
    Product();
    int getId();
    QString getName();
    QString getBrand();
    float getQuantity();
    QString getUnit();
    float getPrice();
    QString getVAT();
    QString getExpirationDate();
    QString getAddDate();
    float getNettoPrice();

    void setId(int id);
    void setName(QString name);
    void setBrand(QString brand);
    void setQuantity(float quantity);
    void setUnit(QString unit);
    void setPrice(float price);
    void setVAT(QString VAT);
    void setExpirationDate(QString expirationDate);
    void setAddDate(QString addDate);
    void setNettoPrice(float nettoPrice);

    std::list<Product> loadFromFile();
    void saveToFile(std::list<Product> clients);
    static void addFromFileToTable(Ui::MainWindow * window);
    Product findProductById(int productId);
    static bool deleteProductById(int productId);
    bool operator <(const Product &other);
    static std::list<Product> findProductsByName(QString name);

    static std::list<Product> products;

signals:

public slots:


};

#endif // PRODUCT_H
