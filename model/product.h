#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>
#include <list>
#include <mainwindow.h>

class Product
{
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

    void setId(int id);
    void setName(QString name);
    void setBrand(QString brand);
    void setQuantity(float quantity);
    void setUnit(QString unit);
    void setPrice(float price);
    void setVAT(QString VAT);
    void setExpirationDate(QString expirationDate);
    void setAddDate(QString addDate);

    std::list<Product> loadFromFile();
    void saveToFile(std::list<Product> clients);
    static void addFromFileToTable(Ui::MainWindow * window);
    static std::list<Product> products;
signals:

public slots:

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
};

#endif // PRODUCT_H
