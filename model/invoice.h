#ifndef INVOICE_H
#define INVOICE_H

#include <QObject>
#include <list>

class Invoice
{

public:
    Invoice();
    int getId();
    int getPurchaseNr();
    QString getPurchaseDate();
    QString getPurchaseValue();
    int getProductsAmount();

    void setId(int id);
    void setPurchaseNr(int purchaseNr);
    void setPurchaseDate(QString purchaseDate);
    void setPurchaseValue(QString purchaseValue);
    void setProductsAmount(int productsAmount);

    std::list<Invoice> loadFromFile();
    void saveToFile(std::list<Invoice> invoices);

signals:

public slots:

private:
    int id;
    int purchaseNr;
    QString purchaseDate;
    QString purchaseValue;
    int productsAmount;

};

#endif // INVOICE_H
