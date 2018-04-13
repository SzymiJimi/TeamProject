#ifndef PRODUCT_H
#define PRODUCT_H

#include <QObject>

class Product : public QObject
{
    Q_OBJECT
public:
    explicit Product(QObject *parent = nullptr);

    int getId();
    QString getName();
    QString getBrand();
    float getQuantity();
    float getPrice();
    QString getVAT();
    QString getExpirationDate();
    QString getAddDate();

    void setId(int id);
    void setName(QString name);
    void setBrand(QString brand);
    void setQuantity(float quantity);
    void setPrice(float price);
    void setVAT(QString VAT);
    void setExpirationDate(QString expirationDate);
    void setAddDate(QString addDate);

signals:

public slots:

private:
    int id;
    QString name;
    QString brand;
    float quantity;
    float price;
    QString VAT;
    QString expirationDate;
    QString addDate;
};

#endif // PRODUCT_H
