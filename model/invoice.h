#ifndef INVOICE_H
#define INVOICE_H

#include <QObject>

class Invoice : public QObject
{
    Q_OBJECT
public:
    explicit Invoice(QObject *parent = nullptr);
    int getPurchaseNr();
    QString getPurchaseDate();
    QString getPurchaseValue();
    int getProductsAmount();

    void setPurchaseNr(int purchaseNr);
    void setPurchaseDate(QString purchaseDate);
    void setPurchaseValue(QString purchaseValue);
    void setProductsAmount(int productsAmount);

signals:

public slots:

private:
    int purchaseNr;
    QString purchaseDate;
    QString purchaseValue;
    int productsAmount;

};

#endif // INVOICE_H
