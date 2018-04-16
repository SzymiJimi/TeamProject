#ifndef SALE_H
#define SALE_H

#include <QObject>

class Sale
{

public:
    Sale();
    int getId();
    QString getName();
    QString getQuantity();
    QString getUnit();
    QString getPrice();

    void setId(int id);
    void setName(QString name);
    void setQuantity(QString quantity);
    void setUnit(QString unit);
    void setPrice(QString price);

    std::list<Sale> loadFromFile();
    void saveToFile(std::list<Sale> clients);

signals:


public slots:

private:
    int id;
    QString name;
    QString quantity;
    QString unit;
    QString price;


};

#endif // SALE_H
